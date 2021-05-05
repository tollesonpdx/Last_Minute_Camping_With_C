// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_curlGeocode.c

#include "headers.h"

buffer* curlGeocode(char* address, int p)
    {
    if (p) { printf("establishing curl...\n"); }
    CURL* curl = curl_easy_init();
    CURLcode res;
    curl_version_info_data *curl_version_info( CURLversion age );
   
    char* a = calloc(50, sizeof(char));
    strcpy(a, address);
    wrapField(a);

    // create curl command
    char cmd[1024] = "";
    strcpy(cmd,"https://maps.googleapis.com/maps/api/geocode/");
    strcat(cmd,"json?address=");
    strcat(cmd, a);
    strcat(cmd,"&key=");
    strcat(cmd,getenv("GMAPIKEY"));

    free(a);

    //if (p) { printf("cmd = %s\n",cmd); }
    
    // creating buffer to hold curl response
    if (p) { printf("establishing buffer...\n"); }
    buffer* b = bufferInit();
    if (p) { printf("finished establishing buffer\n"); }

    if(curl)
        {
        printf("setting curl options...\n");
        // using cmd from above to set the URL
        curl_easy_setopt(curl, CURLOPT_URL, cmd);
        // telling curl it can be redirected at most 1 times
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        // telling curl to write results to a buffer
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bufferWrite);
        // providing curl with the buffer pointer
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, b);
        
        // turn on progress bar
        if (p) { curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);}

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
