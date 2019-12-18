// Chad Tolleson Copyright (c) 2019
// New Beginnings 2018 - Capstone Project
// filename: f_addUserNode.c

#include "headers.h"

int userListAdd(struct userList* L, char* loc)
    {
    printf("insider add user node\n");
    struct userData* fresh = malloc(sizeof(userData));
    printf("added user location data\n");
    strcpy(fresh->userLocation, loc);
    printf("userLocation = %s\n",fresh->userLocation);

    if (L->head == NULL)
        {
        printf("no head, fresh is head\n");
        L->head = fresh;
        L->tail = fresh;
        L->count = 1;
        printf("head userLocation = %s\n",L->head->userLocation);
        return 0;
        }
    
    else
        {
        printf("there was a head, adding location in list\n");
        //struct userData* current = L->head;
        //while (current->next != NULL)
        //    { current = current->next; }
        L->tail->next = fresh;
        L->tail = fresh;
        L->count++;
        return 0;
        }

    return 1;
    }
