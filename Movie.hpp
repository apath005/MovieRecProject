/*
 * Composite Class
 */
#ifndef MOVIE_H
#define MOVIE_H



// TODO: This class will store our genres and subgenres in the subclass Genre and selectGenre will pick from there
class Movie {

public:
    Movie() {

    }


    virtual ~Movie() {}

    virtual void addMovie(Movie mov) = 0;

    virtual void remove(Movie mov) = 0;

    virtual void getChild() = 0;

    virtual void setMovie() = 0;


};
#endif
