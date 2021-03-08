#include "spreadsheet.hpp"
#include "MovieSelector.hpp"

#include <algorithm>
#include <iostream>

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(MovieSelector* new_select)
{
    delete select;
    select = new_select;
}

void Spreadsheet::clear()
{


    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}
void Spreadsheet::remove_row(std::string title){
    for(int i = 0; i< data.size(); i++){
        if(this->cell_data(i, 0).find(title) != std::string::npos){
            data.erase(data.begin() + i);
        }
    }
}
void Spreadsheet::print_selection(std::ostream &out) const {
    for (int i = 0; i < data.size(); i++) {
        out << this->cell_data(i, 0) << " " << this->cell_data(i, 1)
            << " " << this->cell_data(i, 2) << " " << this->cell_data(i, 3) << "\n";
    }
}

