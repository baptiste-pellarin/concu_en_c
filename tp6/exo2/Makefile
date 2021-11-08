CFLAGS=-Wall -Wextra -g
VPATH = bin


all: P1 P2 tuer create

P1: ../my_sem.o P1.o
tuer: tuer.o ../my_sem.o
create: create.o ../my_sem.o

P2: ../my_sem.o P2.o

P1.o: ../my_sem.h P1.c
P2.o: ../my_sem.h P2.c
tuer.o: ../my_sem.h tuer.c
create.o: ../my_sem.h create.c

../my_sem.o: ../my_sem.c ../my_sem.h
	$(CC) -c $< -o $@ 
