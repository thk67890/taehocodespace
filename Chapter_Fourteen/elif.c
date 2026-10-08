#include <stdio.h>
#define DEBUG 0
#define MACOS 0
#define WIN64 0
#define LINUX 0


int main(void)
{
    #if DEBUG
    printf("Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #elif __STDC__
    printf("STDC! ");
    printf("ELIF!");
    #endif

    #if WIN64
    printf("WIN64! Taeho Kang");
    printf(" is good at");
    printf(" CODING!\n");
    #elif MACOS
    printf("MACOS! ");
    printf("ELIF!");
    #elif LINUX
    printf("HII LINUX");
    #else
    printf("Unknown operating system!");
    #endif
}