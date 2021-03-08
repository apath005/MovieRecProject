#ifndef __SELECT_YEAR_HPP__

#define __SELECT_YEAR_HPP__

#include "select_column.hpp"



class Select_Year: public Select_Column
{
public:
    std::string movieYear;
    std::string movieName;

    Select_Year(const Spreadsheet* movie, const std::string& movieName, const std::string movieYear, const std::string& columnName): Select_Column(movie, columnName)
    {
        this->movieName = movieName;
        this->movieYear = movieYear;
    }

    virtual bool select(const Spreadsheet* movie) const {
        return movie->cell_data(row, column).find(movieYear) != std::string::npos;
    }

    virtual bool select(const std::string& s) const {
        return false;

    }
}

#endif // SELECT_YEAR_H
