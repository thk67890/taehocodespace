/*
Write calls of printf that display a float variable x in the following formats.
    (a) Exponential notation; left-justified in a field of size 8; one digit after the decimal point
    (b) Exponential notation; right-justified in a field of size 10; six digits after the decimal point
    (c) Fixed-point notation; left-justified in a field of size 8; three digits after the decimal point
    (d) Fixed-point notation; right-justified in a field of size 6; no digits after the decimal point
*/

(a) printf("%-8.1e", a);
(b) printf("%10.6e", a);
(c) printf("%-8.3f", a);
(d) printf("%6.0f", a);

