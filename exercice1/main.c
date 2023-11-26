/*
 * Objectif : Dessin d'un losange vide (exercice 1)
 * Date     : 08/11/2023
 * Auteur   : Bousbia Ayoub
 */

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_ORANGE  "\x1b[38;5;208m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_INDIGO  "\x1b[38;5;69m"
#define ANSI_COLOR_VIOLET  "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char **argv) {

    char symb;
    int choice;
    int color = 0;
    int isLineSet = 0;
    int isCharacterSet = 0;

    int n = 0;
    int run = 1;

    while (run) {

        do {

            printf("\nMenu:\n");
            printf("1. Entrer un caractere\n");
            printf("2. Entrer un nombre de ligne\n");
            printf("3. Ajouter l'option arc-en-ciel\n");
            printf("4. Lancer le programme\n");
            printf("5. Exit\n");

            printf("Entrer votre choix (1-5) : ");
            scanf("%d", &choice);
            fflush(stdin);

            switch (choice) {
                case 1:

                    do {
                        printf("\nEntrer un caractere : ");
                        scanf(" %c", &symb);
                        fflush(stdin);
                    } while (symb == '\n');
                    isCharacterSet = 1;
                    break;

                case 2:

                    do {
                        printf("\nEntrer un nombre de ligne (impair): ");
                        scanf("%d", &n);
                        fflush(stdin);
                        if (n % 2 == 0 || n <= 0)
                            printf("Le nombre de ligne n'est pas impair\n");
                    } while (n % 2 == 0 || n <= 0);
                    isLineSet = 1;
                    break;

                case 3:
                    do {
                        printf("\nSouhaitez vous ajouter l'option arc-en-ciel ? Taper 1 si oui, 0 non sinon : ");
                        scanf("%d", &color);
                        fflush(stdin);
                    } while (color != 1 && color != 0);
                    break;


                case 4:

                    if (!isLineSet) {
                        printf("\nNombre de lignes non saisie. Lancement impossible\n");
                        break;
                    } else if (!isCharacterSet) {
                        printf("\nCaractere non saisie. Lancement impossible\n");
                        break;
                    }


                    if (color) {
                        int k = 0;
                        for (int i = 1; i <= n; i++) {
                            i <= n / 2 + 1 ? k++ : k--;

                            for (int j = 1; j <= n; j++) {
                                if (j <= n / 2 + 2 - k || j >= n / 2 + k) {
                                    switch (i % 7) {
                                        case 0:
                                            printf(ANSI_COLOR_RED " %c", symb);
                                            break;
                                        case 1:
                                            printf(ANSI_COLOR_ORANGE " %c", symb);
                                            break;
                                        case 2:
                                            printf(ANSI_COLOR_YELLOW " %c", symb);
                                            break;
                                        case 3:
                                            printf(ANSI_COLOR_GREEN " %c", symb);
                                            break;
                                        case 4:
                                            printf(ANSI_COLOR_BLUE " %c", symb);
                                            break;
                                        case 5:
                                            printf(ANSI_COLOR_INDIGO " %c", symb);
                                            break;
                                        case 6:
                                            printf(ANSI_COLOR_VIOLET " %c", symb);
                                            break;
                                    }
                                } else {
                                    printf("  ");
                                }
                            }
                            printf(ANSI_COLOR_RESET "\n");
                        }
                    } else {
                        int k = 0;
                        for (int i = 1; i <= n; i++) {
                            i <= n / 2 + 1 ? k++ : k--;

                            for (int j = 1; j <= n; j++) {
                                if (j <= n / 2 + 2 - k || j >= n / 2 + k) {
                                    printf(" %c", symb);
                                } else {
                                    printf("  ");
                                }
                            }

                            printf("\n");
                        }
                    }
                    break;

                case 5:
                    printf("\nFin du programme");
                    run = 0;
                    break;

                default:
                    printf("\nChoix invalide. Entrer une nouvelle option\n");
                    break;

            }

        } while (choice != 5);

    }
    return 0;
}
