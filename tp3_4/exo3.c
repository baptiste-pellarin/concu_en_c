/*
	Baptiste PELLARIN - Julien Gautron (2021/2022)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>

#define NB_RAND 5

int main() {

	srand(getpid());
		
	int pipeImpaire[2], pipePaire[2], sommePaire[2], sommeImpaire[2], randint;
		
	pipe(pipeImpaire);
	pipe(pipePaire);
	pipe(sommeImpaire);
	pipe(sommePaire);

	if(!fork()){

		printf("Générateur\n");
	
		close(pipePaire[0]);
		close(pipeImpaire[0]);
		close(sommeImpaire[1]);
		close(sommePaire[1]);

		for(int i =0; i< NB_RAND; i++) {
			
			
			randint = rand()%100;

			//printf("Gen %i\n", randint);
			if (randint % 2 == 0){
				write(pipePaire[1], &randint, sizeof(int));
			} else {
				write(pipeImpaire[1], &randint, sizeof(int));
			}
			
		}

		randint = -1;

		write(pipeImpaire[1], &randint, sizeof(int));

		write(pipePaire[1], &randint, sizeof(int));

		int somme_totale = 0, somme_impaire = 0, somme_paire = 0;	

		read(sommeImpaire[0], &somme_impaire, sizeof(int));
		read(sommePaire[0], &somme_paire, sizeof(int));

		somme_totale = somme_impaire + somme_paire;

		printf("\n-------\nTotal Paire : %i\nTotal Impaire : %i\nTotal : %i\n", somme_paire, somme_impaire, somme_totale);

		
		close(sommeImpaire[0]);
		close(sommePaire[0]);
		close(pipeImpaire[1]);
		close(pipePaire[1]);
		exit(0);
	}

	if(!fork()){
		close(pipeImpaire[1]);
		close(pipeImpaire[0]);
		close(sommeImpaire[0]);
		close(sommeImpaire[1]);
		close(sommePaire[0]);
		close(pipePaire[1]);


		int nombre = 0, somme=0;
		//printf("Filtre paire\n");

		while(nombre != -1){

			read(pipePaire[0], &nombre, sizeof(int));
			if(nombre >= 0){
				printf("%d paire\n", nombre);
				somme = somme + nombre;
			} else {
				printf("Fin pipe\n");
			}
			//printf("Somme paire %d\n", somme);
		}

		if(write(sommePaire[1], &somme, sizeof(int)) == -1){
			perror("Erreur ecriture dans le pipe");
		}

		close(pipePaire[0]);
		close(sommePaire[1]);
		exit(0);

	}
	



	if(!fork()){
		close(pipeImpaire[1]);
		close(sommeImpaire[0]);
		close(sommePaire[1]);
		close(sommePaire[0]);
		close(pipePaire[0]);
		close(pipePaire[1]);

		int nombre = 0, somme = 0;
		//printf("Filtre impaire\n");

		while(nombre != -1){

			read(pipeImpaire[0], &nombre, sizeof(int));
			if(nombre >= 0){
				printf("%d impaire\n", nombre);
				somme = somme + nombre;
			} else {
				printf("Fin pipe\n");
			}
			//printf("Somme impaire %d\n", somme);
		}
		if(write(sommeImpaire[1], &somme, sizeof(int)) == -1){
			perror("Erreur ecriture dans le pipe");
		}


		close(pipeImpaire[0]);
		close(sommeImpaire[1]);

		exit(0);

	}

	while(wait(NULL) != -1);

	
	
	return 0;
}
