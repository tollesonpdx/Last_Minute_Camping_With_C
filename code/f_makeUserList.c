// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: f_makeUserList.c

#include "headers.h"

struct userData* makeUserList()
    {
    struct userData* head = malloc(sizeof( userData* ));
    strcpy(head->userLocation, "zzz");
    head->next = NULL;
    return head;
    }

