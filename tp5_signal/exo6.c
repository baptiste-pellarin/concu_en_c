#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>
#include <sys/types.h>
int interrupt;

void interruption(){
    printf("\nInterruption\n");
    interrupt=1;
}

int main(){
    interrupt=0;
    pid_t pid_pere = getpid();
    pid_t pid_fils = fork();
    printf("PID pere = %d\nPID fils = %d\n", pid_pere, pid_fils);
    if (!pid_fils){
	signal(SIGUSR1, interruption);
	while(1){
		if (interrupt==1)
		{
		    puts("Je suis le fils");
		    sleep(1);
		}
	}
    }else{
        for(int i=0;i<6;i++){
        puts("Je suis le père"); 
	if (i==3 || i==5){
	    //signal usr1
	}
        sleep(1);
        }
	//signal usr2
    }
    return 0;
}

