/*
Write the following function. The call sum(g,i,j) should return g(i) + ... + g(j).
int sum(int (*f)(int), int start, int end);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int (*f)(int), int start, int end);

int function(int i);

int start = 10, end = 20;

int main(void)
{
    printf("The sum is: %d\n",sum(function,start,end));

}

int sum(int (*f)(int), int start, int end)
{
    int temp = 0, interval = 2;
    int increment = ceil((end-start)/interval);

    while(start <= end){
        temp += function(start);
        start += increment;
    }

    return temp;
}

int function(int i)
{
    return i * i;
}
