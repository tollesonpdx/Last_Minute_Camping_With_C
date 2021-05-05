// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_haversine.c

// attribution: https://en.wikipedia.org/wiki/Haversine_formula#The_haversine_formula
// attribution: https://www.vcalc.com/wiki/vCalc/Haversine+-+Distance

#include "headers.h"

double haversine(double lat1, double lng1, double lat2, double lng2)
    {
    // convert coordinates to radians
    lat1 *= (M_PI / 180);
    lng1 *= (M_PI / 180);
    lat2 *= (M_PI / 180);
    lng2 *= (M_PI / 180);

    // calculate the latitude haversine
    double latdiff = (lat2 - lat1);
    double lathavrs = sin(pow((latdiff/2),2));

    // calculate the longitude haversine
    double lngdiff = (lng2 - lng1);
    double lnghavrs = sin(pow((lngdiff/2),2));

    // radius of Earth in kilometers, average of at equator and
    // at north-pole radiuses
    double R = (6356.752 + 6378.137) / 2;
    
    // calculate distance via solving for distant in haversine
    double h = lathavrs + (cos(lat1) * cos(lat2) * lnghavrs);
    h = sqrt(h);
   
    // ensure h stays between 0 and 1 for haversine formula to
    // work properly
    h = min(max(0,h),1);

    double d = 2 * R * asin(h);
   
    // convert distance from kilometers to miles
    d *= 0.62137;
    return d;
    }


