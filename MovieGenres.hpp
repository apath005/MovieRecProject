#ifndef MOVIEGENRES_HPP
#define MOVIEGENRES_HPP

#include <utility>
#include <vector>
#include "Movie.hpp"
class MovieGenres : public Movie {
    std::vector<Movie*> children;
public:
    std::string genreName;

    MovieGenres(std::string genre) {
        this->genreName = std::move(genre);
    }
    std::string getGenreName(){
        return genreName;
    }
    void addMovie(Movie* movie) override {
        this->children.push_back(movie);
        movie->setParent(this);
    }

    Movie* subGenre(std::string genreName) override {
        for(Movie*m : children) {
            if(m->isComposite() && m->getGenreName().find(genreName) != std::string::npos){
                return m;
            }
        }
        return nullptr;
    }
    bool subGenreExists() override {
        //if there is a subGenre return true

        for(Movie* m: children){
            if (m->isComposite()) return true;
        }
        return false;
    }

    Movie* getChild(std::string movieName) override {
        for (Movie* m : children){
            if (m->getMovie() == movieName) {
                return m;
            }
        }
        return nullptr;
    }

    void remove(std::string movieName) override {
        for (int i = 0; i<children.size(); i++){
            if (children.at(i)->getMovie() == movieName) {
                children.at(i)->setParent(nullptr);
                delete children.at(i);
                children.erase(children.begin() + i);

            }
        }
    }

    virtual bool isComposite() {
        return true;
    }

    virtual std::string getMovie() {
        std::string movies;

        for (Movie* m : children) {
            if(m->isComposite()){
                movies+= "Sub Genre: " + m->getGenreName() + "\n";
            }
                movies += m->getMovie() + "\n";
        }

        return movies;
    }







};


#endif //MOVIEGENRES_HPP
