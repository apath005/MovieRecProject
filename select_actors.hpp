#ifndef __SELECT_ACTORS_HPP__

#define __SELECT_ACTORS_HPP__

#include "select_column.hpp"



class Select_Actors: public Select_Column
{
public:
    std::string actorName;
    Select_Actors(const Movie* movie, const std::string& movieName, const std::string actorName)
    {
        this->movieName = movieName;
	this->actorName = actorName;
    }

    virtual bool select(const Movie* movie) const
    {
        return movie->movie_data(row, column).find(actorName) != std::string::npos;
    {

    virtual bool select(const std::string& s) const 
    {
        return movieName;

    }
};

#endif //SELECT_ACTORS_H__
