// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_printUserList.c

#include "headers.h"

int userListPrint(struct userList* L)
    {
    printf("printing user list...\n");
    
    if (L->head == NULL)
        {
        printf("no head, returning...\n");
        return 0;
        }

    struct userData* current = L->head;
    int tempcount = 0;

    while (current != NULL)
        {
        tempcount++;
        printf("#%d location: %s\tlat,lng: %lf, %lf\n",
            tempcount,current->userLocation, current->u_lat, 
            current->u_long);
        current = current->next;
        }

    printf("...finished printing list\n");
    return 0;
    }
