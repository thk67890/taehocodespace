/*
Write the parameterized macros that compute the following values
(a) the cube of x
(b) the remainder when n is divided by 4
(c) 1 if the product of x and y is less than 100, 0 otherwise
do your macros always work? If not, describe what arguments would make them fail.

I don't know when they will fail!
*/

#include <stdio.h>
#define cube(x) ((x)*(x))
#define remainder(n) ((n) % 4)
#define product(x,y) (((x) * (y)) > 100 ? 1 : 0)

int main(void){
    printf("Cube of 5 = %d\n",cube(5));
    printf("Remainder of 5 divided by 4 = %d\n",remainder(5));
    printf("product of 50 * 50 exceeds 100 if following number is 1, %d\n", product(50,50));

}

/*
ANS to final Q: The macros will only work with arguments that evaluate a numeric type.

*/