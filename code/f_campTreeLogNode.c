// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeLogNode.c

#include "headers.h"

int campTreeLogNode(struct campground* node)
    {
    FILE* f1 = fopen("capstoneResultsLog.txt","a+");
    fprintf(f1,"\n\n");
    for (int i = 0; i < 65; i++)
        { fprintf(f1,"="); }
    fprintf(f1,"\n");
    fprintf(f1,"Campground Name & Code: %s    %s\n"
            "Lat,Lng: %lf,%lf\n"
            "Distance: %lf miles\n"
            "Available: ",
            node->c_name, node->c_code, 
            node->c_lat,node->c_long, node->distance);
    fprintf(f1,node->c_available ? "yes\n" : "no\n");
    fprintf(f1,"Weather Forecast:  %s\n",node->c_weathers);
    fclose(f1);
    return 0;
    }
    
