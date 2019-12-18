// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlClearCampDist.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlClearCampDist(sqlite3* db, int p)
    {
    if (p) { printf("inside sqlClearCampDist...\n"); }
    char * zErrMsg = 0;
    int rc = 0;

    // update cmd to include the newly calculated distance
    char cmd[50] = "UPDATE camps SET c_dist_user = NULL;";

    if (p) { printf("sql stmt is: %s\t%ld\n",cmd,strlen(cmd)); }

    if (p) { printf("clearing campground distance from user...");}
    
    rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }
    else
        {
        if (p) { printf("update successful\n"); }
        }

    if (p) printf("rc = %d\n",rc);
    
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

