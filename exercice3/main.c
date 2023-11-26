/*
 * Objectif : determiner 9 zones selon 2 points donnes par l'utilisateur (exercice 3)
 * Date     : 15/11/2023
 * Auteur   : Bousbia Ayoub
 */

#include <stdio.h>

int main(int argc, char **argv) {

    int width;
    int height;

    int x1, y1;
    int x2, y2;
    int x, y;

    int run = 1;

    while (run) {
        do {
            printf("\nSaisir une largeur : ");
            scanf("%d", &width);
            if (width <= 0)
                printf("\nVotre largeur doit etre superieur a 0\n");

        } while (width <= 0);

        do {
            printf("\nSaisir une hauteur : ");
            scanf("%d", &height);
            if (height <= 0)
                printf("\nVotre hauteur doit etre superieur a 0 ");
        } while (height <= 0);

        do {
            printf("\nSaisir les coordonees de a (x1 y1) : ");
            scanf("%d %d", &x1, &y1);
            if (x1 < 0 || x1 > width - 1 )
                printf("x doit etre superieur ou egale a 0 et inferieur ou egale a largeur - 1");
            if(y1 < 0 || y1 > height - 1)
                printf("y doit etre superieur ou egale a 0 et inferieur ou egale a heuteur - 1");
        } while (x1 < 0 || x1 > width - 1 || y1 < 0 || y1 > height - 1);

        do {
            printf("\nSaisir les coordonees de b (x2, y2) : ");
            scanf("%d %d", &x2, &y2);
        } while (x2 < 0 || x2 > width - 1 || y2 < 0 || y2 > height - 1);



        printf("Coordonees des 9 zones : \n");
        printf("Zone 1 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", 0, 0, x1, 0, 0, y1, x1, y1);
        printf("Zone 2 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x1, 0, x2, 0, x1, y1, x2, y1);
        printf("Zone 3 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x2, 0, width-1, 0, x2, y1, width-1, y1);
        printf("Zone 4 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", 0, 0, x1, y1, 0, y2, x1, y2);
        printf("Zone 5 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y1, x1, y2, x2, y2);
        printf("Zone 6 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x2, y1, width-1, y1, x2, y2, width-1, y2);
        printf("Zone 7 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", 0, 0, x1, y2, x1, height-1, 0, height-1);
        printf("Zone 8 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x1, y2, x2, y2, x1, height-1, x2, height-1);
        printf("Zone 9 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x2, y2, width-1, y2, x2, height-1, width-1, height-1);



        printf("\nEntrer les coordonees d'un point pour determiner son emplacement :  ");
        scanf("%d %d", &x, &y);

        if (x <= x1 && x >= 0) {
            if (y < y1 && y >= 0) {
                printf("Votre point se situe sur la Zone 1\n");
            } else if (y >= y1 && y <= y2) {
                printf("Votre point se situe sur la Zone 4\n");
            } else {
                printf("Votre point se situe sur la Zone 7\n");
            }
        } else if (x > x1 && x < x2) {

            if (y <= y1 && y >= 0) {
                printf("Votre point se situe sur la Zone 2\n");
            } else if (y >= y1 && y <= y2) {
                printf("Votre point se situe sur la Zone 5\n");
            } else {
                printf("Votre point se situe sur la Zone 8\n");
            }
        } else if (x > x2 && x <= width-1) {

            if (y < y1 && y >= 0) {
                printf("Votre point se situe sur la Zone 3\n");
            } else if (y > y1 && y < y2) {
                printf("Votre point se situe sur la Zone 6\n");
            } else {
                printf("Votre point se situe sur la Zone 9\n");
            }
        } else {
            printf("Votre point ne figure sur aucune zones\n");
        }

        if (x == x1 && y == y1) {
            printf("Votre point est sur la frontiere entre les zones 1, 2, 4 et 5\n");
        } else if (x == x2 && y == y2) {
            printf("Votre point est sur la frontiere entre les zones 5, 6, 8 et 9\n");
        } else if (x < x1) {
            if (y == y1)
                printf("Votre point est sur la frontiere entre les zones 1, 4\n");
            if (y == y2)
                printf("Votre point est sur la frontiere entre les zones 4, 7\n");
        } else if (x > x1 && x < x2) {
            if (y == y1)
                printf("Votre point est sur la frontiere entre les zones 2, 5\n");
            if (y == y2)
                printf("Votre point est sur la frontiere entre les zones 5, 8\n");
        }
        else if (x > x2 && x <= width-1) {
            if (y == y1)
                printf("Votre point est sur la frontiere entre les zones 3, 6\n");
            if (y == y2)
                printf("Votre point est sur la frontiere entre les zones 6, 9\n");
        } else {
            printf("Votre point ne figure pas sur une frontiere\n");
        }



        printf("\nVoulez-vous relancer le programme ? Taper 1 si oui 0 sinon : ");
        scanf("%d", &run);

    }
    return 0;

}