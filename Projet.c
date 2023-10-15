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

/*typedef struct IP{
    char * IP;
}IP;

typedef IP IPs[NMAX];


void SaisieIP(IP * ip){
    char buffer[NMAX];
    printf("IP : ");
    fgets(buffer,NMAX-1,stdin);
    ip->IP = (char *)calloc(strlen(buffer)+1, sizeof(char));
    strcpy(ip->IP,buffer);
    if (!ip->IP){
		printf("Erreur d'allocation !\n");
		exit(0);
	}
}

void SaisieIPs(IPs ips){
    int i; 
    for (i=0;i<NMAX;i++){
        printf("Saisie IP %d",i+1);
        SaisieIP(&(ips[i]));
    }
}*/


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

int main(int argc, char *argv[]) {

    FILE* fic = NULL;

    char *IP;
    char *TABips[NMAX];
    int compteurIP = 0;

    fic = fopen("test.txt", "a+");

    if (fic != NULL) {

        int nbIPs;

        printf("Combien d'adresses IP voulez-vous saisir ? ");
        scanf("%d", &nbIPs);
        getchar();

        for (int i = 0; i < nbIPs && compteurIP < NMAX; i++) {

            IP = SaisieIP();

            if (IPValide(IP)) {
                fprintf(fic, "%s\n", IP);
                TABips[compteurIP] = strdup(IP);
                compteurIP++;

            } else {
                printf("L'adresse IP saisie n'est pas valide.\n");
            }
        }

        fclose(fic);

        /*printf("Voici les adresses IP valides saisies :\n");
        for (int i = 0; i < compteurIP; i++) {
            printf("%s\n", TABips[i]);
        }*/

        printf("Adresses IP sauvegardées :\n");

        fic = fopen("test.txt", "r");

        if (fic != NULL) {
            char buffer[NMAX];
            while (fgets(buffer, NMAX, fic) != NULL) {
                printf("%s", buffer);
            }
            fclose(fic);
            
        } else {
            printf("Impossible d'ouvrir le fichier pour la lecture.\n");
        }

    } else {
        printf("Impossible d'ouvrir le fichier.\n");
    }

    return 0;

}
