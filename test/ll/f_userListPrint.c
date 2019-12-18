// Chad Tolleson Copyright (c) 2019
// New Beginnings 2018 - Capstone Project
// filename: f_printUserList.c

#include "headers.h"

int userListPrint(struct userList* L)
    {
    printf("printing user linked list\n");
    
    if (L->head == NULL)
        {
        printf("no head, returning to main\n");
        return 0;
        }

    struct userData* current = L->head;
    int tempCount = 0;

    while (current != NULL)
        {
        tempCount++;
        printf("#%d = location: %s\tlat,lng: %lf, %lf\n",
            tempCount,current->userLocation, current->u_lat, 
            current->u_long);
        current = current->next;
        }

    printf("done printing linked list\n");
    return 0;
    }
