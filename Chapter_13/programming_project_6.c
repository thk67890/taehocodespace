/*
Improve planet.c to ignore case(uppercase, lower case) when comparing command-line arguments with strings in the planet array

- create string comparison function that converts string and planet names into uppercase and then compares


*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int stringCompare(char *s, char *t);

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupitor",
                        "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j;

    for(i = 1; i < argc; i++){
        for(j = 0;j < NUM_PLANETS; j++)
            if(stringCompare(argv[i],planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        if(j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

int stringCompare(char *s, char *t)
{
    char UpS[100], UpP[100];
    int i,j = 0;
    while(*s++){
        UpS[i] = *s;
        i++;
    }

    while(*t++){
        UpP[j] = *t;
        j++;
    }
    return strcmp(UpS, UpP);
}





/*
Sample ANS
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int string_equal(const char *s, const char *t);

int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (string_equal(argv[i], planets[j])) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

int string_equal(const char *s, const char *t)
{
  int i;

  for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
    if (s[i] == '\0')
      return 1;

  return 0;
}




*/