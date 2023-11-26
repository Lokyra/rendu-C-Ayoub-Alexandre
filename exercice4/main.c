/*
 * Objectif : salaire (exercice 4)
 * Date     : 23/11/2023
 * Auteur   : Fouillit Alexandre
 */

#include <stdio.h>

int main(int argc, char **argv) {

    double salary;
    double sales;
    double kilometers = 0.0;
    char exitCountry;
    int days;

    int run = 1;
    int choice;
    int isSalarySet = 0 ;
    int isSalesSet = 0 ;

    while (run) {

        do {

            printf("\nMenu:\n");
            printf("1. Entrer votre salaire de base \n");
            printf("2. Entrer le chiffre d'affaire  \n");
            printf("3. si il y a eu un deplacement professionnel \n");
            printf("4. Lancer le programme\n");
            printf("5. Exit\n");

            printf("Entrer votre choix (1-5) : ");
            scanf("%d", &choice);
            fflush(stdin);

            switch (choice) {
                case 1:
                    do {
                        printf("\nVotre salaire de base  : ");
                        scanf("%lf",&salary);
                        fflush(stdin);
                    } while (salary < 0);
                    isSalarySet = 1;
                    break;

                case 2:
                    do {
                        printf("\nEntrer le chiffre d'affaire : ");
                        scanf("%lf", &sales);
                        fflush(stdin);
                    } while (sales < 0);
                    isSalesSet = 1;
                    break;

                case 3:
                    do {
                        printf("\nEntrer le nombre de kilometre parcouru : ");
                        scanf("%lf", &kilometers);
                        fflush(stdin);
                    } while (kilometers < 0);
                    do {
                        printf("\ny a-t-il un deplacement a l'etranger (o ou n): ");
                        scanf("%c", &exitCountry);
                        fflush(stdin);
                    } while (exitCountry != 'n' && exitCountry != 'o');
                    if (exitCountry == 'o') {
                        do {
                            printf("\ncombien de jour ? : ");
                            scanf("%d", &days);
                            fflush(stdin);
                        } while (days < 0 );
                    }
                    break;



                case 4:

                    if (!isSalarySet) {
                        printf("\nPas de salaire saisie. Lancement impossible\n");
                        break;
                    }
                    if (!isSalesSet) {
                        printf("\nPas de chiffre d'affaire saisie. Lancement impossible\n");
                        break;
                    }

                    if (sales >= 22000) {
                        sales = sales - 22000.0;
                        salary = salary + 13000.0*0.0160 + 9000.0*0.0220 + sales*0.03;

                    } else if (sales >=13000.0) {
                        sales = sales - 13000.0;
                        salary = salary + 13000.0*0.0160 + sales*0.0220 ;
                    } else {
                        salary = salary + sales*0.0160;
                    }

                    if (kilometers < 0.0 ){
                        if (kilometers*0.50 <= 50.00){
                            salary = salary + 50.00;
                        } else if (kilometers*0.50 >= 150.00) {
                            salary = salary + 150.00;
                        } else {
                            salary = salary + kilometers*0.50;
                        }
                    }

                    if (exitCountry == 'o') {
                        salary = salary + days*100.00;
                    }

                    printf("\nsalaire brut mensuel : %.2lf euros", salary);
                    break;

                case 5:
                    printf("\nFin du programme");
                    run = 0;
                    break;


                default:
                    printf("\nChoix invalide. Entrer une nouvelle option\n");
                    break;

            }

        } while(choice != 5);

    }
    return 0;
}