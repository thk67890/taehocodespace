#include <stdio.h>
#define print_count(s,count) (printf("%s",s),printf("   count = %d\n",++count))
#define print_count_dw(s,count) \
do{printf("%s",s); printf("   count = %d\n",++count);}\
while(0)


int main(void){
    int count = 0;
    print_count("hohoho",count);

    print_count("hohoho",count);

    print_count("hohoho",count);

    print_count("hohoho",count);

    print_count("hohoho",count);
  
    print_count_dw("hohoho",count);

    print_count_dw("hohoho",count);

    print_count_dw("hohoho",count);

    print_count_dw("hohoho",count);

    print_count_dw("hohoho",count);


}