// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_parseCoords.c

#include "headers.h"

double* parseCoords(char* string, int p)
    {
    double* coords = calloc(2, sizeof(double));

    // create cJSON object
    cJSON* json = cJSON_Parse(string);
    if (json == NULL)
        {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            {
            fprintf(stderr, "Error before: %s\n", error_ptr);
            }
        }
    if (p)
        {
        char* p_json = cJSON_Print(json); 
        printf("json detail:\n%s\n\n\n\n\n",p_json);
        if (p_json) free(p_json);
        }

    if (p)
        {
        cJSON* status = cJSON_GetObjectItemCaseSensitive(json,"status");
        printf("status: %s is %s\n",status->string, status->valuestring);
        cJSON_Delete(status);
        }

    cJSON* results = cJSON_GetObjectItemCaseSensitive(json,"results");
    if (p)
        {
        if (cJSON_IsObject(results)) printf("results is an object\n");
        if (cJSON_IsArray(results)) printf("results is an array\n"); 
        char* p_results = cJSON_Print(results); 
        printf("results detail:\n%s\n\n\n\n\n",p_results);
        if (p_results) free(p_results);
        }
        
    cJSON* results2 = results->child;
    if (p)
        {
        if (cJSON_IsArray(results2)) { printf("results2 is an array\n"); }
        if (cJSON_IsObject(results2)) { printf("results2 is an object\n"); }
        char* p_results2 = cJSON_Print(results2);
        printf("results2 detail:\n%s\n\n\n\n\n",p_results2);
        if (p_results2) free(p_results2); 
        }

    cJSON* geometry = cJSON_GetObjectItemCaseSensitive(results2,"geometry");
    if (p)
        {
        if (cJSON_IsArray(geometry)) { printf("geometry is an array\n"); }
        if (cJSON_IsObject(geometry)) { printf("geometry is an object\n"); }
        char* p_geometry = cJSON_Print(geometry);
        printf("geometry detail:\n%s\n\n\n\n\n",p_geometry);
        if (p_geometry) free(p_geometry); 
        }

    cJSON* location = cJSON_GetObjectItemCaseSensitive(geometry,"location");
    if (p)
        {
        if (cJSON_IsArray(location)) { printf("location is an array\n"); }
        if (cJSON_IsObject(location)) { printf("location is an object\n"); }
        char* p_location = cJSON_Print(location);
        printf("location detail:\n%s\n\n\n\n\n",p_location);
        if (p_location) free(p_location);
        }

    cJSON* lat = cJSON_GetObjectItemCaseSensitive(location,"lat");
    if (p)
        {
        if (cJSON_IsArray(lat)) { printf("lat is an array\n"); }
        if (cJSON_IsObject(lat)) { printf("lat is an object\n"); }
        if (cJSON_IsNumber(lat)) { printf("lat is a number\n"); }
        char* p_lat = cJSON_Print(lat);
        printf("lat detail:\n%s\n\n\n\n\n",p_lat);
        if (p_lat) free(p_lat);
        }
    coords[0] = lat->valuedouble;

    cJSON* lng = cJSON_GetObjectItemCaseSensitive(location,"lng");
    if (p)
        {
        if (cJSON_IsArray(lng)) { printf("lng is an array\n"); }
        if (cJSON_IsObject(lng)) { printf("lng is an object\n"); }
        if (cJSON_IsNumber(lng)) { printf("lng is a number\n"); }
        char* p_lng = cJSON_Print(lng);
        printf("lng detail:\n%s\n\n\n\n\n",p_lng);
        if (p_lng) free(p_lng);
        }
    coords[1] = lng->valuedouble;

    if (p)
        {
        printf("lat,lng: %lf, %lf\n",coords[0],coords[1]);
        }

    // cleanup all the junk - running these Delete functions
    // caused segmentation faults in the entire program
    //cJSON_Delete(lng);
    //cJSON_Delete(lat);
    //cJSON_Delete(location);
    //cJSON_Delete(geometry);
    //cJSON_Delete(results2);
    //cJSON_Delete(results);
    //cJSON_Delete(json);
    
    return coords;
    }

