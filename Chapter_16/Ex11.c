/*
Suppose that s is the following structure:

struct {
    double a;
    union{
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} s;

How much space will a C compiler allocate for s?
8 + 8 + 4 = 20 bytes

Solution
A C compiler will allocate twenty bytes for the s structure, 
such that e will be allocated eight bytes.
*/