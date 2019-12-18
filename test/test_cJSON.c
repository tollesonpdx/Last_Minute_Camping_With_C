// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: test_cJSON.c

// this file is used to test the cJSON features before
// incorporating into the main capstone project

// attributions
// http://www.json.org/
// https://github.com/DaveGamble/cJSON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

// function prototype
double* parseCoords(char* string, int p);

int main()
    {
    printf("testing cJSON\n");
    int p = 1;

    // open and read file into a buffer
    FILE* f1 = fopen("sampleJSON.txt","r");
    fseek(f1, 0, SEEK_END);
    long fsize = ftell(f1);
    fseek(f1, 0, SEEK_SET);  /* same as rewind(f); */

    char* string = malloc(fsize + 1);
    fread(string, fsize, 1, f1);
    string[fsize] = '\0';

    if (p)
        {
        // print out buffer to test for complete read
        for (int i = 0; i<fsize; i++)
            { printf("%c", string[i]); }
        printf("\n");
        }
    
    double* coords = parseCoords(string,p);
    printf("coords are %lf, %lf\n",coords[0],coords[1]);
    
    if (string) free(string);
    fclose(f1);
    return 0;
    }

double* parseCoords(char* string, int p)
    {
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
    double dlat = lat->valuedouble;

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
    double dlng = lng->valuedouble;

    if (p)
        {
        printf("lat,lng: %lf, %lf\n",dlat,dlng);
        }

    double* coords = calloc(2, sizeof(double));
    coords[0] = dlat;
    coords[1] = dlng;
    
    // cleanup all the junk
    //cJSON_Delete(lng);
    //cJSON_Delete(lat);
    //cJSON_Delete(location);
    //cJSON_Delete(geometry);
    //cJSON_Delete(results2);
    //cJSON_Delete(results);
    cJSON_Delete(json);
    
    return coords;
    }
