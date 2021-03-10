
#ifndef GENRE_HPP
#define GENRE_HPP
#include "MovieSelector.hpp"
#include <iostream>
#include <utility>
class Select_Genre : public MovieSelector {

public:
    std::string genreName;
    Select_Genre(std::string genreName) {
        this->genreName = std::move(genreName);
    }

    virtual bool select(const std::string& s) const {
        //Looks through the genre categories and returns the string with the genres

        //TODO: Loop through the array of genres and find ones that meet the same conditions as the movie passed
        return s.find(genreName) != std::string::npos;
    }

    virtual bool select(const Spreadsheet* sheet, int row) const {

    }
    ~Select_Genre() {
        delete this;
    }
};



#endif //SELECT_GENRE_HPP
