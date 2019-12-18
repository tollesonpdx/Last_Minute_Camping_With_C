// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_makeUserList.c

#include "headers.h"

struct userList* userListMake(int p)
    {
    if (p) { printf("creating list of uncoded users..."); }
    struct userList* L = malloc(sizeof(struct userList));
    L->head = NULL;
    L->p = p;
    L->count = 0;
    if (p) { printf("list created successfully...\n"); }
    return L;
    }

