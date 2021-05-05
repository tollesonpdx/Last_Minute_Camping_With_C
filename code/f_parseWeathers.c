// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_parseWeathers.c

#include "headers.h"

char* parseWeathers(char* string, int p)
    {

    // create cJSON object
    cJSON* json = cJSON_Parse(string);
    if (json == NULL)
        {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            { fprintf(stderr,"Error before: %s\n", error_ptr); }
        }

    if (p)
        {
        char* p_json = cJSON_Print(json); 
        printf("json detail:\n%s\n\n",p_json);
        if (p_json) free(p_json);
        p_json = NULL;
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
        p_properties = NULL;
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
        printf("periods detail:\n%s\n\n",p_periods);
        if (p_periods) free(p_periods);
        p_periods = NULL;
        }



    cJSON* per = periods->child;
    if (p)
        {
        if (cJSON_IsObject(per))
            printf("per is an object\n");
        if (cJSON_IsArray(per))
            printf("per is an array\n");
        char* p_per = cJSON_Print(per);
        printf("per detail: \n%s\n", p_per);
        if(p_per) free(p_per);
        p_per = NULL;
        }
            

    char* forecasts = calloc(1, sizeof(char));
    //forecasts[0] = '\0';
    cJSON* name = NULL;
    cJSON* detail = NULL;
    char* p_name = NULL;
    char* p_detail = NULL;
    int newlen = 0;

    while (per)
        {
        name = cJSON_GetObjectItemCaseSensitive(per,"name");
        detail = cJSON_GetObjectItemCaseSensitive(per,
                                    "detailedForecast");
        p_name = cJSON_Print(name);
        p_detail = cJSON_Print(detail);
        newlen = strlen(forecasts) + 1 + strlen(p_name) 
                    + 2 + strlen(p_detail) + 3;
        //printf("new len = %d\n",newlen);
        forecasts = realloc(forecasts, newlen);
        strcat(forecasts, "\n");
        strcat(forecasts, p_name);
        strcat(forecasts, ": ");
        strcat(forecasts, p_detail);
        //forecasts[newlen] = '\0';
        
        if (p_name) free(p_name);
        if (p_detail) free(p_detail);
        name = NULL;
        detail = NULL;
        p_name = NULL;
        p_detail = NULL;

        per = per->next;
        }

    for (int i = 0; i < newlen; i++)
        {
        if (forecasts[i] == '"')
            { forecasts[i] = ' '; }
        }

    // cleanup cJSON object and free alloc'd memory
    cJSON_Delete(json);
    
    return forecasts;
    }
