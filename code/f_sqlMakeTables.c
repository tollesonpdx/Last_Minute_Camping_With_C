// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_sqlMakeTables.c

#include "headers.h"

// static function prototype
// these need to be included in the related implementation file
// versus a universal header file
static int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);


// function definition
int sqlMakeTables(sqlite3 * db, int p)
    {
    char * zErrMsg = 0;
    int rc;
    char* cmd = "CREATE TABLE IF NOT EXISTS "
            "userlocs("
            "userLocation varchar(1000) unique primary key, "
            "userlat double, "
            "userlng double, "
            "datatype varchar(10)); "
            ""
            "CREATE TABLE IF NOT EXISTS "
            "camps("
            "c_lng double, "
            "c_lat double, "
            "c_GPScomp varchar(500), "
            "c_campCode varchar(10), "
            "c_name varchar(100), "
            "c_type varchar(10), "
            "c_phone varchar(50), "
            "c_datesOpen varchar(50), "
            "c_comments varchar(100), "
            "c_numCampsites int, "
            "c_elevation int, "
            "c_amenities varchar(50), "
            "c_state varchar(10), "
            "c_distanceTown double, "
            "c_bearingTown varchar(10), "
            "c_nearestTown varchar(50), "
            "c_orgFile varchar(20), "
            "c_dist_user double, "
            "c_available bool, "
            "datatype varchar(10));"
            ""
            "CREATE TABLE IF NOT EXISTS "
            "distances("
            "userlat double, "
            "userlng double, "
            "c_lat double, "
            "c_lng double, "
            "c_dist_user double, "
            "UNIQUE(userlat, userlng, c_lat, c_lng)"
            ");"
            ""
            "CREATE TABLE IF NOT EXISTS "
            "weathers("
            "wid int primary key, "
            "wname varchar(1000), "
            "wlat double, "
            "wlong double, "
            "wforecast int, "
            "datatype varchar(10)); "
            ""
            "CREATE TABLE IF NOT EXISTS "
            "lightpol("
            "pid int primary key,"
            "pname varchar(100), "
            "plat double, "
            "plong double, "
            "pollut int, "
            "datatype varchar(10));"
            ""
            "CREATE TABLE IF NOT EXISTS "
            "astro("
            "aid int primary key, "
            "astrodesc varchar(1000), "
            "astroBdate varchar(100), "
            "astroEdate varchar(100), "
            "datatype varchar(10));"
            "";
    
    if (p) { printf("generating tables..."); }

    rc = sqlite3_exec(db, cmd, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK )
        {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        }
    else
        {
        if (p) { printf("tables generated successfully\n"); }
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

