// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: headers.h

#ifndef __HEADERS_H_
#define __HEADERS_H_

// included libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sqlite3.h>
#include <curl/curl.h>

#include "structs.h"
#include "sqlstmts.h"
#include "cJSON.h"

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define tick "'\0"

//// function prototypes ////

// user data functions
struct userData * getUserData();
void printUserData(struct userData * user);
void geocodeUser(userData* user, int p);

// system time and date
int displayCurrentDateTime();
char* returnCurrentDateTime();

void chadcat(char* a, char* b);
void wrapField(char* a);// wraps with ' needed for SQL stmts
char* convertAddress2G(char* address);
char* doubleToString(double dubs);
double haversine(double lat1, double lng1, double lat2, double lng2);
void logEntry(char* filename);

// database functions
sqlite3 * sqlOpenMakeDb(char * dbname, int p);
int sqlSetDb(sqlite3 * db, int p);
// int sqlExec(sqlite3 * db); // SQLite function archetype
int sqlMakeTables(sqlite3* db, int p);
int sqlInsertUser(sqlite3* db, struct userData* user, int p);
int sqlUsersWOutGeo(sqlite3* db, struct userList* L, int p);
int sqlUpdateUsrCoords(sqlite3* db, char* location, double ulat, double ulng, int p);
int sqlUpdateUserFromDb(sqlite3* db, userData* user, int p);
int sqlCampsFromDb (sqlite3* db, struct campTree* C, int p);
int sqlUpdateCampDist(sqlite3* db, double lat, double lng, char* name, double distance, double uLat, double uLng, int p);
int sqlClearCampDist(sqlite3* db, int p);

// curl functions
buffer* bufferInit(); // initialize the buffer
size_t bufferWrite(void *info, size_t size, size_t nmemb, buffer *buff); // function used for writing to a buffer
buffer* curlGeocode(char* address, int p);
buffer* curlWeathers(double cLat, double cLng, int p);

// JSON parsing functions
double* parseCoords(char* string, int p);
char* parseWeathers(char* string, int p);

// user linked list functions
struct userList* userListMake(int p);
int userListAdd(struct userList* L, char* loc, double* coords, int p);
int userListPrint(struct userList* L);
int userListDelete(struct userList* L, int p);
int userListTravGeo(struct userList* L, sqlite3* db, int p);

// campground linked list functions
struct campTree* campTreeMake(double uLat, double uLng, double maxDriveD, int p);
int campTreeAdd(struct campTree* C, double lng, double lat, char* name, char* code, int p);
int campTreeAddNode(int c, struct campground* current, struct campground* fresh, int p);
int campTreePrintNode(struct campground* node);
int campTreeLogNode(struct campground* node);
int campTreePrint(struct campTree* C, int p);
int campTreeTravPrint(struct campground* node, int p);
int campTreeDelete(struct campTree* C, int p);
int campTreeDeleteNode(struct campground* node, int p);
int campTreeProcess(struct campTree* C, sqlite3* db, int p);
int campTreeTravProc(struct campground* node, struct campTree* C, sqlite3* db, int p);

// attributions:
// https://sqlite.org
// https://en.wikipedia.org/wiki/C_date_and_time_functions
// https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811 USER paxdiablo
// syntax for reading in date values obtained from user Hopeless Noob on this page: https://stackoverflow.com/questions/25956444/c-using-scanf-or-any-other-function-to-get-date-mm-dd-yyyy-in-int
// https://curl.haxx.se/libcurl/c/getinmemory.html
// https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string USER Alex Jasmin
// https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811 USER paxdiablo
// http://www.json.org
// https://github.com/DaveGamble/cJSON
// http://developer.active.com/
// http://www.uscampgrounds.info/ - list of campsites in US & CA
// https://en.wikipedia.org/wiki/Haversine_formula#The_haversine_formula
// https://www.vcalc.com/wiki/vCalc/Haversine+-+Distance
// https://www.weather.gov/documentation/
// Falchi, Fabio; Cinzano, Pierantonio; Duriscoe, Dan; Kyba, Christopher C. M.; Elvidge, Christopher D.; Baugh, Kimberly; Portnov, Boris; Rybnikova, Nataliya A.; Furgoni, Riccardo (2016): Supplement to: The New World Atlas of Artificial Night Sky Brightness. GFZ Data Services. http://doi.org/10.5880/GFZ.1.4.2016.001

#endif 
