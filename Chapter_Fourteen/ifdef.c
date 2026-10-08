//#ifdef #ifndef

#include <stdio.h>
#define DEBUG 0


int main(void)
{
    #ifdef DEBUG
    printf("Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #endif

    #ifndef TAEHO
    printf("NDEF !! Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #endif
}