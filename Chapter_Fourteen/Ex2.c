/*
Write a macro NELEM(a) that computes the number of elements in a one-dimensinoal array a
*/
/*
#include <stdio.h>
#define SIZE(a) ((int)(sizeof(a)) / (sizeof(a[0])))
#define NELEM(a) \
int NELEM(int a[SIZE(a)]) {                  \
        for(int i = 0; i < SIZE(a); i++){ \
    if(a[i] == 0) return i; \
}

int a[10] = 0;


NELEM(a[SIZE(a)]);

int main(void){
    
    printf("Size of array a = %d",NELEM(a));

}

*/

#include <stdio.h>
#define NELEM(a) ((int)(sizeof(a)) / (sizeof(a[0])))

/*
Sample ANS

#define NELEM(a) ((int)(sizeof(a)) / sizeof(a[0]))


*/