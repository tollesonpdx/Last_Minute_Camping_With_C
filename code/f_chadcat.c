// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_logEntry.c

#include "headers.h"

void chadcat(char* a, char* b)
    {
    int lena = strlen(a);
    int lenb = strlen(b);
    int newlen = lena + lenb + 3;
    a = realloc(a, (newlen * sizeof(char)));
    strcat(a, b);
    return;
    }

