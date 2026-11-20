#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

int main(void)
{
    struct node *first = NULL;

    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    new_node -> value = 10;
    new_node -> next = first;
    first = new_node;

    new_node = malloc(sizeof(struct node)); //2nd node, allocating new space
    new_node -> value = 20;
    new_node -> next = first;
    first = new_node;

    new_node = malloc(sizeof(struct node)); //3rd node, allocating new space
    new_node -> value = 30;
    new_node -> next = first;
    first = new_node;

    struct node *p;
    for(p = first; p != NULL; p= p->next){
        printf("%d\n",p->value);
    }

    return 0;
}