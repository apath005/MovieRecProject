
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
class Interface {
    std::vector <Movie*> genres;
    Spreadsheet* sheet;

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
	addMovie("Mad_Max:_Fury_Road","2015","Action,Adventure","George Miller","Tom Hardy","97");
 	addMovie("Logan","2017","Fantasy,Adventure","James Mangold","Hugh Jackman","93");
	addMovie("The_Lion_King","1994","Animation,Adventure","Roger Allers,Rob Minkoff","Matthew Broderick","93");
	addMovie("Star_Wars:_Episode_V_-_The_Empire_Strikes_Back", "1980", "Sci Fi,Fantasy","Irvin Kershner", "Mark Hamill", "94");
	addMovie("Back_To_The_Future", "1985", "Sci Fi,Adventure", "Robert Zemeckis", "Michael J. Fox", "96");
	addMovie("Jurassic_Park", "1993", "Sci Fi,Action", "Steven Spielberg", "Sam Niell", "91");
	addMovie("Monty_Python_and_the_Holy_Grail", "1975", "Comedy", "Terry Gilliam,Terry Jones", "Graham Chapman", "97");
	addMovie("Coco", "2017", "Comedy", "Lee Unkrich", "Anthony Gonzalez", "97");
	addMovie("One_Upon_A_Time_In_Hollywood", "2019", "Drama,Comedy", "Quentin Tarantino", "Leonardo DiCaprio,Brad Pitt", "85");
	addMovie("La La Land","2016","Drama,Comedy","Damien Chazelle", "Ryan Gosling,Emma Stone", "91" );
	addMovie("Ghostbusters", "1984", "Adventure,Comedy", "Ivan Reitman", "Bill Murray", "97");
	addMovie("The_Truman_Show", "1998", "Drama,Comedy", "Peter Weir", "Jim Carrey", "95");
	addMovie("The_Exorcist", "1973", "Horror", "William Friedkin", "Ellen Burstyn", "83");
	addMovie("Hereditary", "2018", "Horror,Thriller", "Ari Aster", "Toni Collette", "89");
	addMovie("The_Shining", "1980", "Horror,Thriller", "Stanley Kubrick", "Jack Nicholson", "84");
	addMovie("The_Conjuring", "2013", "Horror,Thriller", "James Wan", "Vera Farmiga", "86");
	addMovie("The_Ring", "2002", "Horror,Thriller", "Gore Verbinski", "Naomi Watts", "71");
	addMovie("Halloween", "1978", "Horror,Slasher", "John Carpenter", "Jamie Lee Curtis", "96");
	addMovie("Insidious", "2010", "Horror,Thriller", "James Wan", "Patrick Wilson", "66");
	addMovie("It", "2017", "Horror,Thriller", "Andy Muschietti", "Bill Skarsgard", "86");
	addMovie("Casablanca", "1942", "Drama", "Michael Curtiz", "Humphrey Bogart,Ingrid Bergman", "99");
	addMovie("The_Shape_of_Water", "2017", "Romance,Fantasy", "Guillermo del Toro", "Sally Hawkins", "92");
	addMovie("The_Big_Sick", "2017", "Romance", "Michael Showalter", "Kumail Nanjiani", "98");
	addMovie("Her", "2013", "Drama,Comedy", "Spike Jonze", "Joaquin Pheonix,Scarlett Johansson", "94");
	addMovie("Groundhog_Day", "1993", "Romance", "Harold Ramis", "Bill Murray", "96"); 
	userMenu();

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
            std::cout << "\nYou have chosen to create a movie. I will need a few details!\n";
            std::cout << "\nFirst enter the movie name: ";
            std::getline(std::cin, Title);
            std::cout << "\nEnter the year of the movie!";
            std::getline(std::cin, Year);
            std::cout << "\nEnter the Genre of the movie. If the movie has a subcategory, Enter the main genre first followed by the Sub Genre(Ex: Fiction,Comedy)";
            std::getline(std::cin, Genre);
            std::cout << "\nEnter the Director of the movie! Split the names using a comma";
            std::getline(std::cin, Director);
            std::cout << "\nEnter the name of the Actors! Split the names using a comma";
            std::getline(std::cin, Actors);
            std::cout << "\nFinally enter the Metascore";
            std::getline(std::cin, Metascore);

            addMovie(Title, Year, Genre, Director, Actors, Metascore);

            std::cout << "\nWill you be adding more movies?(Enter -1 for No, 1 for Yes)";
            std::getline(std::cin, input);

        }
    }

    void category() {

        std::string input = "";
        std::string genre;
        while(input != "-1"){
            std::cout << "\nYou have chosen to create a category.";
            std::cout << "\nLets create a Category!";
            std::cout << "\nWhat is the name of this genre? (If it is a subcategory, split name by comma Ex: Fiction,Comedy!) ";
            std::getline(std::cin, genre);
            std::cout << "\nGenre name is: " << genre;
            if(genreExists(genre)){
                std::cout << "\nThat genre already exists!";
            }
            else{
                std::cout << "\nCreating genre now!";
                createGenre(genre);
            }
            std::cout << "\nWould you like to create another genre?(-1 for no, 1 for yes)";
            std::getline(std::cin, input);

        }

    }

    void userRemoveMovie() {
        std::string input = "";
        std::string movieName;
        while(input != "-1"){
            std::cout << "\nYou have chosen to remove a movie!.";
            std::cout << "\nIn order to delete a movie you need a Title(Enter 1 to continue! or -1 to quit)";
            std::getline(std::cin, input);
            if (input == "1"){
                std::cout << "\nGreat lets remove a Movie!";
                std::cout << "\nWhat is the name of this movie?";
                std::getline(std::cin, movieName);
                std::cout << "\n Movie name is: " << movieName;
                std::cout << "\nDeleting that movie if it exists!";
                removeMovie(movieName);
                std::cout << "\nWould you like to delete another Movie?(-1 for no, 1 for yes)";
                std::getline(std::cin, input);
            }
        }
    }
    Movie* getMovie(std::string movieName){
        for(Movie* m : genres){
            if(m->getChild(movieName) == nullptr){
                continue;
            }
            else {
                return m->getChild(movieName);
            }

        }
        return nullptr;
    }

    void printDirector(std::string director) {
        std::cout << "\nHere are all movies that were directed by: " << director << std::endl;
        sheet->set_selection(new Select_Directors(sheet, director, "Director"));
        sheet->print_selection(std::cout);


    }

    void printActors(std::string actor) {
        std::cout << "\nHere are all movies that actor : " << actor << " was in: " << std::endl;
        sheet->set_selection(new Select_Actors(sheet, actor, "Actors"));
        sheet->print_selection(std::cout);
    }

    void printYear(std::string year) {
        std::cout << "\nHere are all movies that in the year : " << year << std::endl;
        sheet->set_selection(new Select_Year(sheet, year, "Year"));
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
            std::getline(std::cin, input);
            if (input == "D"){
                std::cout << "\nGreat lets get you a similar?";
                std::cout << "\nWhat is the name of this movie you want it similar too? ";
                std::getline(std::cin, movieName);
                std::cout << "\n Movie name is: " << movieName;
                std::cout << "\n Great lets pull that movie!";
                if (getMovie(movieName) == nullptr){
                    std::cout << "That movie doesn't exist. Lets create it!\n";
                    userAddMovie();
                }
                std::cout << "\nSimilar movies by director is: ";
                printDirector(getMovie(movieName)->getDirector());
                std::cout << "\nWould you like another recommendation?(-1 for no, 1 for yes) ";
                std::getline(std::cin, input);
            }
            if (input == "A"){
                std::cout << "\nGreat lets get you a similar movie that has those actors?";
                std::cout << "\nWhat is the name of this Actor you want? ";
                std::getline(std::cin, movieName);
                std::cout << "\nActor name is: " << movieName;
                std::cout << "\nGreat lets pull a similar movie!";
                std::cout << "\nSimilar movies by Actor is: ";
                printActors((movieName));
                std::cout << "\nWould you like another recommendation?(-1 for no, 1 for yes) ";
                std::getline(std::cin, input);
            }
            if (input == "G"){
                std::cout << "\nGreat lets get you movies in that genre?";
                std::cout << "\nWhat is the name of this Genre you want? ";
                std::getline(std::cin, movieName);
                std::cout << "\nGenre name is: " << movieName;
                std::cout << "\nGreat lets pull movies in that genre!";
                std::cout << "\nMovies: \n";
                printAllMovies((movieName));
                std::cout << "\nWould you like another recommendation?(-1 for no, 1 for yes) ";
                std::getline(std::cin, input);
            }
            if (input == "Y"){
                std::cout << "\nGreat lets print you movies that are in that yea? ";
                std::cout << "\nGive me a movie that you would like that were made in the same year! ";
                std::getline(std::cin, movieName);
                std::cout << "\nMovie name is: " << movieName;
                std::cout << "\nGreat lets pull movies in that year!";
                std::cout << "\nMovies: ";
                printYear((getMovie(movieName)->getMovieYear()));
                std::cout << "\nWould you like another recommendation?(-1 for no, 1 for yes) ";
                std::getline(std::cin, input);
            }

            if (input == "-1") input = "-1";
            else if (input == "1") input = "1";
            else{
                std::cout << "\nThat wasn't a correct input, please try again! (If you would like to quit press -1)";
                std::getline(std::cin, input);
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
                    << "\nWhat is the name of this Genre/SubGenre(If it is a SubGenre split by using a comma(Ex:Fiction,Sci-Fi)? ";
            std::getline(std::cin, genreName);
            std::cout << "\n Genre name is: " << genreName;
            std::cout
                    << "\nWarning! THis will also delete all movies under this genre, do you want to continue?(Y for Yes, N for No) ";
            std::getline(std::cin, input);
            if (input == "Y") {
                std::cout << "\nDeleting that genre if it exists!";
                removeGenre(genreName);
                std::cout << "\nWould you like to delete another Genre?(-1 for no, 1 for yes) ";
                std::getline(std::cin, input);
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
        std::getline(std::cin, input);

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
            std::getline(std::cin, userInput);

            if (userInput == "1") category();
            else if (userInput == "2") printAllCategories();
            else if (userInput == "3") printAllMovies();
            else if (userInput == "4") userAddMovie();
            else if (userInput == "5") userRemoveGenre();
            else if (userInput == "6") userRemoveMovie();
            else if (userInput == "7") movieRecommendation();
            else if (userInput == "-1") input = "-1";
            else {
                std::cout << "That wasn't a correct input! Please try again!\n";
            }
        }
        std::cout << "Have a good day!";

    }
    void printAllMovies(){
        for(Movie* m : genres) {
            std::cout << m->getMovie();
        }
>>>>>>> master
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
               std::cout << "The genre: " << m->getGenreName() << " has subgenres: "
               << m->printSubGenres() << std::endl;
           }
           else {
               std::cout << "This genre is: " << m->getGenreName() << " and has no subgenres!" << std::endl;
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
            if(m->remove(Title)) exists = true;

        }
        if(exists){
            sheet->remove_row(Title);
            std::cout << "\nMovie successfully removed!\n";
        }
        else{
            std::cout << "\nThat movie does not exist!\n";
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
