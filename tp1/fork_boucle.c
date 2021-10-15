#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    for(int k =0; k<3; k++){
        pid_t ppid = getppid();
        int retour = fork();
        
        pid_t pid = getpid();
        printf("%d : je suis le processus : %d, mon prere est %d, retour: %d\n", k, pid, ppid, retour );
    }
    exit(10);

}