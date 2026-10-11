/*
Rewrite the following function to use pointer arithmetic instead of array subscripting. Make as few changes as possible.
*/

#include <stdio.h>

int sum_array(const int a[], int n)
{
    int sum = 0;
    int *p = a;

    sum = 0;
    for(p = a; p < a + n; p++)
        sum += *p;
    return sum;
}


/*
Sample ANS

int sum_array(const int a[], int n)
{
  int *p, sum;

  sum = 0;
  for (p = a; p < a + n; p++) // a + n == a[0+n]
    sum += *p;
  return sum;
}
*/