//__func__ identifier

#include <stdio.h>

void foo(const char *a);
void woo(void);


int main(void){
    woo();
    foo(__func__);
}

void woo(void){
    foo(__func__);
}
void foo(const char *a){
    printf("Name of the function that called foo: %s\n",a);
    printf("%s called \n", __func__);
    printf("%s returns \n", __func__);
}

//looks useful for debugging. add const char*a to parameter and __func__ to present where and what function called the other
//Definately helps to trace calls