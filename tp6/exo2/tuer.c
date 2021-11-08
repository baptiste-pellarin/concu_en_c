#include <stdio.h>
#include "../my_sem.h"

#define clef_1 1234
#define clef_2 5678

int main(){
	printf("on passe le balais\n");
	
	int sem1 = sem_create(clef_1, 0);
	int sem2 = sem_create(clef_2, 0);

	sem_delete(sem1);
	sem_delete(sem2);
	
	return 0;
}
