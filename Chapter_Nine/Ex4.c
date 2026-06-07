//Write a function day_of_year(month,day,year) that returns the day of the year(an integer between 1 and 366) 
//specified by the three arguments

#include <stdio.h>


int day_of_year(int month, int day, int year)
{
    int month_conversion[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month_tot;
    
    while((month-1) > 0){
        month_tot += month_conversion[--month];
    }

    return year % 4 == 0 ? day + month_tot : day + month_tot +1;

}

int main(void)
{
    printf("%d\n",day_of_year(6,7,2026));
}

/*
Sample ANS

int day_of_year(int month, int day, int year)
{
  int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_count = 0, i;

  for (i = 1; i < month; i++)
    day_count += num_days[i-1];

//adjust for leap years, assuming they are divisible by 4 
  if (year % 4 == 0 && month > 2)
    day_count++;

  return day_count + day;
}


*/