//void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
/*
Functions Needed
find_closest_flight --> find closest departure time to desired time, retrieve the arrival time of the selected flight
convertor --> converts hour and min val into int val
int main --> show prompt, recieve input(&desired_time), call find_closest_flight, print results
*/

#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int desired_time;
    int departure_time = 0, arrival_time = 0;
    printf("Enter a desired time in minutes after midnight: ");
    scanf("%d", &desired_time);

    find_closest_flight(desired_time, &departure_time, &arrival_time);
    
    printf("Clostest departure time is %d minutes from midnight, arriving %d minutes from midnight\n", departure_time, arrival_time);

}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int departure_time_list[8] = {240,137,41,47,120,225,420,585};
    int arrival_time_list[8] = {104,8,91,180,248,355,560,718};
    int temp = abs(desired_time - departure_time_list[0]);
    for(int i = 1; i < 8; i++){
        if(temp > abs(desired_time - departure_time_list[i])){
            temp = abs(desired_time - departure_time_list[i]);
            *departure_time = departure_time_list[i];
            *arrival_time = arrival_time_list[i];
        }
    }
}