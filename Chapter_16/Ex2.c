/*
(a) Declare structure variables named c1, c2, and c3, each having members real and imaginary of type double
(b) Modify the declaration in part (a) so that c1's members initially have the values 0.0 and 1.0, while 
c2's members are 1.0 and 0.0 initially. (c3 is not initialized)
(c) Write statements that copy the members of c2 into c1. Can this be done in one statement? or does it require two?
(d) Wrtie statements that add the corresponding members of c1 and c2, storing the results in c3.

*/

//(a)
/*
struct{
    double real;
    double imaginary;
} c1,c2,c3;
*/

//(b)
struct{
    double real;
    double imaginary;
} c1 = {0.0,1.0}, c2 = {1.0,0.0}, c3;

int main(void){


//(c)
c1=c2;//Cannot be outside of a function; Only Varaible, function, macro declarations can be outside.

//(d)
c3.real = c1.real + c2.real;
c3.imaginary = c1.imaginary + c2.imaginary;


}