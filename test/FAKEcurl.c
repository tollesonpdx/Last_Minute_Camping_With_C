// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: FAKEcurl.c

// this file is used to test the cJSON features
// without actually curling data from Google API

#include "headers.h"


buffer FAKEcurl()
    {
    int p = 1;
    if (p) printf("fake CURLing\n");

    // open and read file into a buffer
    FILE* f1 = fopen("sampleJSON.txt","r");
    fseek(f1, 0, SEEK_END);
    long fsize = ftell(f1);
    fseek(f1, 0, SEEK_SET);  /* same as rewind(f); */
    
    if (p) printf("creating buffer\n");
    buffer b;
    bufferInit(&b);

    b.len = fsize+1;
    if (p) printf("reallocating buffer info\n");
    b.info = realloc(b.info, b.len);
    if (p) printf("freading into b info\n");
    fread(&b.info, fsize, 1, f1);
    if (p) printf("setting ending character to 0\n");
    b.info[b.len] = '\0';

    // print curl results from buffer
    if (p) printf("printing buffer stuff\n");
    if (p)
        {
        printf("buffer data:\n");
        for (int i = 0; i < b.len; i++)
            { printf("%c",b.info[i]); }
        printf("\n");
        }

    fclose(f1);
    return b;
    }
