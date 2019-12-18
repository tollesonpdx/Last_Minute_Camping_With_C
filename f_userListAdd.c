// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_userListAdd.c

#include "headers.h"

int userListAdd(struct userList* L, char* loc, double* coords, int p)
    {
    if (p) { printf("adding user node to list...\n"); }

    // create new node to hold user data
    struct userData* fresh = malloc(sizeof(userData));
    strcpy(fresh->userLocation, loc);
    fresh->u_lat = coords[0];
    fresh->u_long = coords[1];
    fresh->next = NULL;
    if (p) { printf("fresh node = %s\t%lf,%lf\n",
            fresh->userLocation,fresh->u_lat,fresh->u_long); }

    if (L->head == NULL)
        {
        if (p) { printf("no head, fresh is head...\n"); }
        L->head = fresh;
        L->tail = fresh;
        L->count = 1;
        if (p) { printf("head = %s\t%lf,%lf\n",
                L->head->userLocation,
                L->head->u_lat, L->head->u_long); }
        return 0;
        }
    
    else
        {
        if (p) { printf("there is a head, adding user in "
                        "list...\n"); }
        struct userData* current = L->head;
        //while (current->next != NULL)
        //    {
        //    if (p) { printf("moving to next node...\n"); }
        //    current = current->next;
        //    }
        //current->next = fresh;
        if (p) { printf("setting last node to fresh...\n"); }
        L->tail->next = fresh;
        L->tail = fresh;
        if (p) { printf("fresh node in list = %s\t%lf,%lf\n",
                current->next->userLocation,
                current->next->u_lat, 
                current->next->u_long); }
        L->count++;
        return 0;
        }

    return 1;
    }
