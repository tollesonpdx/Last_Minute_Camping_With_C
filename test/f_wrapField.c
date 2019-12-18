// Chad Tolleson Copyright (c) 2019
// New Beginnings 2018 - Capstone Project
// filename: f_wrapField.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* wrapField(char* a)
    {
    printf("in wrap function\n");
    int lena = strlen(a);
    char* b = calloc(lena+2, sizeof(char));
    strcat(b,"'");
    strcat(b, a);
    strcat(b, "'");
    printf("%s\t%ld\n",b,strlen(b));
    return b;
    }

