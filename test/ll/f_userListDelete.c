// Chad Tolleson Copyright (c) 2019
// New Beginnings 2018 - Capstone Project
// filename: f_userListDelete.c

#include "headers.h"

int userListDelete(struct userList* L)
    {
    printf("deleting user linked list\n");
    
    if (L->head == NULL)
        {
        printf("no head, returning to main\n");
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

    printf("done deleting linked list\n");
    return 0;
    }
     
