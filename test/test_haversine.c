// Chad Tolleson
// testing of haversine formula
// filename: test_haversine.c

// attribution: https://en.wikipedia.org/wiki/Haversine_formula#The_haversine_formula
// attribution: https://www.vcalc.com/wiki/vCalc/Haversine+-+Distance


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

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

int main()
    {
    double ptA[2] = { 41.507483, -99.436554 };
    double ptB[2] = { 38.504048, -98.315949 };
    double test = 347.32883869;
    double dist = haversine(ptA[0], ptA[1], ptB[0], ptB[1]);
    
    printf("Nebraska: %lf, %lf\n", ptA[0], ptA[1]);
    printf("Kansas: %lf, %lf\n", ptB[0], ptB[1]);

    printf("my haversine distance is %lf\n",dist);
    printf("actual haversine distance is %lf\n",test);
    dist == test ? printf("PASS\n") : printf("FAIL\n"); 
    return 0;
    }
