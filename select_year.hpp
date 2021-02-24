#ifndef __SELECT_YEAR_HPP__

#define __SELECT_YEAR_HPP__

#include "select_column.hpp"



class Select_Year: public Select_Column
{
public:
    std::string movieYear;
    Select_Actors(const Movie* movie, const std::string& movieName, const std::string movieYear)
    {
        this->movieName = movieName;
        this->movieYear = movieYear;
    }

    virtual bool select(const Movie* movie) const
    {
        return movie->movie_data(row, column).find(movieYear) != std::string::npos;
    {

    virtual bool select(const std::string& s) const
    {
        return movieName;

    }
}

#endif // SELECT_YEAR_H
