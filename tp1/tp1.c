#include <stdio.h>
int main (int argc, char *argv[]) {
	int i;
	printf ("Nom du programme : %s\n", argv[0]);
	printf ("Nbre arg de la lgn de cmd : %d\n", argc-1);
	printf ("Les arguments sont : ");
	for (i=1;i<argc;i++){
		printf("\t%d : %s\n", i, argv[i]);
	}
	return 0 ;
}
