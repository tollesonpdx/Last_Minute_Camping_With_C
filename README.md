# Last_Minute_Camping_With_C
seek camping spots within driving distance and their related weather forecasts

# IN SEARCH OF DARK SKIES:

## LAST MINUTE CAMPING FOR STARGAZING, ALMOST
A Project Report: Presented to Faculty and the 2018 New Beginnings Cohort of the Maseeh School of Computer Science at Portland State University in Partial Fulfillment of the Requirements for the New Beginnings Program by Chad M. Tolleson in the Winter of 2019.

## Introduction / Original Goals

The original goal of this project was to create a tool that allows a user to, based on a calendar of astronomical events, find reservable camping spots in areas with favorable: location, weather forecast, and light pollution. The user would first scan a calendar of upcoming astronomical events, select an event they want to observe, and then the program would find and return a short list of campgrounds filtered and sorted by the parameters mentioned above.

During the development of the tool, unexpected limitations arose so the end-goal was adjusted. The current iteration of the project strives to allow a user to provide their location, anticipated camping dates, and maximum driving range, for which the tool then produces a list of reservable campsites within range and the associated weather forecast. The original project goals are not forgotten and are slated for future development.

## Tools &amp; Data Sources Utilized

For this project, I elected to use the following tools:

- C
- SQLite3
- libcurl
- cJSON
- Google Maps API
- Reserve America API
- National Weather Service API
- GFZ German Research Centre for Geosciences

## Data Structures

Within the current version of the tool, I employ the following data structures:

- C structs
  - hold current user data within the process
  - serves as nodes for campgrounds, weather forecasts, light pollution reports, and astronomical event data structures (linked lists, binary search trees, etc)
- Linked List
  - holds list of user locations not yet geocoded
- Binary Search Tree
  - holds population of campgrounds meeting the search criteria
- SQLite3 Database
  - used for long term storage of all data points
  - databases utilize lists, binary search trees, B trees, hash tables, and more

## Algorithms

There are several algorithms utilized in this tool:

- Pattern Matching
  - cJSON is essentially a series of pattern matching functions combined together
- haversine formula
  - the distance between a user&#39;s location and all of the campgrounds in the database is calculated using the haversine formula. This is the first tool used to decrease the population of data points in a theoretical decrease and conquer algorithmic solution.
- Sorting / Searching Algorithms
  - SQLite employs multiple sort and search algorithms, internally choosing the most optimal based on parameters defined in the moment
  - SQLite typically employees hash tables for searching for particular tables, but also uses string matching for searching for values within fields (vs on fields)

## Program Narrative

This is a narrative style walkthrough of the tool, from both the user&#39;s standpoint and the tool&#39;s standpoint. The user runs the program, and then the program prompts the user to input their location, dates the user wants to go camping, and the maximum amount of time the user is willing to drive. The tool checks all of these inputs for accuracy, and then stores the values into a structure called userData. In this step, the maximum driving time is calculated as the maximum driving time (as provided by user) multiplied by an average speed limit of 60 miles per hour. This value is also stored in the userData struct. A log file called capstoneResultsLog.txt is opened, and the beginning of a log entry is written to file. This consists of a header area containing the current date and time. The database associated with the project, called tollesonCapstone.db is opened, and the database&#39;s tables are verified to exist. Any tables expected but missing from the database are created via the tool. After the tables are verified, the tool updates the userlocs (user locations) table with the current user&#39;s location (as entered by the user).

At this point in the process, the tool ensures that all user provided locations are stored and geocoded in the database. To start this part of the process, a linked list object called userList for holding userData structs is created. Now, the tool pulls any and all non-geocoded user locations from the database and stores them in a linked list of userData structs. The program traverses the linked list of userData structs, and obtains the geographic coordinates (geocodes) using a libcurl interface with the Google Maps API. The results of the libcurl operation are parsed into usable data using the cJSON JSON building and parsing library for C. As the geocodes are obtained, the corresponding user record in the database is updated. The tool is structured this way to minimize the number of calls to the Google Maps API over time.

At this point in the process, the analysis of campsites begins. To start this part of the process, a binary search tree object called campTree is created to contain active campground structures. The tool pulls a list of substantially all public campgrounds in the United States and Canada from the database and begins to analyze them one-by-one. Each campground is added to a C struct called campground. At this step, the distance from user is calculated using the haversine formula, and the campground availability is determined. Ideally, in the future, campground availability will be obtained via the Reserve America API, but for reasons explained below we are using a dummy value for availability at this point. To calculate the dummy availability value, the tool takes the distance between the user and campground, converts the value from a double to an integer and then determines whether the number is even or odd using the modulo operator. Evens are not available, odds are available. If the camp is within the maximum driving range and also available, then the tool adds the campground to the campTree binary search tree. Once the campground population is initially analyzed and the binary search tree is totally populated, the tool traverses the binary tree in non-decreasing order of distance from the user and performs two new functions. One, the tool updates the database table called distances with the geocodes of the user and campground and distance between, if the appropriate record is not already stored in said table. Two, the tool interfaces with the National Weather Service API (NWS), via libcurl, to obtain the weather forecast for each campground. The results from the NWS are parsed using the cJSON C library, combined into one contiguous character string, and added to the corresponding campground node.

A list of the campgrounds meeting the range and availability criteria, along with the corresponding weather forecast are printed to screen and the activity log file.

Finally, the tool frees all allocated memory, closes any open files, and closes the database before finishing its operation.

## Challenges &amp; Adjustments from Original Goals

During the evolution of this project, I encountered several unforeseen challenges that either changed the direction and goal of the project, added significant amounts of time to development, or, in many cases, both. Here is a brief summary of some of those challenges:

- SQLite3 is a free and portable database that integrates easily with C. I used particular compilation flags to link the SQLite library with my code, but a more intensive compilation option is available where all the underlying code is actually compiled into the program&#39;s executable. SQLite3&#39;s integration with C, is very convenient and largely intuitive because the publishers have created several high level &quot;wrapper&quot; functions that combine all underlying setup functions and intermediary steps into one function. The wrapper function still requires some work from the programmer, and these particular steps are where I first spent significant unbudgeted amounts of time. SQLite requires a programmer to build up database SQL statements in character strings. Any time these SQL statements include variables from the C process, those values must be converted from their original types into strings, and when encapsulated in single tick marks ( &#39; ). C does not natively contain a function allowing for the concatenation of multiple strings at once, so these statements must be built up from separate segments, one segment at a time. The C function for concatenating two strings together is called &quot;strcat&quot; and it is known to cause memory leak problems. This turned out to be an ongoing issue… plugging memory leaks. The other, and probably more interesting SQLite challenge is the notion of a callback function. Callback functions are  passed as an argument to another function and executed at the completion of the original function. Callback functions are a critical component of working with the SQL database because this is the feature that allows a user to execute functions iteratively on results from a SQL select query. Much of the critical operations in the tool occur via these callback functions. Learning how to properly structure these callback functions, especially wrapping my head around the notion of passing them as parameters to other functions was an unexpected, but very interesting, task that required a significant amount of unbudgeted time.
- libcurl is a client side URL transfer library that is widely and freely used. I included this library in my tool using particular compilation flags that can been seen in the makefile. The documentation and sample program are quite helpful, but some fiddling was still required to access the exact information needed from both the Google Maps API and the National Weather Service API.
- JSON (stands for JavaScript Object Notation) is a widely used file format that is used to structure data for transfer, but in a manner that is readable by humans. As with SQLite and libcurl, I compiled this library into my code with special compilation flags. Both the Google Maps API and the NWS provide data via JSON files. Parsing JSON really boils down to a series of string matching. While I could have written my own string matching functions to extract data from the Google Maps and NWS JSON data, I decided that in the spirit of learning about software development tools, learning and implementing a JSON parsing library was the correct option. This was mostly a time-consuming but intuitive task, but for one exception. The Google Maps API contains a poorly marked array of one element where an object ought to be. It took an entire frustrating day to reveal this quirk and proceed onto other tasks.

## Opportunities for Future Development (Next Steps)

In the course of developing this project, I compiled a list of tasks and features for future versions. In no particular order, here is that list:

- Add error handling to the National Weather Service API libcurl function. This website is both slow and prone to unexpected downtimes. A error handler to skip a campground when the weather forecast is unavailable will keep the program from terminating mid-stream unnecessarily.
- Create an data structure (adjacency matrix or dictionary of dictionaries) containing the maximum distance between contiguous US states and Canadian provinces. This will be used with a Floyd-Warshall shortest path algorithm to limit the campground search population to just those in states within the user derived maximum driving distance. Idea provided by Prof. York.
- Transform and load the light pollution data from the GFZ from a KMZ into a CSV or other text format that is loadable into the database.
- Implement a XML parsing library to integrate live data from the Reserve America API.
- Design a system to obtain campground availability information beyond the limitation currently set by the Reserve America API.
- Integrate detailed driving times and/or directions using the Google Maps API.
- Enable an auxiliary program that will continually ping the National Weather Service for updated forecasts and store them in the database. Then the campground forecasts would be pulled from the database if available, otherwise pulled live from the NWS.
- Explore the option of multithreading to obtain all of the weather forecasts simultaneously vs the current one at a time approach.
- Implement the &quot;perror&quot; based detailed error reporting feature on fragile sections of the program. Idea provided by Will Mass.
- Add an administrative menu to toggle on / off verbose printing and to trigger the updating of infrequently changing data (such as light pollution and calendar of astronomical events).
- Expand the database integration to other aspects of the program, currently only the user locations and campground details are actively managed in the database.
- Switch weather forecast sourcing from the National Weather Service to the The Weather Company. This is more expensive and requires a more elaborate integration but will provide quicker and more accurate weather forecasts. Idea provided by Evan DePosit.
- Obtain historical climate data to use as reference for dates that are beyond the weather forecast date range.
- Incorporate a calendar of astronomical events that the user will use to predetermine dates to feed into the program.
- And of course, a user interface besides the command line.
