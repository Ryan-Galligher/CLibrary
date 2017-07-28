#include <stdio.h>
#include <stdlib.h>


//type 0 = int
//type 1 = float
//type 2 = string
typedef struct node
{
    int type;
    char * data;
    struct node * next;
    struct node * previous;
}linkList;