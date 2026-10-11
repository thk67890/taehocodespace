//#if and #endif

#include <stdio.h>
#define DEBUG 0


int main(void)
{
    #if DEBUG
    printf("Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #endif
}