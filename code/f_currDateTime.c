// Chad Tolleson Copywrite (c) 2019
// New Beginnings - Capstone Project
// filename: f_currDateTime.c


// attribution: https://en.wikipedia.org/wiki/C_date_and_time_functions

// attribution: https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811 USER paxdiablo

#include "headers.h"

int displayCurrentDateTime()
    {
    time_t current_time;
    time(&current_time);
    struct tm* tm_info = localtime(&current_time);
    char timebuffer[26];
    strftime(timebuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current date and time is: %s\n",timebuffer);
    return 0;
    }

char* returnCurrentDateTime()
    {
    time_t current_time;
    time(&current_time);
    struct tm* tm_info = localtime(&current_time);
    char* timebuffer = calloc(27, sizeof(char));
    strftime(timebuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    //printf("%s\n",timebuffer);
    return timebuffer;
    }


/* the below code is the same from the website attributed above

int printCurrentDateTime()
    {
    
    time_t current_time;
    char* c_time_string;

    // Obtain current time.
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
        {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        return -1;
        }

    // Convert to local time format.
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
        {
        fprintf(stderr, "Failure to convert the current time.\n");
        return -1;
        }

    // Print to stdout. ctime() has already added a terminating newline character.
    printf("Current time is %s", c_time_string);
    
    return 0;
    
    }
*/
