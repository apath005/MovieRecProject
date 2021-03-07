#ifndef __SELECT_ACTORS_HPP__

#define __SELECT_ACTORS_HPP__

#include "select_column.hpp"
#include "Movie.hpp"
#include <iostream>
#include "spreadsheet.hpp"
class Select_Actors: public Select_Column
{
public:
    std::string actorName;
    std::string movieName;
    Select_Actors(const Spreadsheet* movie, const std::string& movieName, const std::string actorName, const std::string& columnName) : Select_Column(movie, columnName)
    {
        this->movieName = movieName;
	    this->actorName = actorName;
    }

    virtual bool select(const Spreadsheet* movie) const {
        return movie->cell_data(row, column).find(actorName) != std::string::npos;
    }

    virtual bool select(const std::string &s) const {

        return true;

    }
};

#endif //SELECT_ACTORS_H__
