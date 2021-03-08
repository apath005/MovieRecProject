#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "MovieSelector.hpp"

#include "spreadsheet.hpp"

class Select_And : public MovieSelector {
protected:
	MovieSelector* selectActor;
	MovieSelector* selectDirector;
	MovieSelector* selectYear;
public:
	Select_And(MovieSelector* actor, MovieSelector* director, MovieSelector* year) {
	this->selectActor = actor;
	this->selectDirector = director;
	this->selectYear = year;
	}

	~Select_And() { 
	delete selectActor; 
	delete selectDirector;
	delete selectYear;
	}

	virtual bool select(const Movie* movie) const {
        if (selectActor->select(sheet, row) == true && selectDirector->select(sheet, row) == true) {
            return true;
        }
	if (selectActor->select(sheet, row) == true && selectYear->select(sheet, row) == true) {
            return true;
        }
	if (selectDirector->select(sheet, row) == true && selectYear->select(sheet, row) == true) {
            return true;
        }
        else {
            return false;
        }
    }
};

#endif
