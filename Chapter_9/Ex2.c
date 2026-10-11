//Write a function check(x,y,n) that returns 1 if both x and y fall between 0 and n-1 , inclusive. 
//The function should return 0 otherwise. Assume that x,y, and n are all type int

int check(int x, int y, int n)
{
    if(0<=x && x<=n-1 && 0<=y && y<=n-1)
        return 1;
    else return 0;
}

/*
Sample ANS
int check(int x, int y, int n)
{
  return (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1);
}

Since <= oberators already produces return values 0 or 1, Code can be made more concise by reducing if statement

*/