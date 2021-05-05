// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_convertAddress2G.c

#include "headers.h"

char* convertAddress2G(char* address)
    {
    int len_googAdd = strlen(address)+1;
    char* googAdd = calloc(len_googAdd, sizeof(char));
    strcpy(googAdd, address);
    googAdd[len_googAdd]='\0';
    for (int i = 0; i < len_googAdd; i++)
        {
        if (googAdd[i] == ' ')
            { googAdd[i]='+'; }
        }
    return googAdd;
    }

