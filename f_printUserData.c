// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_printUserData.c

#include "headers.h"

void printUserData(struct userData * u1)
    {

    printf("Location: %s\n", u1->userLocation);
   
    printf("latitude & longitude: %lf, %lf\n",
            u1->u_lat, u1->u_long);

    printf("date range: %d/%d/%d - %d/%d/%d\n",
        u1->begDate.tm_mon, u1->begDate.tm_mday, 
        u1->begDate.tm_year,
        u1->endDate.tm_mon, u1->endDate.tm_mday, 
        u1->endDate.tm_year);

    printf("max drive time: %.2lf hours\n", u1->maxDriveTime);

    printf("max drive distance (time * 60mph avg): "
            "%.2lf miles\n", u1->maxDriveDist);

    }

