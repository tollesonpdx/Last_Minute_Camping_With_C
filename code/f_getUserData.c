// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_getUserData.c

#include "headers.h"

struct userData * getUserData()
    {
    
    struct userData * u1 = malloc(sizeof(struct userData));
    char l[1000];
    int m = -1;
    int d = -1;
    int y = -1;
    double s = -1.0;

    printf("Enter your Location: ");
    scanf("%1000[^\n]", l);
    while (l == NULL || strcmp(l,"") == 0 
            || strcmp(l,"\n") == 0)
        {
        while ((getchar()) != '\n');
        printf("Invalid Location \nEnter your Location: ");
        scanf("%1000[^\n]", l);
        }
    while ((getchar()) != '\n'); // clearing input buffer

    strcpy(u1->userLocation, l);
    
    printf("Enter your starting date as  MM/DD/YYYY: ");
    scanf("%d/%d/%d", &m,&d,&y);
    while (m == -1 || d == -1 || y == -1)
        {
        while ((getchar()) != '\n');
        printf("Invalid Date \n"
            "Enter your starting date as MM/DD/YYYY: ");
        scanf("%d/%d/%d", &m,&d,&y);
        }
    while ((getchar()) != '\n'); // clearing input buffer

    u1->begDate.tm_mon = m;
    u1->begDate.tm_mday = d;
    u1->begDate.tm_year = y;
    m = -1;
    d = -1;
    y = -1;

    printf("Enter your ending date as MM/DD/YYYY: ");
    scanf("%d/%d/%d", &m,&d,&y);
    while (m == -1 || d == -1 || y == -1)
        {
        while ((getchar()) != '\n');
        printf("Invalid Date \n"
            "Enter your ending date as MM/DD/YYYY: ");
        scanf("%d/%d/%d", &m,&d,&y);
        }
    while ((getchar()) != '\n'); // clearing input buffer

    u1->endDate.tm_mon = m;
    u1->endDate.tm_mday = d;
    u1->endDate.tm_year = y;


    printf("Enter your maximum driving time, in hours: ");
    scanf("%lf", &s);
    while (s == -1.0)
        {
        while ((getchar()) != '\n');
        printf("Invalid Driving Time \n"
                "Enter your maximum driving time, in hours: ");
        scanf("%lf", &s);
        }
    
    while ((getchar()) != '\n'); // clearing input buffer

    u1->maxDriveTime = s;
    u1->maxDriveDist = u1->maxDriveTime * 60;
    
    u1->u_lat = 0.0;
    u1->u_long = 0.0;
    
    return u1;
    }

// attribution: syntax for reading in date values obtained from user Hopeless Noob on this page: https://stackoverflow.com/questions/25956444/c-using-scanf-or-any-other-function-to-get-date-mm-dd-yyyy-in-int

