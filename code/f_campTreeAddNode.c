// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeAddNode.c

#include "headers.h"

int campTreeAddNode(int c, struct campground* current, struct campground* fresh, int p)
    {
    
    if (p)
        {
        printf("fresh node in campTreeAddNode");
        //campTreePrintNode(fresh);
        }

    if (fresh->distance <= current->distance)
        {
        if (p) { printf("fresh <= current, inserting left\n"); }
        if (current->left == NULL)
            {
            current->left = fresh;
            if (p) 
                {
                printf("current->left in tree #%d ", c);
                campTreePrintNode(current->left);
                }
            return 0;
            }
        else
            {
            return campTreeAddNode(c, current->left, fresh, p);
            }
        }

    else
        {
        if (p) { printf("fresh > current, inserting right\n"); }
        if (current->right == NULL)
            {
            current->right = fresh;
            if (p) 
                {
                printf("current->right in tree #%d ", c);
                campTreePrintNode(current->right);
                }
            return 0;
            }
        else
            {
            return campTreeAddNode(c, current->right, fresh, p);
            }
        }

    return 1;
    }
