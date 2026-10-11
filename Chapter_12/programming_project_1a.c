/*
Function needed
1. int main() --> print prompt, read input message, call process(), print return message(reverse messege)
2. process() --> store message as character array, reverse order, pass reversed array through pointer
*/

#include <stdio.h>
#include <stdbool.h>

#define NUM_CHAR 1000

void process(char *ptr, int count);

int main(void)
{
    char a[NUM_CHAR];
    char *ptr = a;
    char ch;
    int count = 0;

    printf("Enter a message:");

    while(1){ //receiving input
        ch = getchar(); //Review 때는 이거 ch 없이 돌리는 방법 찾아보기; if((*ptr = getchar() != '\n') ... 이런 느낌일듯?
        *ptr = ch;
        if(ch != '\n'){
            ptr++;
            count++;
        }
        else break;
    }
        
    printf("\nLength of arr: %d\n\n",count);

    process(a,count);

    printf("Reversal is ");
    for(ptr = a; ptr < a + count; ptr++){
        printf("%c", *ptr);
    }
    printf("\n");

}

void process(char *ptr,int count)
{
    char temp;
    for(int i = 0; i < count; i++) { //Review 때는 이걸 완전히 pointer로만 해보기 ptr subscripting말고 그냥 순수 ptr arithmetic으로
        temp = ptr[count-1];
        ptr[count-1] = ptr[i];
        ptr[i] = temp;
        count--;
        
    }
}

/*
Sample ANs
#include <stdio.h>

#define MSG_LEN 80      maximum length of message 

int main(void)
{
  char msg[MSG_LEN];
  int i;

  printf("Enter a message: ");
  for (i = 0; i < MSG_LEN; i++) {
    msg[i] = getchar();
    if (msg[i] == '\n')
      break;
  }

  printf("Reversal is: ");
  for (i--; i >= 0; i--)
    putchar(msg[i]);
  putchar('\n');

  return 0;
}

*/