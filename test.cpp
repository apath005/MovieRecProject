#include "gtest/gtest.h"

#include <iostream>

#include "Movie.hpp"
#include "MovieSelector.hpp"
#include "MovieGenres.hpp"
#include "setMovie.hpp"
#include "interface.hpp"
#include "spreadsheet.cpp"

TEST(RecommenderTest, DirectorsTestValue) {
	auto* sheet = new Spreadsheet();
	auto* Interface_ = new Interface(sheet);
	sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
	Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
	std::stringstream s;
	sheet->set_selection(new Select_Directors(sheet, "Abdi", "Director"));
	sheet->print_selection(s);
	EXPECT_EQ("\nMovie Title: Movie1\nYear: 2019\nGenre: Romance\nDirectors: Abdi\nActors: Jogar,Anant\nMetascore: 55.5\n",s.str());
}

TEST(RecommenderTest, ActorsTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        std::stringstream s;
        sheet->set_selection(new Select_Actors(sheet, "Jogar,Anant", "Actors"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Movie1\nYear: 2019\nGenre: Romance\nDirectors: Abdi\nActors: Jogar,Anant\nMetascore: 55.5\n",s.str());
}

TEST(RecommenderTest, YearTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        std::stringstream s;
        sheet->set_selection(new Select_Year(sheet, "2019", "Year"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Movie1\nYear: 2019\nGenre: Romance\nDirectors: Abdi\nActors: Jogar,Anant\nMetascore: 55.5\n",s.str());
}

TEST(RecommenderTest, ActorsTestFilmTitanic) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Titanic", "1997", "Romance", "James Cameron", "DiCaprio,Winset", "78");
        std::stringstream s;
        sheet->set_selection(new Select_Actors(sheet, "DiCaprio,Winset", "Actors"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Titanic\nYear: 1997\nGenre: Romance\nDirectors: James Cameron\nActors: DiCaprio,Winset\nMetascore: 78\n",s.str());
}

TEST(RecommenderTest, ActorsTestTitanicAgainstTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Titanic", "1997", "Romance", "James Cameron", "DiCaprio,Winset", "78");
	Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        std::stringstream s;
        sheet->set_selection(new Select_Actors(sheet, "DiCaprio,Winset", "Actors"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Titanic\nYear: 1997\nGenre: Romance\nDirectors: James Cameron\nActors: DiCaprio,Winset\nMetascore: 78\n",s.str());
}

TEST(RecommenderTest, YearTestTheShiningAgainstTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("The Shining", "1980", "Horror", "Stanley Kubrick", "Jack Nicholson,Shelley Duvall", "84");
	Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        std::stringstream s;
        sheet->set_selection(new Select_Year(sheet, "1980", "Year"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: The Shining\nYear: 1980\nGenre: Horror\nDirectors: Stanley Kubrick\nActors: Jack Nicholson,Shelley Duvall\nMetascore: 84\n",s.str());
}

TEST(RecommenderTest, DirectorTestTheElfAgainstTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Elf", "2003", "Comedy", "Jon Favreau", "Will Ferrell,James Caan", "70");
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        std::stringstream s;
        sheet->set_selection(new Select_Directors(sheet, "Jon Favreau", "Director"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Elf\nYear: 2003\nGenre: Comedy\nDirectors: Jon Favreau\nActors: Will Ferrell,James Caan\nMetascore: 70\n",s.str());
}

TEST(RecommenderTest,ActorTestForrestGumpAgainstMultipleTestValues) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Forrest Gump", "1994", "Drama", "Robert Zemekis", "Tom Hanks,Robin Wright", "88");
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        Interface_->addMovie("Movie3", "2020", "Comedy", "Anant", "Jogar,Abdi", "86");
        std::stringstream s;
        sheet->set_selection(new Select_Actors(sheet, "Tom Hanks,Robin Wright", "Actors"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Forrest Gump\nYear: 1994\nGenre: Drama\nDirectors: Robert Zemekis\nActors: Tom Hanks,Robin Wright\nMetascore: 88\n",s.str());
}

TEST(RecommenderTest, YearTestTheDarkKnightAgainstMultipleTestValues) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("The Dark Knight", "2008", "Action", "Christopher Nolan", "Christian Bale,Heath Ledger", "90");
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
	Interface_->addMovie("Movie3", "2020", "Comedy", "Anant", "Jogar,Abdi", "86");
        std::stringstream s;
        sheet->set_selection(new Select_Year(sheet, "2008", "Year"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: The Dark Knight\nYear: 2008\nGenre: Action\nDirectors: Christopher Nolan\nActors: Christian Bale,Heath Ledger\nMetascore: 90\n",s.str());
}

TEST(RecommenderTest, DirectorTestInceptionAgainstMultipleTestValues) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Inception", "2010", "Sci-Fi", "Christopher Nolan", "Leonardo DiCaprio,Joseph-Gordon-Levitt", "88");
        Interface_->addMovie("Movie1", "2019", "Romance", "Abdi", "Jogar,Anant", "55.5");
        Interface_->addMovie("Movie3", "2020", "Comedy", "Anant", "Jogar,Abdi", "86");
        std::stringstream s;
        sheet->set_selection(new Select_Directors(sheet, "Christopher Nolan", "Director"));
        sheet->print_selection(s);
        EXPECT_EQ("\nMovie Title: Inception\nYear: 2010\nGenre: Sci-Fi\nDirectors: Christopher Nolan\nActors: Leonardo DiCaprio,Joseph-Gordon-Levitt\nMetascore: 88\n",s.str());
}

TEST(RecommenderTest, GenreTestValue) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Movie3", "2020", "Comedy", "Anant", "Jogar,Abdi", "86");
        std::stringstream genre;
        sheet->set_selection(new Select_Genre("Comedy"));
        sheet->print_selection(genre);
        EXPECT_EQ("\nMovie Title: Movie3\nYear: 2020\nGenre: Comedy\nDirectors: Anant\nActors: Jogar,Abdi\nMetascore: 86\n",genre.str());
}

TEST(RecommenderTest, GenreTestTheAvengers) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("The Avengers", "2012", "Action", "Joss Whedon", "Robert Downey Jr.,Chris Evans", "80");
        std::stringstream genre;
	sheet->set_selection(new Select_Genre("Action"));
        sheet->print_selection(genre);
        EXPECT_EQ("\nMovie Title: The Avengers\nYear: 2012\nGenre: Action\nDirectors: Joss Whedon\nActors: Robert Downey Jr.,Chris Evans\nMetascore: 80\n",genre.str());
}

TEST(RecommenderTest, GenreTestComedyRomance) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
	Interface_->addMovie("Movie3", "2020", "Comedy,Romance", "Anant", "Jogar,Abdi", "86");
        std::stringstream genre;
        sheet->set_selection(new Select_Genre("Comedy,Romance"));
        sheet->print_selection(genre);
        EXPECT_EQ("\nMovie Title: Movie3\nYear: 2020\nGenre: Comedy,Romance\nDirectors: Anant\nActors: Jogar,Abdi\nMetascore: 86\n",genre.str());
}

TEST(RecommenderTest, GenreTestNewFilm) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("La La Land", "2016", "Comedy,Romance", "Damien Chazelle", "Ryan Gosling,Emma Stone", "80");
        std::stringstream genre;
        sheet->set_selection(new Select_Genre("Comedy,Romance"));
        sheet->print_selection(genre);
        EXPECT_EQ("\nMovie Title: La La Land\nYear: 2016\nGenre: Comedy,Romance\nDirectors: Damien Chazelle\nActors: Ryan Gosling,Emma Stone\nMetascore: 80\n",genre.str());
}

TEST(RecommenderTest, getMovieTest) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Halloween", "1978", "Horror,Slasher", "John Carpenter", "Jamie Lee Curtis", "96");
	Movie * movieTest = Interface_->getMovie("Halloween");
        EXPECT_EQ(Interface_->getMovie("Halloween"), movieTest);
}

TEST(RecommenderTest, genreExistsTest) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Halloween", "1978", "Horror,Slasher", "John Carpenter", "Jamie Lee Curtis", "96");
        EXPECT_EQ(Interface_->genreExists("Horror"), true);
}

TEST(RecommenderTest, genreDoesNotExistTest) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Halloween", "1978", "Horror,Slasher", "John Carpenter", "Jamie Lee Curtis", "96");
        EXPECT_EQ(Interface_->genreExists("Comedy"), false);
}

TEST(RecommenderTest, multipleGenreExistsTest) {
        auto* sheet = new Spreadsheet();
        auto* Interface_ = new Interface(sheet);
        sheet->set_column_names({"Title", "Year", "Genre", "Director", "Actors", "Metascore"});
        Interface_->addMovie("Halloween", "1978", "Horror,Slasher", "John Carpenter", "Jamie Lee Curtis", "96");
	Interface_->addMovie("La La Land", "2016", "Comedy,Romance", "Damien Chazelle", "Ryan Gosling,Emma Stone", "80");
        EXPECT_EQ(Interface_->genreExists("Comedy"), true);
	EXPECT_EQ(Interface_->genreExists("Horror"), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
