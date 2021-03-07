/*
 * Strategy Interface
 */

#ifndef MOVIERECOMMENDER_HPP
#define MOVIERECOMMENDER_HPP

#include "Movie.hpp"
class MovieSelector {


public:
    virtual ~MovieSelector() = default;


    // TODO: Requires a parameter! Store movie from Movie
    virtual bool select(const Movie* m) const = 0;


    virtual bool select() const = 0;
};

#endif //MOVIERECOMMENDER_H
