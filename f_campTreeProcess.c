// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeProcess.c

#include "headers.h"

int campTreeProcess(struct campTree* C, sqlite3* db, int p)
    {
    if (p) { printf("traversing campground tree to update db "
                    "distances from user and pull additional "
                    "data from 3rd parties...\n"); }
    
    if (C->root == NULL)
        {
        if (p) { printf("no root, returning...\n"); }
        return 0;
        }

    if (p) { printf("before calling traversal function\n"); }
    campTreeTravProc(C->root, C, db, p);

    if (p) { printf("...finished traversing list\n"); }
    return 0;
    }
