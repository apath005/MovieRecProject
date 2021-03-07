#ifndef __SELECT_DIRECTORS_HPP__

#define __SELECT_DIRECTORS_HPP__

#include "select_column.hpp"



class Select_Directors: public Select_Column
{
public:
    std::string directorName;
    std::string movieName;
    Select_Directors(const Spreadsheet* movie, const std::string& movieName, const std::string directorName, const std::string& columnName) : Select_Column(movie, columnName)
    {
        this->movieName = movieName;
        this->directorName = directorName;
    }

    virtual bool select(const Spreadsheet* movie, int row) const {
        return movie->cell_data(row, column).find(directorName) != std::string::npos;
    }

    virtual bool select(const std::string& s) const
    {
        return false;

    }
}

#endif// __SELECT_DIRECTORS_H__
