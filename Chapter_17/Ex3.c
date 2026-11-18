/*
Write the following function:
int *create_array(int n, int initial_value);

The function should return a pointer to a dynamically allocated int array with n members, eacb of which is initialized to
initial_value. The return value should be NULL if the array can't be allocated.
*/

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value);

int main(void)
{
    int init = 10;
    int n = 5;
    int *arr;

    arr = create_array(n,init);
    printf("Initial Value: %d\n",arr[0]);
    
    return 0;
}

int *create_array(int n, int initial_value)
{
    int *p = malloc(n * sizeof(int));
    p[0] = initial_value;

    return p;
}