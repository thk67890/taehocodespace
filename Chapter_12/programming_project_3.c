/*
Function needed
1. int main() --> print prompt, read input message, call process(), print return message(reverse messege)
2. process() --> store message as character array, reverse order, pass reversed array through pointer
*/

#include <stdio.h>
#include <stdbool.h>

#define NUM_CHAR 1000


int main(void)
{
    char a[NUM_CHAR];
    char *ptr = a;
    int count = 0;

    printf("Enter a message:");

    while(1){ //receiving input
         //Review 때는 이거 ch 없이 돌리는 방법 찾아보기; if((*ptr = getchar() != '\n') ... 이런 느낌일듯? 성공
        *ptr = getchar();
        if(*ptr != '\n'){
            ptr++;
            count++;
        }
        else break;
    }
        
    printf("\nLength of arr: %d\n\n",count);

    printf("Reversal is ");
    for(ptr--; ptr >= a; ptr--){ //processing unecessary. We can just go backwards!!!!
        putchar(*ptr);
    }
    putchar('\n');

    return 0;

}


/*
Sample ANS
#include <stdio.h>

#define MSG_LEN 80      maximum length of message 

int main(void)
{
  char msg[MSG_LEN], *p;

  printf("Enter a message: ");
  for (p = msg; p < msg + MSG_LEN; p++) {
    *p = getchar();
    if (*p == '\n')
      break;
  }

  printf("Reversal is: ");
  for (p--; p >= msg; p--)
    putchar(*p);
  putchar('\n');

  return 0;
}
*/
