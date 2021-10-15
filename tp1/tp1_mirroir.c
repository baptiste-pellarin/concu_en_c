#include <stdio.h>
int main (int argc, char *argv[]) {
	int i = 0;
	int j = 0;

	char* mot = argv[1];
	printf("Mot : %s \n", mot);
	
	
	while(mot[i] != '\0'){
		i++;
	}
	
	for (j=i;j>=0;j--){
		printf("%c", mot[j]);
	}
	printf("\n");
	return 0 ;
}
