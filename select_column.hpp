#ifndef __SELECT_COLUMN_HPP__
#define __SELECT_COLUMN_HPP__

#include "MovieSelector.hpp"
#include "spreadsheet.hpp"

class Select_Column: public MovieSelector
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* dataset, const std::string& movieColumn)
    {
        column = dataset->get_column_by_name(movieColumn);
        int r = column;
    }

    virtual bool select(const Spreadsheet* dataset, int row) const
    {
        return select(dataset->cell_data(row, column));
    }

    // Derived classes implement this interface to select from movie dataset
    virtual bool select(const std::string& s) const = 0;

};

#endif