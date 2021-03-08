#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "MovieRecommender.hpp"

#include "spreadsheet.hpp"

class Select_And : public MovieRecommender {
protected:
	MovieRecommender* selectActor;
	MovieRecommender* selectDirector;
	MovieRecommender* selectYear;
public:
	Select_And(MovieRecommender* actor, MovieRecommender* director, MovieRecommender* year) {
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
