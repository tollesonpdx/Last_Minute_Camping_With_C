// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_bufferWrite.c

#include "headers.h"

size_t bufferWrite(void *info, size_t size, size_t nmemb, buffer *buff)
    {
    size_t new_len = buff->len + size*nmemb;
    buff->info = realloc(buff->info, new_len+1);
    if (buff->info == NULL)
        {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
        }
    memcpy (buff->info + buff->len, info, size*nmemb);
    buff->info[new_len] = '\0';
    buff->len = new_len;

    return size*nmemb;
    }
    
