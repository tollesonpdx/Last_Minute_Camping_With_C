// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_campTreeDeleteNode.c

#include "headers.h"

int campTreeDeleteNode(struct campground* node, int p)
    {
    if (p) { printf("deleting campground node..."); }
   
    if (node->left != NULL)
        {
        campTreeDeleteNode(node->left, p);
        free(node->left);
        node->left = NULL;
        }

    if (node->right != NULL)
        {
        campTreeDeleteNode(node->right, p);
        free(node->right);
        node->right = NULL;
        }
 
    free(node->c_weathers);
    node->c_weathers = NULL;

    if (p) { printf("finished deleting node\n"); }
    return 0;
    }
     
