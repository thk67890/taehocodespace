/*

Modify the read_line function in each of the following ways:
(a) Have it skip white space before beginning to store input characters.
(b) Have it stop reading at the first white-space character.
(c) Have it stop reading at the first new-line character, then store the new-line character in the string
(d) Have it leave behind characters that it doesn't have room to store

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_line(char str[], int n);

int read_linea(char str[], int n);

int read_lineb(char str[], int n);

int read_linec(char str[], int n);

int read_lined(char str[], int n);

int main(void)
{

}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while((ch = getchar()) != '\n'){
        if(i < n) str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int read_linea(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n'){
        if(i == 0 && isspace(ch))
            ;
        else if(i < n) str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int read_lineb(char str[], int n)
{
    int ch, i = 0;
    while(!(isspace(ch = getchar()))){
        if(i < n) str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int read_linec(char str[], int n)
{
    int ch, i = 0;
    do{
        ch = getchar();
        if(i < n) str[i++] = ch;
    }
    while(ch != '\n');

    str[i] = '\0';
    return i;
}


int read_lined(char str[], int n)
{
    int ch, i = 0;
    for(; i < n; i++){
        ch = getchar();
        if(ch == '\n') break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}


/*

Sample ANS
(a)

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i == 0 && isspace(ch))
      ;   ignore 
    else if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
(b)

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (!isspace(ch = getchar()))
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
(c)

int read_line(char str[], int n)
{
  int ch, i = 0;

  do {
    ch = getchar();
    if (i < n)
      str[i++] = ch;
  } while (ch != '\n');
  str[i] = '\0';
  return i;
}
(d)

int read_line(char str[], int n)
{
  int ch, i;

  for (i = 0; i < n; i++) {
    ch = getchar();
    if (ch == '\n')
      break;
    str[i] = ch;
  }
  str[i] = '\0';
  return i;
}
*/