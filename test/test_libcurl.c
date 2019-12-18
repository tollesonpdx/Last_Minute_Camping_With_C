// Chad Tolleson
// curl test
// attribution: https://curl.haxx.se/libcurl/c/getinmemory.html
// attribution: https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string USER Alex Jasmin
// attribution: https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811 USER paxdiablo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// structure definitions
typedef struct buffer
    {
    char *info;
    size_t len;
    } buffer;

// function definitions
void bufferInit(buffer *buff)
    {
    buff->len = 0;
    buff->info = malloc(buff->len+1);
    if (buff->info == NULL)
        {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
        }
    buff->info[0] = '\0';
    }

size_t bufferWrite(void *info, size_t size, size_t nmemb, buffer *buff)
    {
    size_t new_len = buff->len + size*nmemb;
    buff->info = realloc(buff->info, new_len+1);
    if (buff->info == NULL)
        {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
        }
    memcpy (buff->info + buff->len, info, size*nmemb);
    buff->info[new_len] = '\0';
    buff->len = new_len;

    return size*nmemb;
    }


char* wrapField(char* a)
    {
    int lena = strlen(a);
    char* b = calloc(lena, sizeof(char));
    strcat(b,"'");
    strcat(b, a);
    strcat(b, "'");
    //printf("%s\n",b);
    return b;
    }



char * printCurrentDateTime()
    {
    time_t current_time;
    time(&current_time);
    struct tm* tm_info = localtime(&current_time);
    char * timebuffer;
    strftime(timebuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("%s\n",timebuffer);
    return timebuffer;
    }

// main 
int main(void)
    {
    
    // open or create a file for curl results
    FILE * f1 = fopen("libcurltestlog.txt","a+");
    fprintf(f1,"log entry: ");
    fprintf(f1, "%s\n",printCurrentDateTime());

    printf("establishing curl\n");
    CURL *curl = curl_easy_init();
    CURLcode res;
    //struct curl_slist *slist1 = curl_slist_append(slist1, "accept: application/geo+json");

    curl_version_info_data *curl_version_info( CURLversion age );
   
    // create curl command
    char* address = "Rome,+OR";
    char cmd[1024] = "";
    strcpy(cmd,"https://maps.googleapis.com/maps/api/geocode/");
    strcat(cmd,"json?address=");
    strcat(cmd,wrapField(address));
    strcat(cmd,"&key=");
    strcat(cmd,getenv("GMAPIKEY"));

    char* lat = "45.512231";
    char* lng = "-122.658719";
    char cmd2[1024] = "";
    strcpy(cmd2, "https://api.weather.gov/points/");
    strcat(cmd2, lat);
    strcat(cmd2, ",");
    strcat(cmd2, lng);
    strcat(cmd2, "/forecast");

  
    printf("cmd is: %s\n",cmd2);

    // creating buffer to hold curl response
    buffer b;
    bufferInit(&b);

    if(curl)
        {
        printf("establishing setting curl options\n");
        //curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 102400L);
        curl_easy_setopt(curl, CURLOPT_URL, cmd2);
        //curl_easy_setopt(curl, CURLOPT_URL, "https://api.weather.gov/points/45.5122\%2C-122.6587/forecast");
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0); // turn on progress bar
        //curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.58.0");
        //curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 2L);
        //curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        //curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, bufferWrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &b);

        /* Perform the request, res will get the return code */
        printf("performing curl\n");
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        printf("checking for curl errors\n");
        if(res != CURLE_OK)
          fprintf(stderr, "curl_easy_perform() failed: %s\n",
                  curl_easy_strerror(res));

        // print curl results
        printf("b data:\n");
        for (int i = 0; i < b.len; i++)
            { printf("%c",b.info[i]); }
        printf("\n\n\n");
             
        /* always cleanup */
        printf("cleaning up curl\n");
        curl_easy_cleanup(curl);
        }
 
    // write curl results to file
    fprintf(f1, "b data:\n");
    for (int i = 0; i < b.len; i++)
        { fprintf(f1,"%c",b.info[i]); }
    fprintf(f1,"\n");

    // close file
    printf("closing program\n"); 
    fclose(f1);
    return 0;
    }
