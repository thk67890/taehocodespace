/*
Write the following function, assuming that the time structure contains three members: month, day, and year(all of type int)
(a) int day_of_year(struct date d);
Returns the day of the year (an integer between 1 and 366) that corresponds to date d
(b) int compare_dates(struct date d1, struct date d2);
Returns -1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2, and 0 if d1 and d2 are the same.
*/

struct date{
    int month;
    int day;
    int year;
};

int day_of_year(struct date d){
    int temp = d.day;
    while(d.month > 0){
        if(d.month % 2 == 0 || d.month != 8){
            temp += 30;
        }
        else
            temp += 31;
        d.month--;
    }
    return temp;
}

int compare_dates(struct date d1, struct date d2){
    if(d1.year > d2.year)
        return -1;
    else if(d1.year < d2.year)
        return 1;
    else if(d1.month > d2.month)
        return -1;
    else if(d1.month < d2.month)
        return 1;
    else if(d1.day > d2.day)
        return -1;
    else if(d1.day < d2.day)
        return 1;
    else return 0;
}

//a > b: c ? 