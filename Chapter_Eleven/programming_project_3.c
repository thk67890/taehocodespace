/*
functions needed
reduce --> recieve original numerator and denomenator, reduce fraction to simplest form, push reduced numerator and denomenator as pointers_
int main --> print intro prompt, feed arguments into reduce function, print results
*/

#include <stdio.h>
#include <stdlib.h>

void reduce(int numerator, int denomenator, int *reduced_numerator, int *reduced_denomenator);

int main(void)
{
    int numerator, denomenator, reduced_numerator, reduced_denomenator;

    printf("Enter a fraction:" );
    scanf("%d/%d",&numerator, &denomenator);

    reduce(numerator,denomenator, &reduced_numerator,&reduced_denomenator);

    printf("In lowest terms: %d/%d\n",reduced_numerator, reduced_denomenator);
}


void reduce(int numerator, int denomenator, int *reduced_numerator, int *reduced_denomenator)
{
    int a,b,r;
    int gcd;

    if(numerator > denomenator) {
        a = numerator; 
        b = denomenator;
    }
    else {
        a = denomenator; 
        b = numerator;
    }

    while(1){
        r = a % b;
        if(r != 0){
            a = b;
            b = r;
        }
        else {
            gcd = b;
            break;
        }
    }

    *reduced_numerator = numerator / gcd;
    *reduced_denomenator = denomenator / gcd;

}