#include <stdio.h>
#include <stdlib.h>
/*
Functions Needed
1. maxmin --> goes through input arr and finds the max and min elements of the arr. Inputs max and min value through pointers *big *small
2. int main --> recieves N number of values and collects them as an array.
                passes arr to max min.
                prints max and min value using the variable which the pointers from max min func points at.
*/

void maxmin(int N,int arr[], int *big, int *small);

int main(void)
{
    int N = 0;
    int arr[10000];
    int big, small;
    
    printf("How many numbers would you like to enter? ");
    scanf("%d",&N);

    printf("Enter %d numbers\n", N);
    
    for(int i = 0; i < N; i++){
        printf("Enter number #%d: ",i+1);
        scanf("%d",&arr[i]);

    }

    maxmin(N,arr,&big,&small);
    printf("\nYour Largest Number: %d\n",big);
    printf("Your Smallest Number: %d\n",small);

    return 0;
}

void maxmin(int N,int arr[], int *big, int *small)
{
    *big = *small = arr[0];
    for(int i = 1; i < N; i++){
        if(arr[i] > *big)
            *big = arr[i];
        else if(arr[i] < *small)
            *small = arr[i];
    }
}