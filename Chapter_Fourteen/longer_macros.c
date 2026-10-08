#include <stdio.h>
#include <string.h>

#define echo(s) (gets(s),puts(s)) // gets(s) no longer exists in C!
#define echos(s) \
do{gets(s); puts(s);} \
while(0)


int main(void) {
    char s[100];
    echo(s);


}