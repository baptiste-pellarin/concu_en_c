#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>
#include <sys/types.h>

void interruption(){
    printf("\nInterruption\n");
}

int main(){

    pid_t pid_pere = getpid();
    pid_t pid_fils = fork();
    printf("PID pere = %d\nPID fils = %d\n", pid_pere, pid_fils);

    if (!pid_fils){
	signal(SIGINT, interruption);
        while (1)
        {
            puts("Je suis le fils");
            sleep(1);
        }
    }else{
        for(int i=0;i<3;i++){
        puts("Je suis le père"); 
        sleep(1);
        }

    }
    return 0;
}

