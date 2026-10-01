/*
Suppose that p has been declared as follows:

char *p = "abc";

which of the following function calls are legal? Show the output produced by each legal call, and explain why the others are illegal.

(a) putchar(p);
(b) putchar(*p); --> "a"
(c) puts(p);
(d) puts(*p); --> "abc"


ANS:

(a) Illegal; p is not a character.
(b) Legal; output is a.
(c) Legal; output is abc.
(d) Illegal; *p is not a pointer.


puts prototype
int puts(const char *str); --> must pass char pointer argument == p not *p;

*/