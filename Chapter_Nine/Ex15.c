//The following (rather confusing) function finds the median of three numbers. 
//Rewrite the function so that it has just one return statement.

/*/
double median(double x, double y, double z)
{
    if(x == y)
        if(y <= z) return y;
        else if(x <= z) return z;
        else return x;
    if (z <= y) return y;
    if (x <= z) return x;
}
*/

#include <stdio.h>

double median(double x, double y, double z);
double median_attempt_Two(double x, double y, double z);

int main(void)
{
    printf("Median: %0.1f\n", median_attempt_Two(5,7,2));
}

double median(double x, double y, double z)
{
    int median;
    while(1){
        if (x <= y)
            if(y <= z){ 
                median = y;
                break;
            }

            else if (x <= z){
                median = z;
                break;
            }
            else {
                median = x;
                break;
            }
        
            if (z <= y) median = y;
        if (x <= z) median = x;
        
        break;
    }
    return median;
}

/*
Sample ANS
double median(double x, double y, double z)
{
  double result;

  if (x <= y)
    if (y <= z) result = y;
    else if (x <= z) result = z;
    else result = x;
  else {
    if (z <= y) result = y;
    else if (x <= z) result = x;
    else result = z;
  }

  return result;
}
  
*/

double median_attempt_Two(double x, double y, double z)
{
    int median;
    
    if (x <= y)
        if(y <= z){ 
            median = y;
        }

        else if (x <= z){
            median = z;
        }
        else {
            median = x;
        }
    
    else if (z <= y) median = y;
    else median = x;
    
    
    return median;    

}