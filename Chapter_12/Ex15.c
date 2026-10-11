/*
Write a loop that prints all temperature readins stored in row i of the temperatures array. Use a pointer to visit each element of the row
*/

#include <stdio.h>

int temperature[7][24];

int main(void)
{
    int *ptr;
    int i = 5;
    for(ptr = &temperature[i]; ptr < &temperature[i]+24; ptr++)
        printf("%d  ", *ptr);
    
    return 0;
}

/*
Sample ANS

int *p;

for (p = temperatures[i]; p < temperatures[i] + 24; p++)
  printf("%d ", *p);
*/