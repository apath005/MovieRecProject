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

    virtual bool select(const Spreadsheet* sheet, int row) const{
        return sheet->cell_data(row, column).find(actorName) != std::string::npos;
    }

    bool select(const std::string &s) const override {

        return true;

    }
    ~Select_Actors() {

    }
};

#endif //SELECT_ACTORS_H__
