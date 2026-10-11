#include <stdio.h>
#include <stdlib.h>

//#define LENGTH 5;

int sortArr[5] = {5,7,2,3,9};
int temp = 0;

int main(void){
    for(int i = 0; i < 5-1; i++){
        for(int  j = i+1; j < 5; j++){
            if(sortArr[i] > sortArr[j]){
                temp  = sortArr[j];
                sortArr[j] = sortArr[i];
                sortArr[i] = temp;
            }
        }
    }
    for(int k = 0; k < 5; k++){
        printf("%d\n",sortArr[k]);
    }
}