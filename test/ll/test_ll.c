// Chad Tolleson
// linked list test

#include "headers.h"

// main 
int main()
    {
    int a = 0;

    printf("making user list\n");
    struct userList* L = userListMake();
    
    printf("adding 1st user node\n");
    a = userListAdd(L, "Portland, OR");
    if (a != 0)
        { printf("user list node addition error\n"); }
    
    printf("adding 2nd user node\n");
    a = userListAdd(L, "Salem, OR");
    if (a != 0)
        { printf("user list node addition error\n"); }
    
    userListPrint(L);
    userListDelete(L);
    free(L);
    return 0;
    }
