#ifndef MOVIEGENRES_HPP
#define MOVIEGENRES_HPP

#include <utility>
#include <vector>
#include "Movie.hpp"
class MovieGenres : public Movie {

public:
    std::string genreName;
    std::vector<Movie*> children;

    ~MovieGenres() {
        for(Movie* m: children){
            if(m->isComposite()) m->removeAllChildren();
            m->removeAllChildren();
            delete m;
        }
    }
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
        for(Movie* m : children){
            if(m->isComposite()) {
                if(m->getChild(movieName)->getMovieName() == movieName) {
                    return m->getChild(movieName);
                }
            }
            else {
                if(m->getMovieName() == movieName) {
                    return m;
                }
            }
        }
        return nullptr;
    }
    std::string getMovieName() override{
        return "0";
    }
    bool remove(std::string movieName) override {
        bool removed = false;
        for (int i = 0; i<children.size(); i++){
            if(children.at(i)->isComposite()) removed = children.at(i)->remove(movieName);
            if (!children.at(i)->isComposite() && children.at(i)->getMovieName() == movieName) {
                children.at(i)->setParent(nullptr);
                delete children.at(i);
                children.erase(children.begin() + i);
                removed = true;
            }
        }
        return removed;
    }

    void removeAllChildren() override {
        for (int i = 0; i < children.size(); i++) {
            children.at(i)->setParent(nullptr);
            delete children.at(i);
            children.erase(children.begin() + i);
        }
    }

    void removeSubGenre(std::string genreName) override {
        for (int i = 0; i<children.size(); i++){
            if (children.at(i)->isComposite() && children.at(i)->getGenreName() == genreName ) {
                children.at(i)->removeAllChildren();
                children.at(i)->setParent(nullptr);
                delete children.at(i);
                children.erase(children.begin() + i);
            }
        }

    }

    virtual bool isComposite() {
        return true;
    }

    virtual std::string printSubGenres() {
        std::string result;

        for(Movie* m : children){
            if (m->isComposite()){
                result+= "\n" + m->getGenreName();

            }
        }
        return result;
    }

    virtual std::string getMovie() {
        std::string movies;

        for (Movie* m : children) {
            movies += m->getMovie() + "\n";
        }

        return movies;
    }
    virtual Movie* getChildB() {
        for(Movie* m : children){
            return m;
        }
        return nullptr;
    }
    virtual std::string getDirector() {
        return "0";
    }

    virtual std::string getMovieYear() {
        return "0";
    }





};


#endif //MOVIEGENRES_HPP
