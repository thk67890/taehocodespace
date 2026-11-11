/*
Suppose that b and i are declared as follows:
enum {FALSE, TRUE} b;
int i
Which of the following statements are legal? Which ones are "safe" (always yield a meaningful result)?
(a) b = FALSE; --> Legal
(b) b = i; -->Illegal 
(c) b++; --> Illegal
(d) i = b; --> Legal
(e) i = 2 * b + 1 --> Legal


*/