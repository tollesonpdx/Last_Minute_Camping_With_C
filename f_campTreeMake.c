// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_makeCampTree.c

#include "headers.h"

struct campTree* campTreeMake(double uLat, double uLng, double maxDriveD, int p)
    {
    if (p) { printf("creating tree of campgrounds..."); }
    struct campTree* C = malloc(sizeof(struct campTree));
    C->root = NULL;
    C->userLat = uLat;
    C->userLng = uLng;
    C->maxDriveDist = maxDriveD;
    C->p = p;
    C->count = 0;
    if (p) { printf("tree created successfully\n"); }
    return C;
    }

