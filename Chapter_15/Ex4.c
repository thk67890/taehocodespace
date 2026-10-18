/*
Assume that debug.h is a header file with the following contents:

#ifdef DEBUG
#define PRINT_DEBUG(n) printf("Value of " #n ":%d\n",n) //defined
#else
#define PRINT_DEBUG(n) //discarded
#endif

Let testdebug.c be the following source file:
#include <stdio.h>

#define DEBUG
#include "debug.h"

int main(void)
{
    int i = 1, j =2, k = 3;

#ifdef DEBUG
    printf("Output if DEBUG is defined: \n"); //printed
#else
    printf("Output if DEBUG is not defined: \n"); //discarded
#endif
    PRINT_DEBUG(i); --> "Value of i: 1"
    PRINT_DEBUG(j); --> "Value of j: 2"
    PRINT_DEBUG(k); --> "Value of k: 3"
    PRINT_DEBUG(i + j); --> "Value of i + j: 3"
    PRINT_DEBUG(2 * i + j - k); --> "value of 2 * i + j - k: 1"
    
    return 0;
}

(a) What is the output when the program is executed?
"Output if DEBUG is defined: "
"Value of i: 1"
"Value of j: 2"
"Value of k: 3"
"Value of i + j: 3"
"Value of 2 * i + j -k: 1"


(b) What is the output if the #define directive is removed from testdebug.c?
"Output if DEBUG is not defined"

(c) Explain why the output is different in parts (a) and (b)
b/c the debug.h header defines the PRINT_DEBUG(n) macro differently depending on whether the conditional compilation directive #ifdef
passes.

(d) Is it necessary for the DEBUG macro to be defined before debug.h is included in order for PRINT_DEBUG to have the desired effect?
    Justify your answer.
    Yes. Without it the desired print statements will not be printed.


Sample ANS matches response
*/