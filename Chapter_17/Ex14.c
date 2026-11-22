/*
Modify the delete_from_list function so that its first parameter has type struct node** (a pointer to a pointer to the first node in a 
list) and its return type is a void. delete_from_list must modify its first argument to point to the list after the deisred node has 
been deleted.

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};


void delete_from_list(struct node **list, int n)
{
    struct node *cur, *prev;

    for(cur = *list, prev = NULL; cur != NULL && 
                cur -> value != n;prev = cur, cur = cur->next)
        ;
    if(cur == NULL){ //adding node to the first node
        printf("Value not found");
        return;
    }
    if(prev == NULL){ //adding node to the first node
        *list = (*list)->next;
    }
    else
        prev->next = cur->next;
    free(cur);
}