#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
    int pid, df1, df2;
    char carac;
    df1 = open("entree",O_RDONLY);
    df2=creat("sortie",0666);
    FILE *trace = fopen("trace","w");
    fprintf(trace, "le caractère '#' indique que c'est le processus fils qui s'exécute \n");
    fprintf(trace, "le caractère '$' indique que c'est le processus père qui s'exécute \n");
    fflush(trace);
    pid=fork();
    printf("Création de Processus\n");
    while (read (df1, & carac,sizeof(char))>0){ //tant que le fichier n'a pas été lu entièrement
        if (pid ==0) fprintf(trace,"#%c", carac);
        else fprintf(trace,"$%c",carac);
        fflush(trace);
        write(df2,& carac, sizeof(char));
    }
    printf("Sortie de la boucle while \n");
    close(df1);close(df2);
    return 0;

}