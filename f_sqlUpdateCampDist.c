// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlUpdateCampDist.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlUpdateCampDist(sqlite3* db, double lat, double lng, char* name, double distance, double uLat, double uLng, int p)
    {
    if (p) { printf("inside sqlUpdateCampDist...\n"); }
    char * zErrMsg = 0;
    int rc = 0;

    char* ua = doubleToString(uLat);
    wrapField(ua);
    char* ul = doubleToString(uLng);
    wrapField(ul);
    char* c = doubleToString(distance);
    wrapField(c);
    char* a = doubleToString(lat);
    wrapField(a);
    char* o = doubleToString(lng);
    wrapField(o);
    int lenname = strlen(name);
    char* n = calloc(lenname+3, sizeof(char));
    strcpy(n, name);
    wrapField(n);

    char cmd[1024] = "";
    strcpy(cmd, "UPDATE camps SET c_dist_user = ");
    strcat(cmd, c);
    strcat(cmd, " WHERE c_name = ");
    strcat(cmd, n);
    strcat(cmd, " AND c_lat = ");
    strcat(cmd, a);
    strcat(cmd, " AND c_lng = ");
    strcat(cmd, o);
    strcat(cmd, ";");
    strcat(cmd, " INSERT OR IGNORE INTO distances(");
    strcat(cmd, "userlat, userlng, c_lat, c_lng, "
                "c_dist_user) ");
    strcat(cmd, "VALUES(");
    strcat(cmd, ua);
    strcat(cmd, ", ");
    strcat(cmd, ul);
    strcat(cmd, ", ");
    strcat(cmd, a);
    strcat(cmd, ", ");
    strcat(cmd, o);
    strcat(cmd, ", ");
    strcat(cmd, c);
    strcat(cmd, ");");
    
    free(ua);
    free(ul);
    free(c);
    free(a);
    free(o);
    free(n);

    if (p) { printf("sql stmt is: %s\t%ld\n",cmd,strlen(cmd)); }

    if (p) { printf("updating campground distance from user...");}
    
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

