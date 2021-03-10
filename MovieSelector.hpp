/*
 * Strategy Interface
 */

#ifndef MOVIESELECTOR_HPP
#define MOVIESELECTOR_HPP

#include "Movie.hpp"
#include "spreadsheet.hpp"
class MovieSelector {


public:
    virtual ~MovieSelector() = default;


    // TODO: Requires a parameter! Store movie from Movie

    virtual bool select(const Spreadsheet* sheet, int row) const = 0;

    virtual bool select(const std::string& s) const = 0;
};

#endif //MOVIESELECTOR_H
