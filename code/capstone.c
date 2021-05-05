// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: capstone.c

#include "headers.h"

int main()
    {
    int p = 0; // flag for verbose printing
    if (p) displayCurrentDateTime();

    //obtain and display user provided data
    struct userData* user = getUserData();
    if (p) printUserData(user);
    //geocodeUser(user, p); // geocode user location before db

    // create new activity & results log entry
    logEntry("capstoneResultsLog.txt");

    // open database
    char dbname[] = "tollesonCapstone.db";
    int rc = 0; //database error tracking return code
    sqlite3* db = sqlOpenMakeDb(dbname, p);

    //sqlSetDb(db, p); // db settings
    rc = sqlMakeTables(db, p); // generate tables in the db
    rc = sqlInsertUser(db, user, p); // insert user data into db

    // create a linked list to hold users without geocodes
    struct userList* L = userListMake(p); 
    
    // geocode users in the linked list from above
    rc = sqlUsersWOutGeo(db, L, p);
    
    // print out the linked list of user locations
    if (p) { userListPrint(L); }

    // update db with newly obtained geocodes
    userListTravGeo(L, db, p);
    
    // update current user with geocodes
    sqlUpdateUserFromDb(db, user, p);
    
    // create binary search tree to hold campsites for
    // further analysis
    struct campTree* C = campTreeMake(user->u_lat, user->u_long,
                                      user->maxDriveDist, p); 
    if (0)
        {
        printf("Press enter to continue.");
        getchar();
        }

    // pull all campsites from database
    rc = sqlCampsFromDb (db, C, p);
    if (p) { printf("campground count after db pull = %d\n",
                    C->count); }

    // update database with campsites' distance from user
    // and pull additional campsite information from 3rd parties
    campTreeProcess(C, db, p);
    if (p) { printf("campground count after traversal = %d\n",
                    C->count); }

    if (p) printUserData(user);

    // close db and files, and cleanup malloc'd resources
    if (p) 
        {
        printf("rc = %d\n",rc);
        printf("freeing dynamic memory, and "
                "closing database %s\n", dbname);
        }

    rc = sqlClearCampDist(db, p); // clear temp data from db
    free(user); // free memory from user data struct
    userListDelete(L, p); // delete entire user linked list
    free(L); // free memory for user linked list
    campTreeDelete(C, p); // delete entire campground BST
    free(C); // free memory for camground tree
    sqlite3_close(db); // properly close the database connection

    if (p) { printf("program complete\n"); }

    return 0;
    }
