justify: justify.o line.o word.o
	cc -o justify justify.o line.o word.o

justify.o: justify.c word.h line.h
	cc -c justify.c

line.o: line.h line.c
	cc -c line.c

word.o: word.h word.c
	cc -c word.c