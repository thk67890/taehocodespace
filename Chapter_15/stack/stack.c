#include <stdio.h>
#include "stack.h"


static int contents[100];
static int top = 0;

void make_empty(void)
{
    top = 0;
}

int is_empty(void)
{
    if(top == 0){
        return 1;
    }
    else return 0;
}

int is_full(void)
{
    if(top == 100){
        return 1;
    }
    else return 0;
}

void push(int i)
{
    if(!is_full()){
        contents[top++] = i;
    }
    else printf("Stack is full!\n");
}

int pop(void)
{
    if(!is_empty()){
        return contents[--top];
    }
    else  printf("Stack is empty!\n");
    return -1;
}

int peek(void)
{
    if(!is_empty()){
        return contents[top-1];
    }
    else{
        printf("Stack is empty!");
        return -1;
    }
}