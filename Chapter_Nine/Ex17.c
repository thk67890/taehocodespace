//Rewrite the fact function so that it's no longer recursive
/*
int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n-1);
}

*/

#include <stdio.h>
#define FT 10;

int fact(int n);

int main(void)
{
    int num = FT;

    printf("%d factorial: %d\n", num, fact(num));
}

int fact(int n)
{
    for(int i = n-1;i>0;i--){
        n *= i;
    }

    return n;
}

/*
Sample ANS
int fact(int n)
{
  int i, result = 1;

  for (i = 2; i <= n; i++)
    result *= i;

  return result;
}

*/