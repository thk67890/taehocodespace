#include <stdio.h>

int main(void){

    int GSI, GI, PC, IN, CD;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", GSI, GI, PC, IN, CD);

    printf("GSI Prefix: %d\nGroup identifier: %d\nPublisher Code: %d\nItem number: %d\nCheck digit: %d", GSI, GI, PC, IN, CD);

    return 0;
}