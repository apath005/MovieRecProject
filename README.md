# Movie Recommender
 > Authors: [Abdirahman Abdi](https://github.com/AmbientOne), [Joel Garcia](https://github.com/jgarc594), [Anant Pathak](https://github.com/apath005)


## Project Description
 > * Our group chose the Movie Recommender option as our choice of project. We believe the implementation and usage of multiple sorting and searching algorithms 
and creating an effective application in which an user can search movies is challenging and interesting. We plan on using C++ and
[TheMovieDB](https://developers.themoviedb.org/3). The UI will be a console GUI that will allow users to have an option of picking a movie based on parameters such as directors, genres, similar movies, movie eras, actors, and many more. The program will then output to the user a list of similar movies, or movies that much said parameters based upon the users input. 
 > * The design patterns we will be implementing will consist of Composite and Strategy pattern. The reason we picked these two patterns is because of their synergy allowing for 
us to create a backend that allows us to access a family of classes without having to modify the structures of the classes themselves. This means that when we create our 
algorithm for looking for movie recommendations, we will not have to edit the movie objects themselves in order to return a movie recommendation/s. We anticipate the need 
to overload classes when looking for movie recommendations and we believe that Composite and Strategy combo will allow us to overcome that issue. The composite pattern will
specifically allow us to visit the strategy children classes while allowing us to separate the recommendation algorithm from the object classes themselves. We can use
a strategy pattern to identify certain parameters through classes which detect user input, such as generating classes by movie genres and movie eras which inherit from a base class.
Our base class will have a class called 'Movie' which will be the interface for generating recommendations back to the user based on specific signifiers pertaining to movie genres,
actors, directors, along with similar movies. The 'Movie' class will be beneficial for our interface since the base class will be static throughout the functionality of the program.
The composite and strategy patterns can then be integrated to call on the base class to produce a value unique to the user and use separate data structures to perform new operations
on each data set. The strategy pattern will be helpful in building a tree that searches and performs operations on each node in the background of the program to return a value specific to the user.

 > ## Phase II
![MR_Diagram](https://user-images.githubusercontent.com/50225081/108142278-4f148d00-707a-11eb-90ac-7d7581b4b81d.png)

> * NOTE: WE HAVE CHANGED OUR ORIGINAL PROPOSAL PATTERNS FROM STRATEGY AND VISITOR TO STRATEGY AND COMPOSITE.

![UPDATED_UML](https://user-images.githubusercontent.com/77028776/110581505-875e3700-811f-11eb-9d86-3462d1833eba.png)

> * PHASE 4 UPDATE: UPDATED UML DIAGRAM TO REFLECT CHANGES DURING DEVELOPMENT AND USES OF STRATEGY, COMPOSITE, AND FACTORY PATTERNS. WE HAVE ADDED THE USE OF A FACTORY PATTERN AS A USE FOR OUR INTERFACE.

 > * The diagram above shows our class structure and how we plan on integrating the Compisite pattern and the Strategy pattern. We can see above that we will have the Movie Recommender Interface hold our final movie recommendation. This is a design choice so we have a family of classes that allow use different algorithms that will allow us to aggregate data that meets our required patterns.  The Strategy pattern will have an algorithm that will allow it to choose the best possible movie based on the parameters and will implement a final conclusive movie recommendation. We can see from the diagram above that we will have a select function that will allow for a recusively called visit to each of the selected classes and aggregate a movie recommendation from visiting inside those classes. The composite pattern will allow us to store movies for genres in a tree data data structure. These two will allow users to choose enter a movie and from create a perfect movie match/es. The factory pattern will allow us to house an interface that will combine these patterns and generate an easy- to- use user interface along with a database.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.
 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 ![MainMenu](https://user-images.githubusercontent.com/77028776/110582423-0bfd8500-8121-11eb-9c9b-65e06feab2e8.png)
 Main Menu with user options
 
 ![CreateCategories](https://user-images.githubusercontent.com/77028776/110582288-dc4e7d00-8120-11eb-963e-90e51149faad.png)
 Output of Option for Creating Movie Categories (Genres)
 
 ![ViewCategories](https://user-images.githubusercontent.com/77028776/110582533-34857f00-8121-11eb-916d-e6ed2e96a5e5.png)
 Output of Option for Viewing Categories (Genres) and subGenres
 
 ![VIEWMovies](https://user-images.githubusercontent.com/77028776/110582744-7f06fb80-8121-11eb-8095-bf1ff5f6c2ff.png)
 Output for Option of Viewing All Movies (sample output)
 
 ![CreatingMovie](https://user-images.githubusercontent.com/77028776/110583161-1d935c80-8122-11eb-944a-1f025216e4ef.png)
 Output for Option of Creating a Movie
 
 ![DeleteGenre](https://user-images.githubusercontent.com/77028776/110583223-3734a400-8122-11eb-8aa8-41ebf5a57339.png)
 Output for Option of Removing a Genre/ subGenres
 
 ![DeleteMovie](https://user-images.githubusercontent.com/77028776/110583340-664b1580-8122-11eb-8313-a7c18ab4c691.png)
 Output for Option of Removing a Movie
 
 ![RECbyGenre](https://user-images.githubusercontent.com/77028776/110583403-7f53c680-8122-11eb-8669-2af58f915640.png)
 Output for Option of Recommendation by Genre
 
 ![RECbyDirector](https://user-images.githubusercontent.com/77028776/110583473-97c3e100-8122-11eb-9412-8b07a3124b37.png)
 Output for Option of Recommendation by Director

 ## Installation/Usage
 1. run cmake3 .
 2. run make
 3. run the executable "./recommender"
 4. Follow prompts on the Main Menu screen:
 > Choose from either:
 > * 1: Create a Category/SubCategory
 > * 2: View all Categories/SubCategories 
 > * 3: View Movies
 > * 4: Add a Movie
 > * 5: Remove a Category/SubCategory
 > * 6: Remove a Movie
 > * 7: Getting a movie recommendation!
 > * -1: quit
 5. View the database of films, and go ahead and find yourself a perfect movie recommendation by Actor, Director, Year, or Genre!
 6. Exit Program.

 ## Testing
 Our project was tested and validated using the Google Test Framework. We used the google test submodule within our repository to test a variety of functions used across each design pattern. All test cases are recorded in test.cpp, and tests can be viewed and executed using the "./test" executable.
 
