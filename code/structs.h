// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: structs.h

#ifndef __STRUCTS_H_
#define __STRUCTS_H_

// structure definitions

typedef struct userData
    {
    char userLocation[1000];
    struct tm begDate; // beginning date
    struct tm endDate; // ending date
    double maxDriveTime; // maximum driving time
    double maxDriveDist; // time * avg 60mph
    double u_lat; // user's latitude
    double u_long; // user's longitude
    struct userData* next; // pointer to next item in linked list
    } userData;

typedef struct userList
    {   
    struct userData* head; // the linked list head
    struct userData* tail; // the linked list tail
    int count; // tracks number of nodes in list
    int p; // verbose printing variable
    } userList;

typedef struct campground
    {
    char c_code[100];
    char c_name[1000];
    char c_address[1000];
    double c_lat;
    double c_long;
    double distance;
    bool c_available; // bool status of campground's availability
    char* c_weathers; // long string of weather forecast info
    struct campground* left; // pointer to lesser item in tree
    struct campground* right; // pointer to greater item in tree
    } campground;

typedef struct campTree
    {
    struct campground* root; // the binary search tree root
    double userLat; // bring user coords into List for
    double userLng; // haversine calculations
    double maxDriveDist; // user maximum driving distance
    int count; // tracks number of nodes in list
    int p; // verbose printing variable
    } campTree;

typedef struct weatherForecast
    {
    int w_id;
    char w_name[1000]; // weather station name
    double w_lat;
    double w_long;
    int w_forecast; // integer value of weather conditions 
                    // on scale from 1 to 100 
    } weatherForecast;

typedef struct lightPollution
    {
    int p_id;
    char p_name[1000]; // light pollution monitoring station name
    double p_lat;
    double p_long;
    int p_poll; // rating of light pollution from 1 to 100
    } lightPollution;

typedef struct astro
    {
    int a_id;
    char a_desc[1000]; // description of astronomical event
    int a_begDate; // beginning date of astronimcal event
    int a_endDate; // ending date of astronomical event
    } astro;


// buffer for curl results
typedef struct buffer
    {
    char *info;
    size_t len;
    } buffer;

#endif 
