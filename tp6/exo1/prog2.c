#include <stdio.h>
#include "my_sem.h"

#define clef 1234

int main() {
	printf("prog2\n");
	
	int sem = sem_create(clef, 0);
	
	printf("1_prog2\n");
	printf("2_prog2\n");
	
	P(sem);
	
	
	printf("3_prog2\n");
	printf("4_prog2\n");
	
	
	return 0;
	
}
