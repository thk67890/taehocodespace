//Write a function that returns the following values. (Assume that a and n are parameters, where a is an array of int values and n is the length of the array.)
// (a) The largest element in a.
// (b) The average of all elements in a.
// (c) The number of positive elements in a.

#include <stdio.h>

int largest_element(int a[], int n);
int average_element(int a[], int n);
int number_positive(int a[], int n);

int main(void)
{
    int a[] = {1,5,4,3,-3};

    printf("largest element: %d\n",largest_element(a, 5));
    printf("average of elements: %d\n", average_element(a,5));
    printf("number of positive elements: %d\n", number_positive(a,5));
}

//(a)
int largest_element(int a[], int n)
{
    int temp = 0, Max = a[0];
    for(int i = 0; i < n; i++){
        temp = a[i];
        if (temp > Max){
            Max = temp;
        }
    }
    return Max;
}

//(b)
int average_element(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    return sum/5;
}

//(c)
int number_positive(int a[], int n){
    int pos_count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0) pos_count++;
    }

    return pos_count;
}

/*
Sample ANS
(a)

int largest(int a[], int n)
{
  int i, max = a[0];

  for (i = 1; i < n; i++)
    if (a[i] > max) --> Temp unecessary!! We're not Sorting or Moving numbers around so no need to use another variable
      max = a[i];

  return max;
}
(b)

int average(int a[], int n)
{
  int i, avg = 0;

  for (i = 0; i < n; i++)
    avg += a[i];

  return avg / n;
}
(c)

int num_positive(int a[], int n)
{
  int i, count = 0;

  for (i = 0; i < n; i++)
    if (a[i] > 0)
      count++;

  return count;
}
  */