/*
Makefile

main: main.o fl.o f2.o
    cc -o main main.o fl.o f2.o

main.o: main.c f1.h
    cc -c main.c

f1.o: f1.c fl.h f2.h
    cc -c f1.c

f2.o: f2.c f1.h f2.h
    cc -c f2.c

(a) Which files need to be compiled when the program is built for the first time?
-> All files

(b) If f1.c is changed after the program has been built, which files need to be recompiled?
-> f1.c

(c) If f1.h is changed after the program has been built, which files need to be recompiled?
-> f1.c f2.c main.c

(d) If f2.h is changed after the program has been built, which files need to be recompiled?
-> f1.c f2.c

*/