// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_doubleToString.c

#include "headers.h"

char* doubleToString(double dubs)
    {
    char* string = calloc(11, sizeof(char));
    sprintf(string, "%lf", dubs);
    //snprintf(string, 50, "%f", dubs);
    //printf("%s\n",string);
    return string;
    }

