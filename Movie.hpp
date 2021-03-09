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

    virtual bool remove(std::string Movie){}

    virtual Movie* getChild(std::string movieName) = 0 ;

    virtual std::string getMovie() = 0;
    virtual std::string getMovieName() = 0;
    virtual void removeAllChildren() = 0;
    virtual bool isComposite() = 0;
    virtual void removeSubGenre(std::string genreName) = 0;
    virtual std::string getGenreName() = 0;
    virtual Movie* subGenre(std::string genreName) = 0;
    virtual bool subGenreExists() = 0;
    virtual std::string printSubGenres() = 0;
    virtual std::string getDirector() = 0;
    virtual Movie* getChildB() = 0;
    virtual std::string getMovieYear() = 0;
};
#endif
