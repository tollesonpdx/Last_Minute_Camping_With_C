// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlUpdateUsrCoords.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlUpdateUsrCoords(sqlite3* db, char* location, double ulat, double ulng, int p)
    {
    if (p) { printf("inside sqlUpdateUsrCoords...\n"); }
    char * zErrMsg = 0;
    int rc = 0;

    char* a = doubleToString(ulat);
    wrapField(a);
    char* o = doubleToString(ulng);
    wrapField(o);
    char* l = calloc(50, sizeof(char));
    strcpy(l, location);
    wrapField(l);

    char cmd[1024] = "";
    strcpy(cmd, "UPDATE userlocs SET userlat = ");
    strcat(cmd, a);
    strcat(cmd, ", userlng = ");
    strcat(cmd, o);
    strcat(cmd, " WHERE userLocation = ");
    strcat(cmd, l);
    strcat(cmd, ";");

    free(a);
    free(o);
    free(l);

    printf("sql stmt is: %s\t%ld\n",cmd, strlen(cmd));

    if (p) {printf("updating user location coordinates...");}
    
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

