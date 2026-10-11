#include <stdio.h>
#include <stdlib.h>

/* 
Functions Needed
1. Decompose Function --> divides input variable into int part and frac part;; recieve as pointers == return type void;
2. int main --> print opening promp, recieve input val(float value), print int and frac parts
*/

void decompose(float x,long *int_part, double *frac_part);

int main(void)
{
    float x = 0;
    long int_part = 0;
    double frac_part = 0;

    printf("Enter a value to Split!");
    scanf("%f",&x);

    decompose(x,&int_part, &frac_part);

    printf("Integer Part of Your Value: %ld\n", int_part);
    printf("Fraction Part of Your Value: %f\n", frac_part);    
}

void decompose(float x,long *int_part, double *frac_part)
{
    *int_part = (long)x;
    *frac_part = x - *int_part;
}