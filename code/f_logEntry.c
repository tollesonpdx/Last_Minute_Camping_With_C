// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_logEntry.c

#include "headers.h"

void logEntry(char* filename)
    {
    // create new log entry in log file
    //FILE* f1 = fopen("capstoneResultsLog.txt","a+");
    FILE* f1 = fopen(filename,"a+");
    fprintf(f1,"\n\n\n\n");
    for (int i = 0; i < 65; i++)
        { fprintf(f1,"*"); }
    fprintf(f1,"\n");
    for (int i = 0; i < 65; i++)
        { fprintf(f1,"*"); }
    fprintf(f1,"\nlog entry: ");
    char* t = returnCurrentDateTime();
    fprintf(f1, "%s\n",t);
    if (t) free(t);
    fclose(f1);
    return;
    }

