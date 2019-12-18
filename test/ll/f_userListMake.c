// Chad Tolleson Copyright (c) 2019
// New Beginnings 2018 - Capstone Project
// filename: f_makeUserList.c

#include "headers.h"

struct userList* userListMake()
    {
    struct userList* L = malloc(sizeof(struct userList));
    L->head = NULL;
    L->tail = NULL;
    L->count = 0;
    printf("returning to main from making user list\n");
    return L;
    }

