#include <stdio.h>
#define IS_EVEN(i) ((i) % 2 ? "Odd" : "Even")

int main(void) {
    printf("%s\n",IS_EVEN(6));
}