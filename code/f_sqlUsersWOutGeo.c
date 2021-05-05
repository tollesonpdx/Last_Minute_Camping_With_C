// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlUsersWOutGeo.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *L, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlUsersWOutGeo(sqlite3* db, struct userList* L, int p)
    {
    char * zErrMsg = 0;
    int rc;
    char * cmd = "SELECT * FROM userlocs "
                "WHERE userlat IS NULL "
                "OR userlat = 0";

    if (p) { printf("pulling users without geocodes..."); }
    
    rc = sqlite3_exec(db, cmd, callback, L, &zErrMsg);
    
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


static int callback(void *L, int argc, char **argv, 
                    char **azColName)
    {
    // casting the void pointer as userList struct to pull
    // in the verbose printing variable set in main
    struct userList* L2 = L;
    int p = L2->p;

    int i = 0; // set column to userLocation field
    if (argv[i])
        {
        if (p) { printf("db record %s = %s\n",
                azColName[i], argv[i]); }
        char* add = convertAddress2G(argv[i]);
        if (p) { printf("converted address =  %s\n",add); }
        buffer* buff = curlGeocode(add,p);
        double* coords = parseCoords(buff->info,p);
        userListAdd(L, argv[i], coords, p);
        free(buff->info);
        free(buff);
        if (p) { printf("buffer created\n"); }
        }
    return 0;
    }

