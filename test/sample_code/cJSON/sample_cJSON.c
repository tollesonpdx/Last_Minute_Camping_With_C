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
//#include <cjson/cJSON.h>
#include "cJSON.h"

// function prototypes
char *create_monitor_with_helpers(void);
int supports_full_hd(const char * const monitor);

// main
int main()
    {
    printf("sample cJSON\n");
    char* monbuff = create_monitor_with_helpers();
    printf("%s\n\n\n",monbuff);
    printf("1 or 0?  %d\n",supports_full_hd(monbuff));
    return 0;
    }
    
//NOTE: Returns a heap allocated string, 
//you are required to free it after use.
char *create_monitor_with_helpers(void)
    {
    const unsigned int resolution_numbers[4][2] = 
        {
        {1280, 720},
        {1920, 1080},
        {3840, 2160}
        };

    char *string = NULL;
    cJSON *resolutions = NULL;
    size_t index = 0;

    cJSON *monitor = cJSON_CreateObject();

    if (cJSON_AddStringToObject(monitor,
        "name", "Awesome 4K") == NULL)
        { goto end; }

    resolutions = cJSON_AddArrayToObject(monitor, 
        "resolutions");
    
    if (resolutions == NULL)
        { goto end; }

    for (index = 0; index < (sizeof(resolution_numbers) / 
        (2 * sizeof(int))); ++index)
        {
        cJSON *resolution = cJSON_CreateObject();

        if (cJSON_AddNumberToObject(resolution, 
            "width", resolution_numbers[index][0]) == NULL)
            { goto end; }

        if(cJSON_AddNumberToObject(resolution, "height", 
            resolution_numbers[index][1]) == NULL)
            { goto end; }

        cJSON_AddItemToArray(resolutions, resolution);
        }

    string = cJSON_Print(monitor);
    if (string == NULL) 
        { fprintf(stderr, "Failed to print monitor.\n"); }

    end:
        cJSON_Delete(monitor);
        return string;
    }   

int supports_full_hd(const char * const monitor)
    {
    int status = 0;
    
    cJSON *monitor_json = cJSON_Parse(monitor);
    if (monitor_json == NULL)
        {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            {
            fprintf(stderr, "Error before: %s\n", error_ptr);
            }
        status = 0;
        goto end;
        }

    const cJSON* name = cJSON_GetObjectItemCaseSensitive(
                        monitor_json, "name");
    if (cJSON_IsString(name) && (name->valuestring != NULL))
        {
        printf("Checking monitor \"%s\"\n", name->valuestring);
        }

    const cJSON* resolutions = cJSON_GetObjectItemCaseSensitive(
            monitor_json, "resolutions");
    
    const cJSON *resolution = NULL;
    cJSON_ArrayForEach(resolution, resolutions)
        {
        cJSON *width = cJSON_GetObjectItemCaseSensitive(
                        resolution, "width");
        cJSON *height = cJSON_GetObjectItemCaseSensitive(
                        resolution, "height");

        if (!cJSON_IsNumber(width) || !cJSON_IsNumber(height))
            {
            status = 0;
            goto end;
            }

        if ((width->valuedouble == 1920) && 
                (height->valuedouble == 1080))
            {
            status = 1;
            goto end;
            }
        }

    end:
        cJSON_Delete(monitor_json);
        return status;
    }
