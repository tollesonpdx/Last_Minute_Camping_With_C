// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlOpenMakeDb.c

#include "headers.h"

// function definition
sqlite3 * sqlOpenMakeDb(char * dbname, int p)
    {
    sqlite3 * db;
    int rc = sqlite3_open(dbname, &db);

    if (p) { printf("opening database %s\n", dbname); }
    
    if (rc)
        {
        fprintf(stderr, "Can't open db: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return NULL;
        //return(1);
        }

    if (p) { printf("rc = %d\n",rc); }
    
    return db;
    }

