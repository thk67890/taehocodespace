/*
(a) Show how to declare a tag named complex for a structure with two members, real and imaginary, of type double
(b) Use the complex tag to declare variables named c1,c2, and c3.
(c) Write a function named make_complex that stores its two arguments(both of type double) in a complex structure, then returns the structure
(d) Write a function named add_complex that adds the corresponding members of its arguments(both complex structures), then returns
the result (another complex structure)

*/

//a
struct complex{
    double real;
    double imaginary;
};

//b
struct complex c1,c2,c3;

//c
struct complex make_complex(double real, double imaginary){
    struct complex return_complex;
    return_complex.imaginary = imaginary;
    return_complex.real = real;

    return return_complex;
}



//d
struct complex add_complex(struct complex a, struct complex b){
    struct complex return_complex;
    return_complex.imaginary = a.imaginary + b.imaginary;
    return_complex.real = a.real + b.real;

    return return_complex;
}