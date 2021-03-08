#include <iostream>

#include "Movie.hpp"
#include "MovieSelector.hpp"
#include "MovieGenres.hpp"
#include "setMovie.hpp"
#include "interface.hpp"
int main() {
    /*
     *Test function requires more testing and needs to be moved to its own class
     */
    auto* sheet = new Spreadsheet();
    auto* Interface_ = new Interface(sheet);

    Interface_->userInterface();
    delete Interface_;
    sheet->clear();
    delete sheet;
    return 0;
};