#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <fcntl.h>

int main(){

    // sort < fichier | grep chaine | tail -n 5 > sortie
    int fdr = open("fichier",0666);
    int fdr2 = open("sortie",0666);
    int pfd[2];
    int pfd2[2];
    
    int pid, pid2, pid3;
    
    pipe(pfd);
    pipe(pfd2);

    pid = fork();

    if(pid == 0){
        dup2(fdr, 0);
        dup2(pfd[1], 1);

        close(pfd2[0]);
        close(pfd2[1]);
        close(pfd[0]);
        close(pfd[1]);

        execlp("sort","sort",NULL);
    }

    pid2 = fork();

    if(pid2 == 0){
        // grep
        close(pfd[1]);
        close(pfd2[0]);

        dup2(pfd[0], 0);
        dup2(pfd2[1], 1);

        close(pfd2[1]);
        close(pfd[0]);

        execlp("grep", "grep", "chaine", NULL);
    }

    pid3 = fork();

    if (pid3 == 0){
        // tail

        close(pfd[0]);
        close(pfd[1]);
        close(pfd2[1]);

        dup2(pfd2[0], 0);
        dup2(fdr2, 1);
        close(pfd2[0]);

        execlp("tail", "tail", "-n", "5", NULL);
    } 

    // sort < fichier > fichierSorti
    /*int fdr = open("fichier",0666);
    int fdr2 = open("fichierSorti",0666);
    dup2(fdr,0);
    dup2(fdr2,1);
    execlp("sort","sort",NULL);*/

    //sort fichier | grep toto | wc -l
    /*int pfd[2];
    int pid,pid2;
    pipe(pfd);
    pid =fork();
    if (pid==0){
        pid2 = fork();
        if(pid2==0){
            close(pfd[1]);
            dup2(pfd[0],0);
            close(pfd[0]);
            execlp("wc","wc","-l",NULL);
        }else{
            close(pfd[1]);
            dup2(pfd[0],0);
            close(pfd[0]);
            execlp("grep","grep","toto",NULL);
        }
    }else{
        close(pfd[0]);
        dup2(pfd[1],1);
        close(pfd[1]);
        execlp("sort","sort","fichier",NULL);
    }*/

    //cat fichier | wc
    /*
    int pfd[2];
    int pid;
    pipe(pfd);
    pid =fork();
    if (pid==0){
        close(pfd[1]);
        dup2(pfd[0],0);
        close(pfd[0]);
        execlp("wc","wc",NULL);
    }else{
        close(pfd[0]);
        dup2(pfd[1],1);
        close(pfd[1]);
        execlp("cat","cat","fichier",NULL);
    }*/

    return 0;
}
    
    
