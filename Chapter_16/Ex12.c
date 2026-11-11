/*
Suppose that u is the following union:
union {
    double a; --> 8 bytes
    struct { --> 16 bytes
        char b[4]; --> 4 bytes
        double c; --> 8 bytes
        int d; --> 4 bytes
    } e;
    char f[4]; --> 4 bytes
} u;

how much sace will a C compiler allocate for u?
16 bytes


Solution
A C compiler will allocate 16 bytes for the u union, 
such that its largest member e will have 16 bytes allocated for itself.
*/