// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_geocodeUser.c

#include "headers.h"

// function definition
void geocodeUser(userData* user, int p)
    {

    if (p) { printf("geocoding user location...\n"); }
    
    char* add = convertAddress2G(user->userLocation);
    buffer* buff = curlGeocode(add, p);
    double* coords = parseCoords(buff->info, p);
    user->u_lat = coords[0];
    user->u_long = coords[1];

    if (p)
        { 
        printf("lat %lf, lng %lf\n",user->u_lat,user->u_long);
        printf("user location geocoded successfully\n");
        }

    free(add);
    free(coords);
    free(buff);
    return;
    }


           

