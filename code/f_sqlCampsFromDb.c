// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlCampsFromDb.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *C, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlCampsFromDb (sqlite3* db, struct campTree* C, int p)
    {

    char * zErrMsg = 0;
    int rc;
    char cmd[100] = "SELECT c_lng, c_lat, c_name, "
                    "c_campCode, c_dist_user "
                    "FROM camps "
                    "WHERE c_dist_user IS NULL;";

    if (p) { printf("pulling campgrounds from db...\n"); }
    
    rc = sqlite3_exec(db, cmd, callback, C, &zErrMsg);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }
    else
        {
        if (p) { printf("...pulled successfully\n"); }
        }

    if (p) { printf("rc = %d\n",rc); }
    return rc;
    }


static int callback(void *C, int argc, char **argv, 
                    char **azColName)
    {
    // verbose printing value by getting around void pointer
    struct campTree* C2 = C;
    int p = C2->p;

    if (argv[0])
        {
        if (p)
        //if (0) // hard coded to turn off printing
            {
            printf("\n\ndb record: ");
            for (int i = 0; i < 4; i++)
                { 
                printf("%s = %s  ",
                azColName[i], argv[i]);
                }
            printf("\n");
            }
        campTreeAdd(C, atof(argv[0]), atof(argv[1]), 
                    argv[2], argv[3], p);
        }
    return 0;
    }

