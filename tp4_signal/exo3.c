#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>
#include <sys/types.h>

int fin;

void interruption(){
    printf("\nInterruption\n");
    fin = 1;
}

int main(){
    fin = 0;
    pid_t pid = getpid();
    printf("PID = %d\n", pid);
    signal(SIGINT, interruption);
    while (!fin)
    {
        //printf("Pas interrompue");
    }
    
    
    
    return 0;
    
}

