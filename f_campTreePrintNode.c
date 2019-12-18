// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreePrintNode.c

#include "headers.h"

int campTreePrintNode(struct campground* node)
    {
    //printf("\n\n");
    for (int i = 0; i < 65; i++)
        { printf("="); }
    printf("\n");
    printf("Campground Name & Code: %s    %s\n"
            "Lat,Lng: %lf,%lf\n"
            "Distance: %lf miles\n"
            "Available: ",
            node->c_name, node->c_code, 
            node->c_lat,node->c_long, node->distance);
    printf(node->c_available ? "yes\n" : "no\n");
    printf("Weather Forecast:  %s\n",node->c_weathers);
    return 0;
    }
    
