// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_bufferInit.c

#include "headers.h"

buffer* bufferInit()
    {
    struct buffer* b = malloc(sizeof( struct buffer ));
    b->len = 0;
    b->info = malloc(b->len+1);
    if (b->info == NULL)
        {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
        }
    b->info[0] = '\0';
    return b;
    }

