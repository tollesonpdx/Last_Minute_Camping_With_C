// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_userListTravGeo.c

#include "headers.h"

int userListTravGeo(struct userList* L, sqlite3* db, int p)
    {
    if (p) { printf("traversing user list to update db "
                    "geocodes...\n"); }
    
    if (L->head == NULL)
        {
        if (p) { printf("no head, returning...\n"); }
        return 0;
        }

    struct userData* current = L->head;
    int tempcount = 0;

    while (current != NULL)
        {
        tempcount++;
        if (p) 
            {
            printf("#%d location: %s\tlat,lng: %lf, %lf\n",
            tempcount,current->userLocation, current->u_lat, 
            current->u_long);
            }
        sqlUpdateUsrCoords(db, current->userLocation,
            current->u_lat, current->u_long, p);
        current = current->next;
        }

    if (p) { printf("...finished traversing list\n"); }
    return 0;
    }
