/*
Show what the following program will look lke after preprocessing. Some lines of the program may cause compilation errors;
find all such errors.
#define N = 10
#define INC(x) x+1
#define SUB (x,y) x-y
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
    int a[N], i, j, k, m;
#ifdef N
    i = j;
#else
    j = i;
#endif
    i = 10 * INC(j);
    i = SUB(j,k);
    i = SQR(SQR(j));
    i = CUBE(j);
    i = M1(j, k);
    puts(M2(i, j));
#undef SQR
    i = SQR(j);
#define SQR
    i = SQR(j);

    return 0;
}

*/
#include <stdio.h>
#define N = 10 // --> invocates as = 10 not the intended 10
#define INC(x) x+1 
#define SUB(x,y) x-y
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

//blankline
//blankline
//blankline
//blankline
//blankline
//blankline
//blankline
//blankline


int main(void)
{
    int a[= 10], i, j, k, m;
//blankline
    i = j;
//blankline
    //j = i;
//blankline
    i = 10 * j + 1; //--> precedence error!
    i = (x,y) x-y;
    i = (((j) * (j)) * ((j) * (j)));
    i = (((j) * (j)) * (j));
    i = jk; // --> ## pastes tokens but doesn't stringizes them; data type error!
    puts("i" "j"); //-> puts() accepts a single string not two
//blank line
    i = SQR(j); // shouldn't run anything bc it was undefined
//blank line
    i = (j); // ERROR -- Cannot redefine a macro unless exactly identical declaration!

    return 0;
}

/*
Sample ANS
Blank line
Blank line
Blank line
Blank line
Blank line
Blank line
Blank line

int main(void)
{
  int a[= 10], i, j, k, m;

Blank line
  i = j;
Blank line
Blank line
Blank line

  i = 10 * j+1;
  i = (x,y) x-y(j, k);
  i = ((((j)*(j)))*(((j)*(j))));
  i = (((j)*(j))*(j));
  i = jk;
  puts("i" "j");

Blank line
  i = SQR(j);
Blank line
  i = (j);

  return 0;
}
Some preprocessors delete white-space characters at the beginning of a line, so your results may vary. Three lines will cause errors when the program is compiled. Two contain syntax errors:

int a[= 10], i, j, k, m;
i = (x,y) x-y(j, k);
The third refers to an undefined variable:

i = jk;
*/