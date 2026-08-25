#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

int contents[STACK_SIZE] = {1,2,3,4,5,6};
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    contents[top++] = i;
}

int pop(void)
{
    return contents[--top];
}

int main(void)
{
    printf("initial\n");
    for(int i = 0;i<=5;i++) {
        printf("%d",contents[i]);
    }

    printf("\npush\n");
    for(int j = 0;j<=5;j++) {
        push(j);
        printf("%d",contents[j]);
    }

    printf("\npop\n");
    for(int j = 0;j<=5;j++) {
        printf("%d",pop());
    }
}

//Top represents the location of the subject element within the Content array.
//As the array is popped, Top moves back an element and returns the value being popped.
//In this case we call this refer to this value as being "popped" because it will be overwritten once a push command is made.
//When a value is pushed after a "pop", the element in the array location of the popped value will be overwritten by the pushed value
//Then, the arrow will be moved one element location forwards in the array to either pop or push the next adequate value.
