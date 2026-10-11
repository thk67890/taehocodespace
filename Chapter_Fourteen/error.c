//#error

#include <stdio.h>
#define OS 1
#define MACOS



int main(void){
    #ifdef OS 
    printf("OS detected: ");
    #endif

    #ifdef MACOS 
    printf("MAC\n");
    #elif defined(WIN64) 
    printf("WIN64\n");
    #elif defined(LINUX) 
    printf("LINUX\n");
    #else
    #error No OS detected
    #endif


    return 0;
}