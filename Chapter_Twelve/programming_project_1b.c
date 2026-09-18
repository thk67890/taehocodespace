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
    for(ptr; ptr < ptr + count; ptr++) { //Review 때는 이걸 완전히 pointer로만 해보기 ptr subscripting말고 그냥 순수 ptr arithmetic으로
        temp = *(ptr + (count-1));
        *(ptr + (count-1)) = *ptr;
        *ptr = temp;
        count--;
        
    }


}

/*
#include <stdio.h>

#define MSG_LEN 80      maximum length of message 

int main(void)
{
  char msg[MSG_LEN], *p;

  printf("Enter a message: ");
  for (p = &msg[0]; p < &msg[MSG_LEN]; p++) {
    *p = getchar();
    if (*p == '\n')
      break;
  }

  printf("Reversal is: ");
  for (p--; p >= &msg[0]; p--)
    putchar(*p);
  putchar('\n');

  return 0;
}
*/