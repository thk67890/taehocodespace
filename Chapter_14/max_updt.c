#include <stdio.h>
#define max_updt(type)              \
type type##_max(type x, type y)     \
{                                   \
    return x > y ? x : y;           \
}

max_updt(float)

int main(void){
    
    

    printf("%f\n", float_max(5.9382,5.3859));

}