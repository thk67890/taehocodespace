#include <stdio.h>
#include <stdbool.h>

#define N 10

double ident[N][N];
int row,col;
double *ptr;

/*
for(row = 0; row < N; row ++)
    for(col = 0; col < N; col++)
        if(row == col)
            ident[row][col] = 1.0;
        else
            ident[row][col] = 0.0;
*/

void process(void)
{
    int count = 10;
    for(ptr = &ident[0][0]; ptr <= &ident[N-1][N-1]; ptr++){
        if(count == 10){
            *ptr = 1.0;
            count = 0;
        }
        else{
            *ptr = 0.0;
            count++;
        }
    }
}

void print(void)
{
    int count = 0;
    for(ptr = &ident[0][0]; ptr < &ident[N][N]; ptr++){
        if(count != 9){
            printf("%lf ",*ptr);
            count++;
        }
        else{
            printf("%lf", *ptr);
            printf("\n");
            count = 0;
        }
    }
}

int main(void){
    process();
    print();
}

/*
Sample ANS
#define N 10

double ident[N][N], *p;
int num_zeros = N;

for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++)
  if (num_zeros == N) {
    *p = 1.0;
    num_zeros = 0;
  } else {
    *p = 0.0;
    num_zeros++;
  }
*/