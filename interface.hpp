
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
class Interface {
    std::vector <Movie*> genres;
    Spreadsheet* sheet = new Spreadsheet;
public:
    Interface(Spreadsheet* sheet) {
        this->sheet = sheet;
        sheet->set_column_names({"Title", "year", "genre", "director", "actors", "metascore"});
    }
    ~Interface() {}

    //TODO: Accepts User input and then gets movie recommendations
    /*
     * This will be the main function to accept user input and from there it return print the appropriate movie recommendation
     */
    void userInterface() {
        //Create a category
        //Create a sub category
        //Create a movie and add it a category
        //Remove a category
        //Remove a sub category
        //Remove a movie from a category
        //Return a recommendations based on either
            //Director
            //Actor
            //Genre
            //Year
            //AND
            
    }

    //TODO: This function is called when user wants to add a movie
    //TODO: This checks to see if the genre exists and adds the movie
    void addMovie(std::string Title, std::string Year, std::string Genre, std::string Director, std::string Actors, std::string Metascore) {
        //Edit this and require them to CIN
        Movie* tmp = new setMovie({Title, Year, Genre, Director, Actors, Metascore});
        getGenre(Genre)->addMovie(tmp);
    }
    //TODO: This function removes a movie
    //TODO: In order to remove a movie, it must be removed from the spreadsheet, and from its genre
    //TODO: Loop through the genre until you find its parent, delete the pointer to its setMovie class
    void removeMovie(std::string Title){
        //Find its genre
        //Remove it from children

    }

    //TODO: This function is called when the user wants to remove a genre:
    bool removeGenre(std::string genre) {
        if(!genreExists(genre)) {
            std::cout << "This genre does not exist!";
            return false;
        }

        for(int i =0; i<genres.size(); i++){
            if (genres.at(i)->getGenreName().find(genre) != std::string::npos) {
                delete genres.at(i);
                genres.erase(genres.begin() + i);
                return true;
            }
        }
        return false;
    }
    //Genre exists function:

    bool genreExists(std::string genre){
        if(!genres.empty()){
            return false;
        }
        for(Movie* m : genres){
            if (m->getGenreName().find(genre) != std::string::npos) {
                return true;
            }
        }
        return false;

    }

    Movie* getGenre(std::string genreName) {
        if(!genreExists(genreName)){
            std::cout << "\nThat genre doesn't exist. Creating it now";
            Movie* mov = new MovieGenres(genreName);
            genres.push_back(mov);
            return mov;
        }

        for(Movie* m : genres) {
            if (m->getGenreName().find(genreName) != std::string::npos) {
                return m;
            }
        }
        return nullptr;
    }

    void printMovies(){

    }
    //TODO: This function is called when the user wants to add a genre
    void addToGenres(std::string genre) {
        if(genreExists(genre)){
            std::cout << "This genre already exists";
        }
        else{
            //It adds it correctly
            Movie* gre = new MovieGenres(genre);
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
