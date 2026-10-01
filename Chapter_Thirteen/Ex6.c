/*
Write a function named censor that modifies a string by replacing every occurence of foo by xxx. 
For example, the string "food fool" would become "xxxd xxxl". Make the functin as short as possible
without sacrificing clarity.
*/

#include <stdio.h>
#include <string.h>

void cmp(char str[], int n);

int main(void)
{
    char str[] = "food fool";
    int n = sizeof(str);
    cmp(str,n);

    printf("%s",str);
}

void cmp(char str[], int n)
{
    int i = 0;
    while(i < n-2){ //--> can be changed to for(i = 0; str[i] != '\0'; i++) bc '\0' would cause the if statement to stop before it evaluates characters following the null char
        if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'o'){
            str[i] = 'x';
            str[i+1] = 'x';
            str[i+2] = 'x'; //--> can be changed to str[i] = str[i+1] = str[i+2] = 'x';
        }
        i++;

    }
}