#include <stdio.h>

int main(void){

    float dollaramnt;

    printf("Enter an anount: ");
    scanf("%f", &dollaramnt);

    printf("With tax added: $%.02f\n",dollaramnt * 1.05f);

    return 0;
}

/*
Sample Code from Author

#include <stdio.h>

int main(void)
{
  float original_amount, amount_with_tax;

  printf("Enter an amount: ");
  scanf("%f", &original_amount);
  amount_with_tax = original_amount * 1.05f;
  printf("With tax added: $%.2f\n", amount_with_tax);

  return 0;
}
The amount_with_tax variable is unnecessary. If we remove it, the program is slightly shorter:

#include <stdio.h>

int main(void)
{
  float original_amount;

  printf("Enter an amount: ");
  scanf("%f", &original_amount);
  printf("With tax added: $%.2f\n", original_amount * 1.05f);

  return 0;
}

*/