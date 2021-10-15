#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main (int argc, char *argv[]) {
	int i = argc;	
	double avg = 0;
	int tmp = 0;
	int sum = 0;
	
	if (argc == 1) {
		printf("Aucune moyenne à calculer");
		return 1;
	}
		

	while ( argc != 0 ) {
		
		tmp = sscanf( *argv++, "%c", "%d" );
		if (tmp > 20 || tmp < 0){
			printf("Note >20 ou <0 : %d\n", tmp);
			return 1;
		}

		sum += tmp;
		argc--;

	}

	avg = sum/(i-1);


	printf("Votre moyenne est de : %f\n", avg);
	return 0 ;
}
