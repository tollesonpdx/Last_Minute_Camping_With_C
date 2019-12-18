// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_userListDelete.c

#include "headers.h"

int userListDelete(struct userList* L, int p)
    {
    if (p) { printf("deleting user list..."); }
    
    if (L->head == NULL)
        {
        if (p) { printf("no head, returning...\n"); }
        return 0;
        }

    struct userData* current = L->head;
    struct userData* previous = L->head;

    while (current != NULL)
        {
        previous = current;
        current = current->next;
        free(previous);
        }

    if (p) { printf("finished deleting list\n"); }
    return 0;
    }
     
