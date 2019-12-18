#ifndef __HEADERS_H_
#define __HEADERS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


struct userList* userListMake();
int userListAdd(struct userList* L, char* loc);
int userListPrint(struct userList* L);
int userListDelete(struct userList* L);

#endif 

