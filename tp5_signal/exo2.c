#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>
#include <sys/types.h>

void interruption(){
    printf("\nInterruption\n");
    exit(1);
}

int main(){
    
    pid_t pid = getpid();
    printf("PID = %d\n", pid);
    signal(SIGINT, SIG_IGN);
    while (1)
    {
        //printf("Pas interrompue");
    }
    
    
    
    return 0;
    
}

