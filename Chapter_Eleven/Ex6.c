/*
Write the following function:
void find_two_largest(int a[], int n, int *largest, int *second_largest);
When passed an array a of length n, the function will search a for its largest and 
second largest elements, storing them in the variables pointed to by largest and 
second_largest, respectively
*/

#include <stdio.h>
#include <stdlib.h>

int largest, second_largest, n = 10, arr[] = {0,5,12,53,63,27,42,12,64,23};

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    find_two_largest(arr, n, &largest, &second_largest);
    printf("\nLargest Number: %d\nSecond Largest Number: %d\n",largest, second_largest);

    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int temp = 0;
    *largest = *second_largest = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > *second_largest){
            *second_largest = arr[i];

        }
        if(*second_largest > *largest){
            temp = *largest;
            *largest = *second_largest;
            *second_largest = temp;
        }
    }
}

/*
Example Ans:
void find_two_largest(int a[], int n, int *largest,
                      int *second_largest)
{
  int i;

  if (a[0] > a[1]) {
    *largest = a[0];
    *second_largest = a[1];
  } else {
    *largest = a[1];
    *second_largest = a[0];
  }

  for (i = 2; i < n; i++)
    if (a[i] > *largest) {
      *second_largest = *largest;
      *largest = a[i];
    } else if (a[i] > *second_largest)
      *second_largest = a[i];
}

I Like my algorithm better for this one.
*/