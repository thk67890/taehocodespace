/*
Write a program that declares several int and float variables, without initializing them, and then prints their values. Is there any patterns to the values? (Usually there isn't.)

No Pattern--value keeps on changing each time the program is run
*/

#include <stdio.h>

int main(void)
{
    int a,b,c;
    float x,y,z;

    printf("int values: %d, %d, %d\n", a, b, c);
    printf("float values: %f, %f, %f\n", x, y, z);

    return 0;
}