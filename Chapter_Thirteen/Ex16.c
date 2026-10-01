/*
Use the techniques of Section 13.6 to condense the cuot_spaces functino of Section 13.4. 
In particular, replace the for statement by a while loop
*/


#include <stdio.h>
#include <string.h>

int count_spaces(const char *s);
int count_spaces_updt(const char *s);

int main(void)
{
    char arr[] = "taeho kang's pizza shop";

    printf("%d",count_spaces_updt(arr));

}

int count_spaces(const char *s)
{
    int count = 0;

    for(; *s != '\0'; s++)
        if(*s == ' ')
            count++;
    return count;
}

int count_spaces_updt(const char *s)
{
    int count = 0;

    while(*s++){
        if(*s == ' ')
            count++;
    }

    return count;
}