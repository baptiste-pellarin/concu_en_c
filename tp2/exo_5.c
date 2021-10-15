#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    
    for (int i=1;i<argc;i++){
        char* fichier = argv[i];
        //printf("\n%s - test\n", fichier);	
        pid_t pid = fork();
        if (pid==0 && fichier){
            execlp("/usr/bin/gcc","gcc","-c",fichier, NULL);
            exit(0);
        }	
    }
    
    
    for (int i=1;i<argc;i++){
        wait(NULL);
    }
    char* fichiers[argc+3];
    char* temp;	
    
    fichiers[0] = "gcc";
    fichiers[1] = "-o";
    fichiers[2] = "output";
    
    for(int i = 1; i<argc; i++){
        temp = argv[i];		
        temp[strlen(temp)-1] = 'o';
        fichiers[i+2] = temp;
    }
    fichiers[argc+2] = NULL;
    
   // for(int i = 0; i < argc+2 ; i++)
     //   puts(fichiers[i]);
    
    execvp("gcc",fichiers);
    
    return 0;
}
