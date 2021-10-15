#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    if (fork() == 0) {
        execlp("/usr/bin/who","who",NULL);
        exit(0);
    }

    if (fork() == 0) {
        execlp("ps","ps",NULL);
        exit(0);
    }

    if (fork() == 0) {
        execlp("ls","ls","-l",NULL);
        exit(0);
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);

    exit(0);

}