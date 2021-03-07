#ifndef __SELECT_COLUMN_HPP__
#define __SELECT_COLUMN_HPP__

#include "MovieSelector.hpp"
#include "spreadsheet.hpp"

class Select_Column: public MovieSelector
{
protected:
    int column;
    int row;
public:
    Select_Column(const Spreadsheet* dataset, const std::string& movieName)
    {
        column = dataset->get_column_by_name(movieName);
    }

    virtual bool select(const Spreadsheet* dataset) const
    {
        return select(dataset->cell_data(row, column));
    }

    // Derived classes implement this interface to select from movie datasets
    virtual bool select(const std::string& s) const = 0;
    };
