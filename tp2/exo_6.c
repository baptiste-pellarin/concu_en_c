#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    
    int i,n=0;
    pid_t pid;
    for(i=1;i<5;i++){
        pid = fork(); /*1*/
        if(pid>0){  /*2*/
            //wait(NULL); /*3*/
            n=i*2;
            break;
        }
    }
    printf("%d\n",n);
    return 0;
}

/*
 Q1 : on se retrouve dans le père. Le pid vaut 0 pour le fils
 Q2 : Il est déterministe car rien ne changera si on le lance. Il n'y a pas de variable.
 Q3 : Plus maintenant, le wait permet d'attendre que les fils finissent avant que le père se finisse.
 Q4 : 2 4 6 8 0 ou encore 2 4 6 0 8
 Q5 : oui car quand le programme est exécuté l'appel fork peut-être réalisé en double causant une boucle infinie 
 
 
 */
