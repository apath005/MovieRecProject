#ifndef __SELECT_DIRECTORS_HPP__

#define __SELECT_DIRECTORS_HPP__

#include "select_column.hpp"



class Select_Directors: public Select_Column
{
public:
    std::string directorName;
    Select_Directors(const Movie* movie, const std::string& movieName, const std::string directorName)
    {
        this->movieName = movieName;
        this->directorName = directorName;
    }

    virtual bool select(const Movie* movie) const
    {
        return movie->movie_data(row, column).find(directorName) != std::string::npos;
    {

    virtual bool select(const std::string& s) const
    {
        return movieName;

    }
}

#endif// __SELECT_DIRECTORS_H__
