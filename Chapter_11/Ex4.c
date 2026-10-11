/* Write the following function
void swap(int *p, int *q);
when passed the addresses of two variables, swap should exchange the values of the variables:

swap(&i,&j); //exchanges values of i and j

*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q);

int i = 10;
int j = 20;

int main(void)
{
    printf("Original Values\ni: %d\nj: %d\n", i, j);

    swap(&i, &j);

    printf("Swap Results\ni: %d\nj: %d\n", i, j);

    return 0;
}

void swap(int *p, int *q)
{
    int temp = 0;
    temp = *p;
    *p = *q;
    *q = temp;
}

/*
Example Ans:
void swap(int *p, int *q)
{
  int temp;

  temp = *p;
  *p = *q;
  *q = temp;
}
*/