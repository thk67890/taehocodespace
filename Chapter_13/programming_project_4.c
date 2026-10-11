/*
- Creating a program that runs on command-line arguments --> Need to recieve command line arguments
- program needs to reverse the order of the command line arguments i.e reverse void and null --> null and void
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i = argc;
    while(i--> 1){
        printf("%s",argv[i]);
        printf(" ");
    }

    printf("\n");
    
    return 0;
}


/*
Sample ANS
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;

  for (i = argc - 1; i > 0; i--)
    printf("%s ", argv[i]);
  printf("\n");

  return 0;
}
  

*/