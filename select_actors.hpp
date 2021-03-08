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
    Spreadsheet* sheet;
    Select_Actors(Spreadsheet* movie, const std::string actorName, const std::string& columnName) : Select_Column(movie, columnName)
    {
	    this->actorName = actorName;
	    this->sheet = movie;
    }

    virtual bool select(Spreadsheet* sheet, int row) const {
        return sheet->cell_data(row, column).find(actorName) != std::string::npos;
    }

    virtual bool select(const std::string &s) const {

        return true;

    }
    ~Select_Actors() {
        delete this;
    }
};

#endif //SELECT_ACTORS_H__
