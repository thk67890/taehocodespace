#include <stdio.h>

struct time{
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_second);

int main(void){
    struct time print_time;
    print_time = split_time(900);
    printf("hours: %d\nminutes: %d\nseconds: %d\n",print_time.hours, print_time.minutes,print_time.seconds);

}

struct time split_time(long total_seconds){
    
    struct time return_time;    
    return_time.hours = total_seconds / 3600;

    total_seconds %= 3600;

    return_time.minutes = total_seconds / 60;

    total_seconds %= 60;

    return_time.seconds = total_seconds;

    return return_time;

}

