/*
Functions Needed
pay_amount --> Sorts dollar amount into 50, 20, 10, 5, 1 dollar bills(determines how many of each is needed)
int main--> shows prompt, recieve input, prints dollar amount

*/
#include <stdio.h>
#include <stdlib.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void){
    int dollars, twenties, tens, fives, ones;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("\n$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenties, tens, fives, ones);
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars / 1;
    dollars %= 1;
}