
#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "MovieSelector.hpp"

#include "spreadsheet.hpp"

class Select_And : public MovieSelector {
protected:
    MovieSelector* select1;
    MovieSelector* select2;
public:
    Select_And(MovieSelector* select, MovieSelector* select_)
    {
        select1 = select;
        select2 = select_;
    }
    virtual bool select(const Spreadsheet* sheet, int row) const {
        return false;
    }

    virtual bool select(const std::string& s) const {
        return select2->select(s) && select1->select(s);
    }
    ~Select_And() {
        delete this;
    }
};

#endif