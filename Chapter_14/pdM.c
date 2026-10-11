//Predefined macros

#include <stdio.h>





int main(void){
    printf("Line of code of current function: %d \n" \
    "Name of File: %s \n" \
    "Date of compilation: %s \n" \
    "Time of compilation: %s \n" \
    "Whether compiler conforms to c standard: %d \n", __LINE__,__FILE__,__DATE__,__TIME__,__STDC__);
}