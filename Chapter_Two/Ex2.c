/* 
Condense the dweight.c program by (1) replacing the assignments to height, length, and width with initializers 
and (2) removing the weight variable, instead calculating (volume + 165) / 166 within the last printf

dweight.c
#include <stdio.h>

int main(void)
{
    int height, length, width, volume, weight;

    printf("Enter the height of the box: ");
    scanf("%d", &height);
    printf("Enter the length of the box: ");
    scanf("%d", &length);
    printf("Enter the width of the box: ");
    scanf("%d", &width);
    volume = height * length * width;
    weight = (volume + 165) / 166;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}
*/

#include <stdio.h>

int main(void)
{
    int height = 8, length = 12, width = 10, volume;
    volume = height * length * width;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

    return 0;
}
