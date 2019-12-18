// Chad Tolleson Copyright (c) 2018
// test file for SQLite

// attribution: https://sqlite.org/quickstart.html

#include <stdio.h>
#include <sqlite3.h>
#include "sqlstmts.h"

// function prototype
void sql_stmts(char * sql);
void sql1(sqlite3 * db, char * zErrMsg, int rc);


// function prototype callback must be in main
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);

// main program
int main()
    {
    sqlite3 * db;
    char * zErrMsg = 0;
    int rc;
    char * dbname = "test.db";
    
    // Opening the SQLite database
    rc = sqlite3_open(dbname, &db);
    
    if (rc)
        {
        fprintf(stderr, "Can't open db: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
        }
    else { printf("opening database...\n"); }
    printf("rc = %d\n",rc);
    
    
    // make database tables
    printf("making tables...\n");
    rc = sqlite3_exec(db, maketables, callback, 0, &zErrMsg);
    printf("rc = %d\n",rc);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }



    // close database
    printf("closing database...\n");
    sqlite3_close(db);
    printf("rc = %d\n",rc);
    return 0;
    }

// key definition for SQLite3 callback function, do not move
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName)
    {
    int i;
    for(i=0; i<argc; i++)
        {
        printf("%s=%s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
    printf("\n");
    return 0;
    }
