// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlInsertUser.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);

// function definition
int sqlInsertUser(sqlite3 * db, struct userData * user, int p)
    {
    char * zErrMsg = 0;
    int rc;

    char* l = calloc(50, sizeof(char));
    strcpy(l, user->userLocation);
    wrapField(l);
    char* a = (doubleToString(user->u_lat));
    wrapField(a);
    char* o = (doubleToString(user->u_long));
    wrapField(o);

    char cmd[1024];
    strcpy(cmd,"INSERT OR IGNORE INTO userlocs ("
                "userLocation, userlat, userlng) "
                "VALUES (");
    strcat(cmd, l);
    strcat(cmd, ",");
    strcat(cmd, a);
    strcat(cmd, ",");
    strcat(cmd, o);
    strcat(cmd, ");");

    free(l);
    free(a);
    free(o);

    if (p) { printf("sql stmt is: %s\t%ld\n",cmd,strlen(cmd)); }
    
    if (p) { printf("inserting user data..."); }
    
    rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }
    else
        {
        if (p) { printf("user data inserted successfully\n"); }
        }

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

