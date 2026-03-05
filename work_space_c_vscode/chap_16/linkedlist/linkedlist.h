#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct linked_list{
    char *name;
    struct linked_list *next;
};
typedef struct linked_list NODE;
typedef NODE *LINK;
