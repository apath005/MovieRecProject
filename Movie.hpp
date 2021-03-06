/*
 * Composite Class
 */
#ifndef MOVIE_H
#define MOVIE_H



class Movie {

protected:
    Movie* parent;
public:


    void setParent(Movie *parent_) {
        this->parent = parent_;
    }

    Movie* getParent() const {
        return this->parent;
    }
    virtual ~Movie() {}

    virtual void addMovie(Movie *mov){}

    virtual void remove(std::string Movie){}

    virtual Movie* getChild(std::string movieName) {}

    virtual std::string getMovie() = 0;

};
#endif
