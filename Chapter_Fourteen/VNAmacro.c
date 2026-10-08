//Variable Number Argument Macros
#include <stdio.h>
#define TEST(condition, ...) ((condition) ? \
printf("Passed test: %s\n", #condition) : \
printf(__VA_ARGS__))

int main(void){
    int voltage = 170, max_voltage = 150;
    TEST(voltage <= max_voltage, "%s,%s,%s", "Taeho","Kang", "Les go");
}

//__VA_ARGS__ holds all of the arguments corresponding the ellipsis in the exact format that they were input
// __VA_ARGS__ = {"%s,%s,%s", "Taeho", "Kang","Les go"}
// Replacing __VA_ARGS__ in printf(__VA_ARGS__) results in printf("%s,%s,%s", "Taeho", "Kang","Les go")