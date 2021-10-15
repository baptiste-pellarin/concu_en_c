CFLAGS=-Wall -Wextra -g
VPATH = bin


all: prog1 prog2 tuer

tuer: tuer.o my_sem.o

prog1: my_sem.o prog1.o

prog2: my_sem.o prog2.o

tuer.o: tuer.c my_sem.h
my_sem.o: my_sem.h my_sem.c
prog1.o: my_sem.h prog1.c
prog2.o: my_sem.h prog2.c
