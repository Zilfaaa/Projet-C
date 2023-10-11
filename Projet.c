//PROJET C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NMAX 100


char * SaisieIP(){
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

bool IPValide(const char *ip) {
    int segments[4];
    int numSegments = sscanf(ip, "%d.%d.%d.%d", &segments[0], &segments[1], &segments[2], &segments[3]);

    if (numSegments != 4) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        if (segments[i] < 0 || segments[i] > 255) {
            return false;
        }
    }

    return true;
}

int main() {
    FILE* fic = NULL;
    char *IP;

    fic = fopen("test.txt", "w");
 
    if (fic != NULL) {

        IP = SaisieIP();
        
        if (IPValide(IP)) {
            fprintf(fic, "%s", IP);
            fclose(fic);

            printf("Voici l'IP saisie : %s\n", IP);
        } else {
            printf("L'adresse IP saisie n'est pas valide.\n");
        }
    } else {
        printf("Impossible d'ouvrir le fichier.\n");
    }
 
    return 0;
}



