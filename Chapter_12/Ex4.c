/*
Rewrite tha make_empty, is_empty, and if_full functions of Section 10.2 to use the pointer variable top_ptr instead of the integer variable top.
*/

#include <stdbool.h>

#define STACK_SIZE 100
int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty(void)
{
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents;
}

bool is_full(void)
{
    return top_ptr == contents[STACK_SIZE];
}

void push(int i)
{
    if(is_full())
        stack_overflow();
    else
        *top_ptr = i;
        top_ptr++;
}

int pop(void)
{
    if(is_empty())
        stack_underflow();
    else
        top_ptr--;
        return *top_ptr;
}

/*
Sample ANS
int *top_ptr;

void make_empty(void)
{
  top_ptr = &contents[0]; --> using &contents[0] may be more intuitive but my answer is still correct too
}

bool is_empty(void)
{
  return top_ptr == &contents[0];
}

bool is_full(void)
{
  return top_ptr == &contents[STACK_SIZE];
}

*/