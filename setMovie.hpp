
#ifndef SETMOVIE_HPP
#define SETMOVIE_HPP
#include "Movie.hpp"

#include <utility>

class setMovie : public Movie {

    std::vector<std::string> movieInfo;
public:
     setMovie(std::vector<std::string> movieInfo){
         this->movieInfo = std::move(movieInfo);
     }
    void addMovie(Movie *mov) override {

     };

    void remove(std::string Movie) override {

    };

    Movie* getChild(std::string movieName) override {
        return nullptr;
    };

    bool isComposite() override{
         return false;
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


    std::string getGenreName() override {
        return "0";
    }

     bool subGenreExists() override {
        return false;
    }

    Movie* subGenre(std::string genreName) override {
        return nullptr;
    };


};
#endif //SETMOVIE_HPP
