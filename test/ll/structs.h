// structure definitions
typedef struct userList
    {
    struct userData* head;
    struct userData* tail;
    int count;
    } userList;

typedef struct userData
    {
    char userLocation[1000];
    double u_lat; // user's latitude
    double u_long; // user's longitude
    struct userData* next; // pointer to next item in linked list
    } userData;

