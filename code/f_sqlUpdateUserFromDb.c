// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlUpdateUserFromDb.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *user, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlUpdateUserFromDb (sqlite3* db, struct userData* user, int p)
    {

    char * zErrMsg = 0;
    int rc;
    
    char* l = calloc(50, sizeof(char));
    strcpy(l, user->userLocation);
    //wrapField(l);

    char cmd[1024] = "";
    strcpy(cmd, "SELECT * FROM userlocs "
                "WHERE userLocation = ");
    strcat(cmd, tick);
    strcat(cmd, l);
    strcat(cmd, tick);
    strcat(cmd,";");

    free(l);

    if (p) { printf("sql stmt is: %s\t%ld\n",cmd,strlen(cmd)); }
    if (p) { printf("pulling current coded user..."); }
    
    rc = sqlite3_exec(db, cmd, callback, user, &zErrMsg);
    
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
    //getchar();
    return rc;
    }


static int callback(void *user, int argc, char **argv, 
                    char **azColName)
    {
    struct userData* user2 = user;
    user2->u_lat = atof(argv[1]);
    user2->u_long = atof(argv[2]);
    return 0;
    }


