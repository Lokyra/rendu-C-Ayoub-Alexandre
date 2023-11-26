/*
* Objectif : Determine l'ecart entre 2 entiers (exercice 2)
* Date     : 09/11/2023
* Auteur   : Fouillit Alexandre et Bousbia Ayoub
*/

#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    int value;
    int buff;
    int temp;
    int run = 1;
    int count = 0;

    while (run) {

        printf("Entrer le nombre d'entiers que vous voulez comparer : ");
        scanf("%d", &n);

        printf("\nEntrer un nombre : ");
        scanf("%d", &value);

        temp = value;

        for (int i = n-1; i > 0;--i) {
            do {
                printf("\nEntrer le prochain nombre : ");
                scanf("%d", &value);
                if (value <= temp)
                    printf("\nLa valeur suivante doit etre superieure a la precedente\n");
            } while (value <= temp);

            buff = value;

            while (temp < buff - 1) {
                temp++;
                printf("\nLe nombres manquant est : %d", temp);
                count++;
            }

            temp = buff;
        }

        printf("\n\nIl y a %d nombre manquants\n", count);

        printf("\nVoulez-vous relancer le programme : Taper 1 si oui 0 sinon : ");
        scanf("%d", &run);

    }

    return 0;
}
