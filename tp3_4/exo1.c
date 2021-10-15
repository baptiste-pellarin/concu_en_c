#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h> 

int main(){
    int tube[2];
    unsigned char buffer[256];
    int i;
    
    printf("Création du tube\n");
    if (pipe(tube) != 0){
        perror("Problème - création du tube\n");
        exit(1);
    }
    for(i =0; i< 256; i++) buffer[i] = i;
    
    printf("Ecriture dans le tube\n");
    
    if(write(tube[1], buffer, 256) != 256){
        perror("Problème - Ecriture dans le tube\n");
        exit(1);
    }
    printf("Lecture depuis le pipe\n");
    if(read(tube[0], buffer, 256)!=256){
        perror("Problème - Lecture depuis le tube\n");
        exit(1);
    }
    
    return 0;
    
}
    
    
