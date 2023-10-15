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

int main(int argc, char *argv[]) {

    FILE* fic = NULL;

    char *IP;
    char *TABips[NMAX];
    int compteurIP = 0;

    fic = fopen("test.txt", "a+");

    if (fic != NULL) {

        int nbIPs;
        char m;

        printf("*****MENU*****\n");
        printf("a : Saisie IP\n");
        printf("b : Affichage IP\n");
        printf("c : Convertir IP\n");
        printf("d : Recherche IP masque\n");
        printf("e : Quitter\n");

        printf("Choix : ");
        scanf("%c",&m);
        switch (m)

        {
        case 'a' :  
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
                    break;
        
        case 'b' : 
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
                    break;

        case 'c' : 
                    char choix;
                    printf("\na : Convertir en base 2\n");
                    printf("b : Convertir en base 16\n");
                    scanf("%c",&choix);

                    /* if (choix == "a"){

                    }
                    else if (choix == "b")
                    {
                        
                    } */
                    
                    break;
        default:
            break;
        }

    } else {
        printf("Impossible d'ouvrir le fichier.\n");
    }

    return 0;

}