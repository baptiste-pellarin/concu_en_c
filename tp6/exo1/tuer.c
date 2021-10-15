#include <stdio.h>
#include "my_sem.h"

#define clef 1234

int main(){
	printf("on passe le balais\n");
	
	int sem = sem_create(clef, 1);
	
	sem_delete(sem);
	
	return 0;
}
