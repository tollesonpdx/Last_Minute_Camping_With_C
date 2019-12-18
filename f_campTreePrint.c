// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreePrint.c

#include "headers.h"

int campTreePrint(struct campTree* C, int p)
    {
    if (p) { printf("printing campground tree...\n"); }
    
    if (C->root == NULL)
        {
        printf("no root, returning...\n");
        return 0;
        }

    campTreeTravPrint(C->root, p);   

    if (p) { printf("...finished printing tree\n"); }
    return 0;
    }
