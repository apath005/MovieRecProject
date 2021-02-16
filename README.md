# Movie Recommender
 > Authors: [Abdirahman Abdi](https://github.com/AmbientOne), [Joel Garcia](https://github.com/jgarc594), [Anant Pathak](https://github.com/apath005)


## Project Description
 > * Our group chose the Movie Recommender option as our choice of project. We believe the implementation and usage of multiple sorting and searching algorithms 
and creating an effective application in which an user can search movies is challenging and interesting. We plan on using C++ and
[TheMovieDB](https://developers.themoviedb.org/3). The UI will be a console GUI that will allow users to have an option of picking a movie based on parameters such as directors, genres, similar movies, movie eras, actors, and many more. The program will then output to the user a list of similar movies, or movies that much said parameters based upon the users input. 
 > * The design patterns we will be implementing will consist of Strategy and Visitor pattern. The reason we picked these two patterns is because of their synergy allowing for 
us to create a backend that allows us to access a family of classes without having to modify the structures of the classes themselves. This means that when we create our 
algorithm for looking for movie recommendations, we will not have to edit the movie objects themselves in order to return a movie recommendation/s. We anticipate the need 
to overload classes when looking for movie recommendations and we believe that strategy and visitor combo will allow us to overcome that issue. The visitor pattern will
specifically allow us to visit the strategy children classes while allowing us to seperate the recommendation algorithm from the object classes themselves. We can use
a strategy pattern to identify certain parameters through classes which detect user input, such as generating classes by movie genres and movie eras which inherit from a base class.
Our base class will have a class called 'Movie' which will be the interface for generating recommendations back to the user based on specific signifiers pertaining to movie genres,
actors, directors, along with similar movies. The 'Movie' class will be beneficial for our interface since the base class will be static throughout the functionality of the program.
The composite and visitor patterns can then be integrated to call on the base class to produce a value unique to the user and use separate data structures to perform new operations
on each data set. The visitor pattern will be helpful in building a tree that searches and performs operations on each node in the background of the program to return a value specific to the user.

 > ## Phase II
![MR_Diagram](https://user-images.githubusercontent.com/77028776/108130400-752f3280-7064-11eb-844a-f7aa86a74662.png)
 > * The diagram above shows our class structure and how we plan on integrating the Vistor pattern and the Strategy pattern. We can see above that we will have the Movie Recommender Interface hold our final movie recommendation. This is a design choice so we have a family of classes that allow use different algorithms that will allow us to aggregate data that meets our required patterns. The vistor pattern will visit each of these classes and finalize a movie or movies that meet the required settings. The Vistor pattern will have an algorithm that will allow it to choose the best possible movie based on the parameters and will implement a final conclusive movie recommendation. We can see from the diagram above that we will have a visitor object visit each of the classes and aggregate a perfectMovieMatch from visiting inside those classes. 
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
 
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
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
