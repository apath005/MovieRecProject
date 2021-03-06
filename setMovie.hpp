
#ifndef SETMOVIE_HPP
#define SETMOVIE_HPP
#include "Movie.hpp"

class setMovie : public Movie {

    std::string movieTitle;
public:
     setMovie(std::string movieName){
         this->movieTitle = movieName;
     }
     std::string getMovie() override {
        return movieTitle;
    }


};
#endif //SETMOVIE_HPP
