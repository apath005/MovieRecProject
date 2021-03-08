#ifndef __SELECT_DIRECTORS_HPP__

#define __SELECT_DIRECTORS_HPP__

#include <utility>

#include "select_column.hpp"



class Select_Directors: public Select_Column
{
    std::string directorName;
    Spreadsheet* sheet;
public:

    Select_Directors(Spreadsheet* sheet, std::string directorName, const std::string& columnName) : Select_Column(sheet, columnName)
    {
        this->directorName = std::move(directorName);
        this->sheet = sheet;
    }

    virtual bool select(const Spreadsheet* sheet, int row) const {
        return sheet->cell_data(row, column).find(directorName)!= std::string::npos;
    }

    virtual bool select(const std::string& s) const {

    }


};

#endif// __SELECT_DIRECTORS_H__
