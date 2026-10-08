//defined

#include <stdio.h>
#define DEBUG


int main(void)
{
    #if defined(DEBUG)
    printf("Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #endif
}