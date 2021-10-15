#include <stdio.h>
#include "my_sem.h"

#define clef 1234

int main () {
	printf("N°1\n");
	
	int sem = sem_create(clef, 0);
	
	printf("1_prog1\n");
	printf("2_prog1\n");
	
	V(sem);
	
	printf("3_prod1\n");
	printf("4_prod1\n");
	
	return 0;
	
}
