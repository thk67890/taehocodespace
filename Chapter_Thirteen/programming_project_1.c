#include <stdio.h>
#include <string.h>
#define n 20


int main(void){
    char smallest_word[n+1];
    char largest_word[n+1];
    char input[n+1];

    //initializing comparison
    printf("Enter word: ");
    scanf("%s",input);
    strcpy(smallest_word, input);
    strcpy(largest_word, input);
    
    while(!(strlen(input) == 4)){
        //Intro prompt
        printf("Enter word: ");

        //receive input
        scanf("%s",input);

        //compare input with smallest word
        if(strcmp(input,smallest_word) < 0)
            strcpy(smallest_word, input);

        //compare input with largest word
        else if(strcmp(input,largest_word) > 0)
            strcpy(largest_word, input);
    }

    //print results
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    


}

/*

Sample ANS

#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

void read_line(char str[], int n);

int main(void)
{
  char smallest_word[WORD_LEN+1],
       largest_word[WORD_LEN+1],
       current_word[WORD_LEN+1];

  printf("Enter word: ");
  read_line(current_word, WORD_LEN); //replacing scanf with a custom input function(no necessary for this problem but can be useful when accepting specifically formatted input)
  strcpy(smallest_word, strcpy(largest_word, current_word)); // Embedding two strcpy into one line

  while (strlen(current_word) != 4) {
    printf("Enter word: ");
    read_line(current_word, WORD_LEN);
    if (strcmp(current_word, smallest_word) < 0)
      strcpy(smallest_word, current_word);
    if (strcmp(current_word, largest_word) > 0)
      strcpy(largest_word, current_word);
  }

  printf("\nSmallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;
}

void read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
}



*/