//int main() --> prompt user to enter country code, call function, print results
//find() --> find matching country name to country code input

#include <stdio.h>
#define NUM_COUNT 32

struct dialing_code{
    char *country;
    int code;
};

const struct dialing_code country_codes[NUM_COUNT + 1] = 
{{"Argentina",            54}, {"Bangladesh",      880},
 {"Brazil",               55}, {"Burma (Myanmar)",  95},
 {"China",                86}, {"Colombia",         57},
 {"Congo, Dem. Rep. of", 243}, {"Egypt",            20},
 {"Ethiopia",            251}, {"France",           33},
 {"Germany",              49}, {"India",            91},
 {"Indonesia",            62}, {"Iran",             98},
 {"Italy",                39}, {"Japan",            81},
 {"Mexico",               52}, {"Nigeria",         234},
 {"Pakistan",             92}, {"Philippines",      63},
 {"Poland",               48}, {"Russia",            7},
 {"South Africa",         27}, {"South Korea",      82},
 {"Spain",                34}, {"Sudan",           249},
 {"Thailand",             66}, {"Turkey",           90},
 {"Ukraine",             380}, {"United Kingdom",   44},
 {"United States",         1}, {"Vietnam",          84}};

int find(int code);

int main(void)
{
    int code,temp;

    printf("Enter Country Code: ");
    scanf("%d", &code);
    
    temp = find(code);

    if(temp == -1)
        printf("Wrong Code");
    else
        printf("The code is for %s\n", country_codes[find(code)].country);

    
    return 0;
}

int find(int code)
{
    int i;

    for(i = 0; i < NUM_COUNT; i++){
        if(country_codes[i].code == code)
            return i;
    }

    return -1;
}