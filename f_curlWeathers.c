// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_curlWeathers.c

#include "headers.h"

buffer* curlWeathers(double cLat, double cLng, int p)
    {
    if (p) { printf("establishing curl...\n"); }
    CURL* curl = curl_easy_init();
    CURLcode res;
    curl_version_info_data *curl_version_info(CURLversion age);
   
    char* ca = doubleToString(cLat);
    char* co = doubleToString(cLng);

    // create curl command
    char cmd[1024] = "";
    strcpy(cmd, "https://api.weather.gov/points/");
    strcat(cmd, ca);
    strcat(cmd, ",");
    strcat(cmd, co);
    strcat(cmd, "/forecast");

    free(ca);
    free(co);

    if (p) { printf("cmd = %s   %ld\n",cmd,strlen(cmd)); }
    
    // creating buffer to hold curl response
    if (p) { printf("establishing buffer...\n"); }
    buffer* b = bufferInit();
    if (p) { printf("finished establishing buffer\n"); }

    if(curl)
        {
        if (p) { printf("setting curl options...\n"); }
        curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
        curl_easy_setopt(curl, CURLOPT_URL, cmd);
        if (1) { curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);}
        curl_easy_setopt(curl, CURLOPT_USERAGENT,"curl/7.58.0");
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 2L);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bufferWrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, b);
        

        if (p) { printf("performing curl...\n"); }
        
        // res gets the return code
        res = curl_easy_perform(curl);
        
        // check for errors
        if (p) { printf("checking for curl errors...\n"); }
        if(res != CURLE_OK)
          fprintf(stderr, "curl_easy_perform() failed: %s\n",
                  curl_easy_strerror(res));

        // print curl results from buffer
        if (p)
            {
            printf("buffer data:\n");
            for (int i = 0; i < b->len; i++)
                { printf("%c",b->info[i]); }
            printf("\n");
            }
        
        // cleanup
        if (p) { printf("cleaning up curl...\n"); }
        curl_easy_cleanup(curl);
        }
  
    return b;
    }
