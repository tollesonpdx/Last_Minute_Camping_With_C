// Chad Tolleson
// testing of field wrapper function
// filename: test_wrap.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f_wrapField.c"

int main()
    {
    char* a = "test";
    printf("a is %s\t%ld\n",a,strlen(a));
    char* c = wrapField(a);
    printf("c is %s\t%ld\n",c,strlen(c));
    
    return 0;
    }
