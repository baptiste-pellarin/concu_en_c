#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <fcntl.h>
#include <time.h>


int main() {

	srand(time(NULL));
	
	pid_t filtreImpaire, filtrePaire, generateur;
	
	int pipeImpaire[2], pipePaire[2], randint;
	
	int nombresGeneres[100];
	
	pipe(pipeImpaire);
	pipe(pipePaire);
	
	close(pipePaire[0]);
	close(pipeImpaire[0]);
	for(int i =0; i< 100; i++) {
		
		
		randint = rand()%100;
		printf("%i\n", randint);
		if (randint % 2){
			write(pipePaire[1], randint, sizeof(int));
		} else {
			write(pipeImpaire[1], randint, sizeof(int));
		}
		  
	}
	
	close(pipeImpaire[1]);
	close(pipePaire[1]);

	
	/*
	
	pid_t generateur = fork();
	
	if (generateur == 0){
		
		int randint = rand();
		
		if (randint % 2 == 0){
			close(pipePaire[0]);
			write(pipePaire[1], randint, strlen(randint));
			close(pipePaire[1]);
		} else {
			close(pipeImpaire[0]);
			write(pipeImpaire[1], randint, strlen(randint));
			close(pipeImpaire[1]);
		}
		
	}
	
	pid_t filtreImpaire = fork();
	
	if (filtreImpaire == 0) {
	
	}
	
	*/
	
	
	
	
	
	return 0;
}
