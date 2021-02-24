#ifndef __SELECT_COLUMN_HPP__
#define __SELECT_COLUMN_HPP__

#include "MovieRecommender.hpp"


class Select_Column: public MovieRecommender
{
protected:
    int column;
    int row;
public:
    Select_Column(const Movie* dataset, const std::string& movieName)
    {
        column = dataset->get_column_by_movieName(movieName);
    }

    virtual bool select(const Movie* dataset) const
    {
        return select(dataset->movie_data(row, column));
    }

    // Derived classes implement this interface to select from movie datasets
    virtual bool select(const std::string& s) const = 0;
    };
