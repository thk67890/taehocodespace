/*
For each of the following macros, give an example that illustrates a problem with the macro and show how to fix it.
(a) #define AVG(x,y) (x+y)/2
(b) #define AREA(x,y) (x) * (y)
*/


#include <stdio.h>
#define AREA(x,y) (x) * (y)
#define AVG(x,y) (x+y)/2


int main(void){
    //(a) error case
    int  a = 2;
    int b = 10;

    //a = 10 * AVG(a,b);
    a = 40 / AREA(a,b);
    b = 12 / AVG(a,b);

    printf("Intended = 20 Resulting a = %d\n", a);
    printf("Intended = 2 Resulting b =  %d\n",b);
    //The problem with both macros is that when they are invocated, they are not invocated within parenthesis
    //As a result they are affected by precedence and associativity resulting in unexpected return values
    //Here's the fix
    //#define AREA(x,y) ((x) * (y))
    //#define AVG(x,y)  ((x+y) / 2)

}