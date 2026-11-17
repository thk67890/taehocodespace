#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char str[]);

int main(void)
{
    char str[15] = "taeho kang!";
    char *result;

    result = duplicate(str);
    printf("%s\n",result);

    return 0;
}

char *duplicate(char str[])
{
    char *result;
    result = malloc(strlen(str) + 1);
    if(result == NULL)
        return NULL;

    strcpy(result,str);
    return result;
}


/*
ANS

char *duplicate(const char *s)
{
  char *temp = malloc(strlen(s) + 1);

  if (temp == NULL)
    return NULL;

  strcpy(temp, s);
  return temp;
}
*/