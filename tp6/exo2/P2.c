#include <stdio.h>
#include "../my_sem.h"

#define clef_1 1234
#define clef_2 5678

int main(){

    printf("P2\n");
	
	int sem1 = sem_create(clef_1, 0);
    int sem2 = sem_create(clef_2, 0);
	
	printf("1_P2\n");
	printf("2_P2\n");
    
    V(sem2);
	P(sem1);
	
	//fct rdv
	printf("3_P2\n");
	printf("4_P2\n");
	
    return 0;
}