//Write a function digit(n,k) that returns the k^th digit (from the right) in n (a positive integer). 
//For example, digit (829,1) returns 9, digit(829,2) returns 2, and digit(829,3) returns 9. If k is
//greater than the number of digits in n, have the funciton return 0;

#include <stdio.h>


int digit(int n, int k)
{
    int digit_bank[100], i = 1;

    while(1) {
        digit_bank[i] = n % 10;

        n/=10;

        if (n == 0) break;

        i++;
    }

    if(i < k) return 0;
    else return digit_bank[k];
}

int main(void)
{
    printf("%d\n",digit(3,1));
}

/*
Sample ANS

int digit(int n, int k)
{
  int i;

  for (i = 1; i < k; i++)
    n /= 10;

  return n % 10;
}

*** 3 * 10 == 3 Not 10. This made the difference in my code & the Sample.
*/