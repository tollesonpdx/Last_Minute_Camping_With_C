// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeTravPrint.c

#include "headers.h"

int campTreeTravPrint(struct campground* node, int p)
    {
    // go left
    if (node->left != NULL)
        { campTreeTravPrint(node->left, p); }
    
    // process current
    if (p)
        { campTreePrintNode(node); }

    // go right
    if (node->right != NULL)
        { campTreeTravPrint(node->right, p); }

    return 0;
    }
