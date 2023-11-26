/*
 * Objectif : casino (exercice 5)
 * Date     : 08/11/2023
 * Auteur   : Fouillit Alexandre
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv) {
    int money;
    int isMoneySet = 0;
    int seuil;
    int isSeuilSet = 0;
    int moneyTarget;
    int isMoneyTargetSet = 0;
    int try ;
    int isTrySet = 0 ;
    int bet ;
    int isBetSet = 0 ;

    int run = 1;
    int choice;
    double simulationWin = 0 ;
    double simulationLose = 0 ;
    double simulation ;


    srand(time(NULL));

    while (run) {

        do {

            printf("\nMenu:\n");
            printf("1. Entrer la somme de depart\n");
            printf("2. Entrer le seuil\n");
            printf("3. Entrer la somme visee\n");
            printf("4. Entrer le nombre d'essai\n");
            printf("5. Entrer la mise a chaque essai\n");
            printf("6. Lancer le programme\n");
            printf("7. Exit\n");

            printf("Entrer votre choix (1-7) : ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    do {
                        printf("\nEntrer une somme : ");
                        scanf("%d",&money);
                    } while (money < 0);
                    isMoneySet = 1;
                    break;

                case 2:
                    do {
                        printf("\nEntrer un seuil (entre 0 et 100) : ");
                        scanf("%d", &seuil);
                    } while (seuil <=0 ||seuil >= 100);
                    isSeuilSet = 1;
                    break;

                case 3:
                    do {
                        printf("\nEntrer la somme visee : ");
                        scanf("%d", &moneyTarget);
                    } while (moneyTarget < 0);
                    isMoneyTargetSet = 1;
                    break;

                case 4:
                    do {
                        printf("\ncombien d'essai ? (1 minimum ) : ");
                        scanf("%d", &try);
                    } while (try < 1);
                    isTrySet = 1;
                    break;

                case 5:
                    do {
                        printf("\ncombien de mise par essai ? (1 minimum ) : ");
                        scanf("%d", &bet);
                    } while (bet < 1);
                    isBetSet = 1;
                    break;


                case 6:

                    if (!isMoneySet) {
                        printf("\nPas de somme de depart saisie. Lancement impossible\n");
                        break;
                    }
                    if (!isSeuilSet) {
                        printf("\nseuil non saisie. Lancement impossible\n");
                        break;
                    }
                    if (!isMoneyTargetSet) {
                        printf("\nsomme visee non saisie. Lancement impossible\n");
                        break;
                    }
                    if (! isTrySet) {
                        printf("\nsomme d'essai non saisie. Lancement impossible\n");
                        break;
                    }
                    if (! isBetSet) {
                        printf("\nmise par essai non saisie. Lancement impossible\n");
                        break;
                    }

                    while (try != 0)  {
                        if (money < bet || money >= moneyTarget){
                            break;
                        }
                        if (rand()%100 <= seuil) {
                            money = money + bet;
                            simulationWin++;
                            simulation++;
                        } else {
                            money = money - bet;
                            simulationLose++ ;
                            simulation++;
                        }
                        printf("Montant restant : %d\n", money);
                        try--;
                    }

                    printf("\nnombre de simulation ; %2.lf", simulation );
                    printf("\npourcentage de simulation reussite : %2.lf %% ",simulationWin/simulation*100);
                    printf("\npourcentage de de simulation ratee : %2.lf %% ",simulationLose/simulation*100);

                    break;

                case 7:
                    printf("\nFin du programme");
                    run = 0;
                    break;


                default:
                    printf("\nChoix invalide. Entrer une nouvelle option\n");
                    break;

            }

        } while(choice != 7);

    }
    return 0;
}