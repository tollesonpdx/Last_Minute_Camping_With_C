// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeDelete.c

#include "headers.h"

int campTreeDelete(struct campTree* C, int p)
    {
    if (p) { printf("deleting campground tree..."); }
    
    if (C->root == NULL)
        {
        if (p) { printf("no root, returning...\n"); }
        return 0;
        }

    campTreeDeleteNode(C->root, p);
    free(C->root);
    C->root = NULL;

    if (p) { printf("finished deleting tree\n"); }
    return 0;
    }
     
