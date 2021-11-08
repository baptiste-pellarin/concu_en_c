#include <stdio.h>
#include "../my_sem.h"

#define clef_1 1234
#define clef_2 5678


int main(){


    sem_create(clef_1, 0);
    sem_create(clef_2, 0);



    return 0;
}