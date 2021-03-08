
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Movie.hpp"
#include "MovieSelector.hpp"
#include <utility>
#include <vector>
#include <iostream>
#include "spreadsheet.hpp"
#include <sstream>
#include <iomanip>
#include <fstream>
#include "select_genre.hpp"
#include <algorithm>
#include "select_genre.hpp"
#include "select_directors.hpp"
#include "select_year.hpp"
#include "select_actors.hpp"
#include "select_and.hpp"
class Interface {
    std::vector <Movie*> genres;
    Spreadsheet* sheet = new Spreadsheet;

public:
    Interface(Spreadsheet* sheet) {
        this->sheet = sheet;
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
    }
    ~Interface() {}

    //TODO: Accepts User input and then gets movie recommendations
    /*
     * This will be the main function to accept user input and from there it return print the appropriate movie recommendation
     */
    void userInterface() {

        //Create a category works
        createGenre("Romance");
        createGenre("Comedy");
        createGenre("Fiction");
        createGenre("Sci-Fi");
        printAllCategories();
        //Delete a category
        std::cout << "--Removing categories--" << std::endl;
        removeGenre("Fiction");
        removeGenre("Sci-Fi");
        printAllCategories();
        //Create a sub category
        std::cout << "--Creating subCategories--" << std::endl;
        createGenre("Romance,Sci-Fi");
        createGenre("Comedy,Fiction");
        printAllCategories();
        std::cout << "--Non existent categories--" << std::endl;
        createGenre("Sci-Fi, Cordial");
        printAllCategories();
        //Remove a sub category
        std::cout << "--Removing sub categories--" << std::endl;
        removeGenre("Romance,Sci-Fi");
        removeGenre("Romance,Sci-Fi"); // should print this genre doesn't exist
        printAllCategories();
        //Create a movie and add it to a category
        std::cout << "--Adding Movies--" << std::endl;
        addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar, Goat", "39.5");
        addMovie("Movie2", "2018", "Comedy,Fiction", "Abdi", "Jogar, Goat", "39.5");
        addMovie("Movie3", "2018", "Comedy,Sci-Fi", "Abdi", "Jogar, Goat", "39.5");
        printAllMovies();
        //Remove a movie from a category
        std::cout << "--Removing Movies--" << std::endl;
        removeMovie("Movie1", "Romance");
        removeMovie("Movie2", "Comedy,Fiction");
        printAllMovies();

        //Remove movies based on categories:
        std::cout << "--Adding Faux Movies--" << std::endl;
        addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar, Goat", "39.5");
        addMovie("Movie2", "2018", "Comedy,Fiction", "Abdi", "Goat", "39.5");
        addMovie("Movie3", "2019", "Romance", "Abdi", "Jogar, Goat", "39.5");
        addMovie("Movie4", "2017", "Comedy,Fiction", "Jogar", "Jogar", "39.5");
        addMovie("Movie5", "2016", "Comedy,Sci-Fi", "Jogar", "Jogar", "39.5");
        addMovie("Movie6", "2015", "Comedy,Sci-Fi", "Jogar", "Jogar", "39.5");
        printAllMovies("Comedy,Sci-Fi");
        std::cout << "--Deleting Category Movies--" << std::endl;
        removeGenre("Comedy,Sci-Fi");
        printAllMovies("Comedy,Sci-Fi");
        //Return a recommendations based on either
            //Director
            std::cout << "--Checking Recommendation Function--\n";
            sheet->set_selection(new Select_Directors(sheet, "Abdi", "Director"));
            sheet->print_selection(std::cout);
            //Actor
            std::cout << "--Checking Recommendation Function for Actors--\n";
            sheet->set_selection(new Select_Actors(sheet, "Goat", "Actors"));
            sheet->print_selection(std::cout);
            //Genre
            std::cout << "--Checking Recommendation Function For Genre--\n";
            printSimilarGenres();
            //Year
            std::cout << "--Checking Recommendation Function for Year--\n";
            sheet->set_selection(new Select_Year(sheet, "2018", "Year"));
            sheet->print_selection(std::cout);
            //AND
            std::cout << "--Checking Recommendation Function for AND--\n";
            sheet->set_selection(new Select_And(new Select_Year(sheet, "2018", "Year"), new Select_Actors(sheet, "Goat", "Actors")));
            sheet->print_selection(std::cout);

    }

    void printAllMovies(){
        for(Movie* m : genres) {
            std::cout << m->getMovie();
        }
    }
    void printAllMovies(std::string Genre){
        std::string delimiter = ",";
        if(Genre.find(delimiter) != std::string::npos) {
            std::cout << getGenre(Genre)->getMovie();
        }
        else {
            for (Movie *m : genres) {
                if (m->getGenreName() == Genre) std::cout << m->getMovie();
            }
        }
    }

    void printSimilarGenres() {
        std::string genre = "Comedy,Fiction";
        MovieSelector* gen = new Select_Genre(genre);

        std::string delimiter = ",";
        if (genre.find(delimiter) != std::string::npos) {
            std::stringstream test(genre);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(test, token, ',')) {
                tokens.push_back(token);
            }
            std::cout << "\nSimilar movies in this genre include: " << std::endl;
            std::cout << getSubGenre(getGenre(tokens.at(0)), tokens.at(1))->getMovie();

        } else {
            for (Movie *m: genres) {
                if(gen->select(m->getGenreName())){
                    std::cout << "\nSimilar movies in this genre include: " << std::endl;
                    std::cout << m->getMovie();
                }
            }
        }
    }

    void printCategories(std::string genre) {
        std::string delimiter = ",";
        if(genre.find(delimiter) != std::string::npos) {
            std::cout << "This a subcategory named: " + getGenre(genre)->getGenreName();
        }
        else {
            std::cout << "There are subcategories named: " + getGenre(genre)->printSubGenres();
        }

    }
    void printAllCategories(){
       for(Movie* m :genres){
           if(m->subGenreExists()){
               std::cout << "This genre is: " << m->getGenreName() << std::endl;
               std::cout << "The genre: " << m->getGenreName() << " has subgenres: "
               << m->printSubGenres() << std::endl;
           }
           else {
               std::cout << "This genre is: " << m->getGenreName() << std::endl;
           }
       }

    }
    //TODO: This function is called when user wants to add a movie
    //TODO: This checks to see if the genre exists and adds the movie
    void addMovie(std::string Title, std::string Year, std::string Genre, std::string Director, std::string Actors, std::string Metascore) {
        //Edit this and require them to CIN
        Movie* tmp = new setMovie({Title, Year, Genre, Director, Actors, Metascore});
        sheet->add_row({Title, Year, Genre, Director, Actors, Metascore});
        getGenre(Genre)->addMovie(tmp);
    }
    //TODO: This function removes a movie
    //TODO: In order to remove a movie
    void removeMovie(std::string Title, std::string genre){
        getGenre(std::move(genre))->remove(Title);
        sheet->remove_row(Title);
    }
    void removeSubGenre(Movie*m, std::string genre){
        if(m->subGenre(genre) != nullptr) {
            m->subGenre(genre)->removeAllChildren();
            m->removeSubGenre(genre);
        }
    }
    //TODO: This function is called when the user wants to remove a genre:
    bool removeGenre(std::string genre) {
        if(!genreExists(genre)) {
            std::cout << "This genre does not exist!\n";
            return false;
        }
        std::string delimiter = ",";
        if(genre.find(delimiter) != std::string::npos){
            std::stringstream test(genre);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(test, token, ',')){
                tokens.push_back(token);
            }
            removeSubGenre(getGenre(tokens.at(0)), tokens.at(1));
        }
        else {
            for (int i = 0; i < genres.size(); i++) {
                if (genres.at(i)->getGenreName().find(genre) != std::string::npos) {
                    delete genres.at(i);
                    genres.erase(genres.begin() + i);
                    return true;
                }
            }
        }
        return false;
    }
    //Genre exists function:
    bool genreExists(std::string genre){
        if(genres.empty()){
            return false;
        }

        std::string delimiter = ",";
        if(genre.find(delimiter) != std::string::npos) {
            std::stringstream test(genre);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(test, token, ',')){
                tokens.push_back(token);
            }

            if (genreExists(tokens.at(0))){
                return subGenreExists(getGenre(tokens.at(0)), tokens.at(1));
            }
            else if (!genreExists(tokens.at(0))){
                return false;
            }
            else {
                std::cout << "Uh oh an error has occurred while checking to see if genreExists!\n";
                return false;
            }

        } else{
                for(Movie* m : genres){
                    if(m->getGenreName().find(genre) != std::string::npos){
                        return true;
                    }
                }
            }
        return false;
    }
    Movie* getSubGenre(Movie* m, std::string subGenre){
        if(m->subGenre(subGenre) != nullptr) return m->subGenre(subGenre);
        return nullptr;
    }
    void createSubGenre(Movie*m, std::string subGenre){
        if(m->isComposite()) m->addMovie(new MovieGenres(std::move(subGenre)));

    }

    bool subGenreExists(Movie* m, std::string subGenre){
        return m->subGenre(std::move(subGenre)) != nullptr;
    }

    Movie* getGenre(const std::string genre) {
        if(!genreExists(genre)){
            std::cout << "\nThat genre doesn't exist. Creating it now.\n";
            createGenre(genre);
            return getGenre(genre);
        }
        std::string delimiter = ",";
        if(genre.find(delimiter) != std::string::npos) {
            std::stringstream test(genre);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(test, token, ',')){
                tokens.push_back(token);
            }
            if (genreExists(tokens.at(0))){
                 return getSubGenre(getGenre(tokens.at(0)), tokens.at(1));

            }

        } else {
            for(Movie* m : genres) {
                if (m->getGenreName().find(genre) != std::string::npos) {
                    return m;
                }
            }
        }
        return nullptr;
    }
    //TODO: This function is called when the user wants to add a genre

    void createGenre(std::string genre) {
            std::string delimiter = ",";
            if(genre.find(delimiter) != std::string::npos) {
                std::stringstream test(genre);
                std::string token;
                std::vector<std::string> tokens;
                while (std::getline(test, token, ',')){
                    tokens.push_back(token);
                }

                if (!genreExists(tokens.at(0))){
                    Movie* mov = new MovieGenres(tokens.at(0));
                    genres.push_back(mov);
                    createSubGenre(mov, tokens.at(1));
                }
                else if (genreExists(tokens.at(0))){
                    Movie* mov_ = new MovieGenres(tokens.at(1));
                    getGenre(tokens.at(0))->addMovie(mov_);
                }
                else{
                    std::cout << "Error creating Genre\n";
                }

            } else {
                    Movie* mov = new MovieGenres(genre);
                    genres.push_back(mov);
                }
        }



    /*
     * This will scrape and store our information into the spreadsheet class for easier querying via vectors
     */
    //TODO: WIP
    /*
    void scrapeCSVFiles() {
        //imdb_title_id,title,original_title,year,date_published,genre,duration,country,language,director,writer,production_company,actors,description,avg_vote,votes,budget,usa_gross_income,worlwide_gross_income,metascore,reviews_from_users,reviews_from_critics
        sheet->set_column_names({"Title", "year", "genre", "country", "director", "actors", "metascore"});

        std::ifstream ip("/Users/ambient/ClassroomProjects/final-project-jgarc594-apath005-aabdi005/IMDb_movies-2.csv");
        if (!ip.is_open()) std::cout << "ERROR HERE";
        std::string worthlessInfo;
        std::string Title;
        std::string year;
        std::string genre;
        std::string country;
        std::string director;
        std::string actors;
        std::string metascore;
        std::string currentRow;
        //imdb_title_id,title,original_title,year,date_published,genre,duration,country,language,director,writer,production_company,actors,description,avg_vote,votes,budget,usa_gross_income,worlwide_gross_income,metascore,reviews_from_users,reviews_from_critics
        char comma;
        while (ip.good()) {
            std::getline(ip, currentRow);
            std::istringstream iss(currentRow);

            while (iss >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(Title) >> comma
                       >> std::quoted(year) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(genre) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(country) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(director) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(actors) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(metascore) >> comma
                       >> std::quoted(worthlessInfo) >> comma
                       >> std::quoted(worthlessInfo) >> std::ws) {
                if (country.find("USA") != std::string::npos) {

                    sheet->add_row({Title, year, genre, country, director, actors, metascore});
                    //sheet->add_row({Title, year, genre, country, director, actors, metascore});
                    /*
                     * Check to see if string needs to be split up
                     * If it doesn't check to see if that genre exists in genre, if it does, create a new Movie and add it that genre
                     */
            /*
                    std::string delimiter = ",";
                    if (genre.find(delimiter) != std::string::npos) {
                        /*
                         * This checks breaks up the genres into Sub Categories
                         * If the First Genre doesn't exist, we create a new sub Genre under the first One
                         */
            /*
                        size_t pos = 0;
                        std::string token;
                        Movie *currentGenre = nullptr;
                        std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
                        token.erase(end_pos, token.end());
                        while ((pos = genre.find(delimiter)) != std::string::npos) { //loops until all sub genres are added
                            token = genre.substr(0, pos);
                            bool exists = false;
                            /*
                             * Check to see if first genre token exists:
                             */
                            /**
                             * This case checks to see if the vector of genres is empty and creates the genres and sets the current genre
                             *
                             * */
                             /*
                            if (genres.empty()) {
                                genres.push_back(new MovieGenres(token));
                                currentGenre = genres.at(0);
                                /**
                                 * This keeps updating currentGenre until the loop is finished
                                 */
                             /*
                            } else {
                                for (Movie *m : genres) {
                                    if (m->isComposite() && m->getGenreName().find(token) != std::string::npos) {
                                        currentGenre = m;
                                        exists = true;
                                        break;
                                    }
                                }
                                /*
                                 * This checks to see if the genre wasn't found in the previous for loop
                                 */
                                /*
                                if (!exists) {
                                    Movie *tmp = new MovieGenres(token);
                                    genres.push_back(tmp);
                                    currentGenre = tmp;
                                }
                                /*
                                /*
                                 * Final iteration checks for all
                                 */
                           // }
                            /*
                             * else {
                                for (Movie *m : genres) {
                                    if (m->isComposite() && m->getGenreName().find(token) != std::string::npos) {
                                        Movie *tmp = new MovieGenres(token);
                                        m->addMovie(tmp);
                                        currentGenre = tmp;
                                    }

                                */
                            /*
                            genre.erase(0, pos + delimiter.length());
                        }

                        if (currentGenre != nullptr) currentGenre->addMovie(new setMovie(Title));

                    }
                    else {
                        addToGenres(genre, Title);
                    }


                }

            }
        }
    }
    */


};

#endif // INTERFACE_H
