//#line


#include <stdio.h>

int main(void){
    printf("Current line: %d\n", __LINE__);
    #line 10
    printf("Line # after #line: %d\n",__LINE__);

    printf("Current file name & Line Num: %s  %d\n", __FILE__, __LINE__);
    #line 10 "taeho.c"
    printf("File name and line # after #line: %s  %d\n",__FILE__, __LINE__);
}