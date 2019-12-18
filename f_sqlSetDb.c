// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlSetDb.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlSetDb(sqlite3 * db, int p)
    {
    if (p) { printf("setting db parameters..."); }

    //int status = 0;
    //status = system("./sqlite3 test.db .headers on");
    //status = system("./sqlite3 test.db .mode column");
    //if (p) { printf("system call status is %d\n",status); }

    char * zErrMsg = 0;
    int rc;
    char cmd[100];
    strcpy(cmd, ".headers on; .mode column;");
    // this turns on headers and changes output style to column
    // in the SQLite database

    rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }
    else { printf("db settings updated successfully\n"); }
    
    if (p) { printf("rc = %d\n",rc); }
    
    return rc;
    }


static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName)
    {
    int i;
    for(i=0; i<argc; i++)
        {
        printf("%s = %s\n",azColName[i], argv[i] ? argv[i] : "NULL");
        }
    printf("\n");
    return 0;
    }
