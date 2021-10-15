#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid = fork();
    if (pid==0){
       execlp("/bin/echo","/bin/echo", "test", NULL); 

    }
    printf("PID %d\n", pid);
    execlp("/bin/ls","/bin/ls", NULL);
    return 0;
}