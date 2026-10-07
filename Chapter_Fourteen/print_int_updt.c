#include <stdio.h>
#define print_int_updt(N) printf(#N " = %d\n",N)

int main(void){

    print_int_updt(10/5);
}