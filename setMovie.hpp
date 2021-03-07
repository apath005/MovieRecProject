
#ifndef SETMOVIE_HPP
#define SETMOVIE_HPP
#include "Movie.hpp"

class setMovie : public Movie {

    std::string movieTitle;
public:
     setMovie(std::string movieName){
         this->movieTitle = movieName;
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
        return movieTitle;
    }


};
#endif //SETMOVIE_HPP
