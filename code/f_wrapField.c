// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_wrapField.c

#include "headers.h"

void wrapField(char* a)
    {
    int lena = strlen(a);
    int lenb = lena + 3;
    char* b = calloc(lenb, sizeof(char));
    strcpy(b,tick);
    strcat(b, a);
    strcat(b,tick);
    a = realloc(a, lenb);
    strcpy(a, b);
    free(b);
    return;
    }

