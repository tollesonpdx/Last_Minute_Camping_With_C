// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeAdd.c

#include "headers.h"

int campTreeAdd(struct campTree* C, double lng, double lat, char*name, char* code, int p)
    {
    if (p) { printf("adding campground to fresh node...\n"); }
    
    // make new node to store campground information
    struct campground* fresh = malloc(sizeof(campground));
    strcpy(fresh->c_code, code);
    strcpy(fresh->c_name, name);
    strcpy(fresh->c_address, "not needed yet");
    fresh->c_lat = lat;
    fresh->c_long = lng;
    fresh->distance = haversine(C->userLat,C->userLng,lat,lng);
    int tempavail = fresh->distance; // temp availability
    fresh->c_available = (tempavail % 2);
    fresh->c_weathers = NULL;
    fresh->left = NULL;
    fresh->right = NULL;
    
    if (p)
    //if (0) // harded coded to turn off printing
        {
        printf("fresh node");
        campTreePrintNode(fresh);
        }

    // only add to camp tree if distance is within range
    // and available
    if (fresh->distance <= C->maxDriveDist 
            && fresh->c_available == 1)
        {
        if (C->root == NULL)
            {
            if (p) { printf("no root, fresh is root...\n"); }
            C->root = fresh;
            C->count = 1;
            if (p)
                {
                printf("root, #%d ",C->count);
                campTreePrintNode(C->root);
                }
                
            return 0;
            }
        
        else
            {
            C->count++;
            int c = C->count;
            return campTreeAddNode(c, C->root, fresh, p);
            }
        }

    else
        {
        if (p)
            {
            printf("campsite out of range or not available "
                    "those dates, not adding to tree\n");
            }
        free(fresh);
        return 0;
        }

    return 1;
    }
