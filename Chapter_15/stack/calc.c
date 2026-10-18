#include "stack.h"
#include <stdio.h>

int main(void){
    push(1);
    push(2);
    push(90);
    printf("%d\n",peek());
    pop();
}