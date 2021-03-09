
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
    ~Interface() {
        for(Movie*m : genres) {
            m->removeAllChildren();
            delete m;
        }
        sheet->clear();

    }

    //TODO: Accepts User input and then gets movie recommendations
    /*
     * This will be the main function to accept user input and from there it return print the appropriate movie recommendation
     */
    void userInterface() {
        addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        addMovie("Movie2", "2018", "Comedy,Fiction", "Anant", "Jogar,Abdi", "96");
        addMovie("Movie3", "2017", "Comedy,Sci-Fi", "Jogar", "Anant,Abdi", "12");
        userMenu();
        /*
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
            */

    }

    void userAddMovie() {
        std::string input;
        std::string Title;
        std::string Year;
        std::string Genre;
        std::string Director;
        std::string Actors;
        std::string Goat;
        std::string Metascore;

        while(input != "-1"){
            std::cout << "You have chosen to create a movie. I will need a few details!\n";
            std::cout << "\nFirst enter the movie name: ";
            std::cin >> Title;
            std::cout << "\nEnter the year of the movie!";
            std::cin >> Year;
            std::cout << "\nEnter the Genre of the movie. If the movie has a subcategory, Enter the main genre first followed by the Sub Genre(Ex: Fiction,Comedy)";
            std::cin >> Genre;
            std::cout << "\nEnter the Director or Directors of the movie! Split the names using a comma";
            std::cin >> Director;
            std::cout << "\nEnter the name of the Actors! Split the names using a comma";
            std::cin >> Actors;
            std::cout << "\nFinally enter the Metascore";
            std::cin >> Metascore;

            addMovie(Title, Year, Genre, Director, Actors, Metascore);

            std::cout << "\nWill you be adding more movies?(Enter -1 for No, 1 for Yes)";
            std::cin >> input;

        }
    }

    void category() {

        std::string input = "0";
        std::string genre;
        while(input != "-1"){
            std::cout << "\nYou have chosen to create a category.";
            std::cout << "\nWill this be a category or subcategory?(1 for Category, 2 For SubCategory)";
            std::cin >> input;
            if (input == "1"){
                std::cout << "\nGreat lets create a Category!";
                std::cout << "\nWhat is the name of this genre?";
                std::cin >> genre;
                std::cout << "\n Genre name is: " << genre;
                std::cout << "\nCreating genre now!";
                createGenre(genre);
                std::cout << "\nWould you like to create another genre?(-1 for no, 1 for yes)";
                std::cin >> input;
            }
        }

    }

    void userRemoveMovie() {
        std::string input = "0";
        std::string movieName;
        while(input != "-1"){
            std::cout << "\nYou have chosen to remove a movie!.";
            std::cout << "\nIn order to delete a movie you need a Title(Enter 1 to continue! or -1 to quit)";
            std::cin >> input;
            if (input == "1"){
                std::cout << "\nGreat lets remove a Movie!";
                std::cout << "\nWhat is the name of this movie?";
                std::cin >> movieName;
                std::cout << "\n Movie name is: " << movieName;
                std::cout << "\nDeleting that movie if it exists!";
                removeMovie(movieName);
                std::cout << "\nWould you like to delete another Movie?(-1 for no, 1 for yes)";
                std::cin >> input;
            }
        }
    }
    Movie* getMovie(std::string movieName){
        for(Movie* m : genres){
            return m->getChild(movieName);
        }
        return nullptr;
    }

    void printSimilar(std::string type, std::string selection) {
        sheet->set_selection(new Select_Directors(sheet, type, selection));
        sheet->print_selection(std::cout);


    }

    void movieRecommendation() {
        std::string input = "0";
        std::string movieName;
        std::string category;
        while(input != "-1"){
            std::cout << "\nYou have chosen to get a Movie Recommendation!.";
            std::cout << "\nIn order to choose a movie, tell me whether you want it by: "
                      << "\n\tDirector(D)"
                      << "\n\tGenre(G)"
                      << "\n\tActors(A)"
                      << "\n\tYear(Y)";
            std::cin >> input;
            if (input == "D"){
                std::cout << "\nGreat lets get you a similar?";
                std::cout << "\nWhat is the name of this movie you want it similar too?";
                std::cin >> movieName;
                std::cout << "\n Movie name is: " << movieName;
                std::cout << "\n Greate lets pull that movie!";
                if (getMovie(movieName) == nullptr){
                    std::cout << "That movie doesn't exist. Lets create it!";
                    userAddMovie();
                }
                std::cout << "\nSimilar movies by director is: ";
                printSimilar(getMovie(movieName)->getDirector(), "Director");
                std::cout << "\nWould you like another recommendation?(-1 for no, 1 for yes)";
                std::cin >> input;
            }
        }

    }

    void userRemoveGenre() {
        std::string input = "0";
        std::string genreName;
        std::string category;
        while(input != "-1") {
            std::cout << "\nYou have chosen remove a Genre or SubGenre!.";
            std::cout
                    << "\nWhat is the name of this Genre/SubGenre(If it is a SubGenre split by using a comma(Ex:Fiction,Sci-Fi)?";
            std::cin >> genreName;
            std::cout << "\n Genre name is: " << genreName;
            std::cout
                    << "\nWarning! THis will also delete all movies under this genre, do you want to continue?(Y for Yes, N for No)";
            std::cin >> input;
            if (input == "N") {
                std::cout << "\nDeleting that genre if it exists!";
                removeGenre(genreName);
                std::cout << "\nWould you like to delete another Movie?(-1 for no, 1 for yes)";
                std::cin >> input;
            }
            else {
                std::cout << "\nYou have decided not to delete this genre, would you like to delete a genre or exit to main menu?(-1 to exit, 1 to stay)";
            }
        }
    }

    bool userMenu() {
        std::cout << "Welcome to the Movie Recommender!\n"
                  << "This program allows you to create and remove genres and subgenres, add movies and remove them "
                     "and get a recommendation we think you would like!.\n";
        std::cout << "Ready?\n";
        std::string input;
        std::cin >> input;

        while(input != "-1") {
            std::string userInput;
            std::cout << "Your options are as below: \n";
            std::cout << "1: Create a Category/SubCategory \n";
            std::cout << "2: View all Categories/SubCategories\n";
            std::cout << "3: View Movies \n";
            std::cout << "4: Add a Movie\n";
            std::cout << "5: Remove a Category/SubCategory \n";
            std::cout << "6: Remove a Movie \n";
            std::cout << "7: Getting a movie recommendation!\n";
            std::cout << "-1: quit\n";
            std::cin >> userInput;

            if (userInput == "1") category();
            else if (userInput == "2") printAllCategories();
            else if (userInput == "3") printAllMovies();
            else if (userInput == "4") userAddMovie();
            else if (userInput == "5") userRemoveGenre();
            else if (userInput == "6") userRemoveMovie();
            else if (userInput == "7") movieRecommendation();
            else if (userInput == "-1") input = "-1";
            else {
                std::cout << "That wasn't a corrent input! Please try again!\n";
            }
        }
        std::cout << "Have a good day!";

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
        delete gen;
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
    void removeMovie(std::string Title){
        bool exists = false;
        for(Movie* m: genres) {
            if(m->isComposite()){
                if(m->getChild(Title) != nullptr){
                    exists = true;
                    m->remove(Title);
                }
            }
            else if(m->getChild(Title) != nullptr){
                exists = true;
                m->remove(Title);
            }

        }
        if(exists){
            sheet->remove_row(Title);
            std::cout << "\nMovie successfully removed!";
        }
        else{
            std::cout << "\nThat movie does not exist!";
        }
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
