
#ifndef SETMOVIE_HPP
#define SETMOVIE_HPP
#include "Movie.hpp"

#include <utility>

class setMovie : public Movie {

    std::vector<std::string> movieInfo;
public:
    ~setMovie() {

    }
      setMovie(std::vector<std::string> movieInfo){
         this->movieInfo = std::move(movieInfo);
     }
    void addMovie(Movie *mov) override {

     };

    bool remove(std::string Movie) override {

    };

    Movie* getChild(std::string movieName) override {
        return nullptr;
    };

    bool isComposite() override{
         return false;
     }
    void removeAllChildren() {

    }
    void removeSubGenre(std::string genreName) {

    }
    std::string getMovie() override {
        std::string result =
                "Movie Title: " + movieInfo.at(0)
                + "\nYear: " + movieInfo.at(1)
                + "\nGenre: " + movieInfo.at(2)
                + "\nDirector: " + movieInfo.at(3)
                + "\nActors: " + movieInfo.at(4)
                + "\nMetascore: " + movieInfo.at(5) + "\n";
        return result;
    }
    virtual std::string getMovieName() {
        return movieInfo.at(0);
    }

    std::string getGenreName() override {
        return "0";
    }
    virtual std::string printSubGenres() {
        return "";
    }
     bool subGenreExists() override {
        return false;
    }

    Movie* subGenre(std::string genreName) override {
        return nullptr;
    };

    virtual std::string getDirector() {
        return movieInfo.at(3);
    }
    virtual std::string getMovieYear() {
        return movieInfo.at(1);
    }

    virtual Movie* getChildB() {
        return nullptr;
    }

};
#endif //SETMOVIE_HPP
