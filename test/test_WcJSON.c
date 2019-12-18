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
char* parseWeathers(char* string, int p);

int main()
    {
    printf("testing cJSON\n");
    int p = 1;

    // open and read file into a buffer
    FILE* f1 = fopen("sampleWeatherJSON.txt","r");
    fseek(f1, 0, SEEK_END);
    long fsize = ftell(f1);
    fseek(f1, 0, SEEK_SET);  /* same as rewind(f); */

    char* string = malloc(fsize + 1);
    fread(string, fsize, 1, f1);
    string[fsize] = '\0';
    fclose(f1);

    if (p)
        {
        // print out buffer to test for complete read
        for (int i = 0; i<fsize; i++)
            { printf("%c", string[i]); }
        printf("\n");
        }
    
    char* forecasts = parseWeathers(string,p);

    printf("forecasts are %s\n",forecasts);
    
    if (string) free(string);
    if (forecasts) free(forecasts);
    fclose(f1);
    return 0;
    }

char* parseWeathers(char* string, int p)
    {
    // create cJSON object
    cJSON* json = cJSON_Parse(string);
    if (json == NULL)
        {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            { fprintf(stderr, "Error before: %s\n", error_ptr); }
        }

    if (p)
        {
        char* p_json = cJSON_Print(json); 
        printf("json detail:\n%s\n\n\n\n\n",p_json);
        if (p_json) free(p_json);
        }



    cJSON* properties = 
        cJSON_GetObjectItemCaseSensitive(json,"properties");
    
    if (p)
        {
        if (cJSON_IsObject(properties))
            printf("properties is an object\n");
        if (cJSON_IsArray(properties))
            { printf("properties is an array\n"); }

        char* p_properties = cJSON_Print(properties); 
        printf("properties detail:\n%s\n\n",p_properties);
        if (p_properties) free(p_properties);
        }
    


    cJSON* periods = 
        cJSON_GetObjectItemCaseSensitive(properties,"periods");

    if (p)
        {
        if (cJSON_IsObject(periods))
            printf("periods is an object\n");
        if (cJSON_IsArray(periods))
            {
            int count = cJSON_GetArraySize(periods);
            printf("periods is an array of size %d\n",count); 
            }

        char* p_periods = cJSON_Print(periods);
        //printf("periods detail:\n%s\n\n",p_periods);
        if (p_periods) free(p_periods);
        }



    cJSON* per = periods->child;

    char* forecasts = calloc(1, sizeof(char));
    forecasts[0] = '\0';
    cJSON* name = NULL;
    cJSON* detail = NULL;
    char* p_name = NULL;
    char* p_detail = NULL;
    int newlen = 0;

    while (per)
        {
        if (p)
            {
            if (cJSON_IsObject(per))
                printf("per is an object\n");
            if (cJSON_IsArray(per))
                printf("per is an array\n");
            }
            
        name = cJSON_GetObjectItemCaseSensitive(per,"name");
        detail = cJSON_GetObjectItemCaseSensitive(per,
                                    "detailedForecast");
        p_name = cJSON_Print(name);
        p_detail = cJSON_Print(detail);
        newlen = strlen(forecasts) + 1 + strlen(p_name) + 2 + strlen(p_detail) + 2;
        forecasts = realloc(forecasts, newlen);
        strcat(forecasts, "\n");
        strcat(forecasts, p_name);
        strcat(forecasts, ": ");
        strcat(forecasts, p_detail);
        forecasts[newlen] = '\0';
        
        name = NULL;
        detail = NULL;
        p_name = NULL;
        p_detail = NULL;

        if (p)
            {
            char* p_per = cJSON_Print(per);
            printf("per detail: \n%s\n", p_per);
            if(p_per) free(p_per);
            }

        per = per->next;
        }

    for (int i = 0; i < newlen; i++)
        {
        if (forecasts[i] == '"')
            { forecasts[i] = ' '; }
        }

    // cleanup cJSON object and free alloc'd memory
    free(name);
    free(detail);
    free(p_name);
    free(p_detail);
    cJSON_Delete(json);
    
    return forecasts;
    }
