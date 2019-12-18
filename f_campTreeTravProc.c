// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeTravProc.c

#include "headers.h"

int campTreeTravProc(struct campground* node, struct campTree* C, sqlite3* db, int p)
    {
    if (p) { printf("inside campTreeTravProc function\n"); }

    // go left
    if (node->left != NULL)
        { campTreeTravProc(node->left, C, db, p); }
    
    // process current
    
        buffer* buff = curlWeathers(node->c_lat,node->c_long,p);
        
        node->c_weathers = parseWeathers(buff->info,p);
        if (p)
            {
            printf("weather forecast:\n%s\n",node->c_weathers);
            }
        free(buff->info);
        free(buff);

        sqlUpdateCampDist(db, node->c_lat, node->c_long,
                      node->c_name, node->distance, 
                      C->userLat, C->userLng, p);

        // print results of program here
        if (1)
            {
            campTreePrintNode(node);
            campTreeLogNode(node);
            }

    // end of current processing

    // go right
    if (node->right != NULL)
        { campTreeTravProc(node->right, C, db, p); }

    return 0;
    }
    
