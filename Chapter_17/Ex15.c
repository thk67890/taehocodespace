#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n",f1(f2));
    return 0;
}

int f1(int (*f)(int))
{
    int n = 0;
    while((*f)(n)) n++;
    return n;
}

int f2(int i)
{
    return i * i + i - 12;
}

/*
Show the output of the following program and explain what it does.
Output: "Answer: 3"
f2 is run until it returns a 0 and terminate f1. f1 returns the value of n that causes the while loop to terminate which is 3.
*/