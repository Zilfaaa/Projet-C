//PROJET C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

char * SaisieChaine(){
    char *s;
    char buffer[NMAX];
    printf("Entrez une IP : ",NMAX-1);
    fflush(stdout);
    fgets(buffer,NMAX-1,stdin);
    s = (char *)malloc((strlen(buffer)+1)*sizeof(char));
    if (!s){
        printf("Problème d'alloc mémoire");
        exit(0);
    }
    strcpy(s,buffer);
    return s;
}

int main(int argc, char *argv[]){
    FILE* fic = NULL;
    char *IP;

    fic = fopen("test.txt", "w");
 
    if (fic != NULL)
    {

        IP = SaisieChaine();

        fprintf(fic,IP);
        fclose(fic);

        fgets(IP,NMAX,fic);
        printf("%s",IP);
    }
 
    return 0;
}