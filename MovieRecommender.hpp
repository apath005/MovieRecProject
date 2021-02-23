/*
 * Strategy Interface
 */

#ifndef MOVIERECOMMENDER_HPP
#define MOVIERECOMMENDER_HPP


class MovieRecommender {


public:
    virtual ~Select() = default;


    // TODO: Requires a parameter! Store movie from Movie
    virtual bool select(const Movie) const = 0;


    virtual bool select() const = 0;
};

#endif //MOVIERECOMMENDER_H
