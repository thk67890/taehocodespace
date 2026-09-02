//void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
/*
Functions Needed
find_closest_flight --> find closest departure time to desired time, retrieve the arrival time of the selected flight
int main --> show prompt, recieve input(&desired_time), call find_closest_flight, print results
*/

#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
int convertor(int hour, int min);

int main(void)
{
    int desired_time;
    float departure_time[8] = {8, 9+43/60, 11+19/60, 12+47/60, 14, 15+45/60, + 19+45/60};
    char arrival_time[8] = {'10:16a.m.','11:52a.m.','1:31 p.m.','3:00p.m.','4:08p.m.','5:55p.m.','9:20p.m.','11:58p.m.'};
    int arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", hour, min);

    desired_time = convertor(hour, min);

    find_closest_flight(desired_time, &departure_time, &arrival_time);
}