/*
 * Objectif : Calcul graphique d'une trajectoire avec CSFML (exercice 6)
 * Date     : 20/11/2023
 * Auteur   : Bousbia Ayoub
 * Ressource : https://26.customprotocol.com/csfml/index.htm
 * Compilation : via Makefile
 */


#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Window.h>
#include <stdio.h>
#include <math.h>


#define WIDTH   1000
#define HEIGHT  800

sfRenderWindow* create_window() {

    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "Let's have fun with C code !", sfDefaultStyle, NULL);

    return window;
}

sfVertexArray* set_x_axis() {

    sfVertexArray* line = sfVertexArray_create();

    sfVertex vertex1 = {.position = {0, HEIGHT / 2.0}, .color = sfBlack};
    sfVertex vertex2 = {.position = {WIDTH, HEIGHT / 2.0}, .color = sfBlack};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);

    return line;
}

sfVertexArray* set_y_axis() {

    sfVertexArray* line = sfVertexArray_create();

    sfVertex vertex1 = {.position = {WIDTH / 2.0, 0}, .color = sfBlack};
    sfVertex vertex2 = {.position = {WIDTH / 2.0, HEIGHT}, .color = sfBlack};

    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);

    return line;
}

int main(int argc, char **argv) {

    int run = 1;

    sfEvent event;
    sfRenderWindow* window = create_window();

    sfVertexArray* line_x = set_x_axis();
    sfVertexArray* line_y = set_y_axis();

    sfVertexArray_setPrimitiveType(line_x, sfLines);
    sfVertexArray_setPrimitiveType(line_y, sfLines);

    sfVertexArray* trajectory = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(trajectory, sfLinesStrip);


    double v;
    double alpha;
    double y0;
    double t = 0.0;
    double g = 9.81;

    while (run) {
        do {

            do {
                printf("\nEntrer la vitesse de sortie de la balle du canon de l'arme : ");
                scanf("%lf", &v);
                if (v < 0)
                    printf("La vitesse ne peut pas etre inferieure a 0\n");

            } while(v < 0);

            do {
                printf("\nEntrer l'angle de tir : ");
                scanf("%lf", &alpha);
                if (alpha < 0 || alpha > 360)
                    printf("Votre angle doit etre superieur a 0 et inferieur ou egale a 360\n");
            } while (alpha < 0 || alpha > 360);

            do {
                printf("\nEntrer la hauteur initiale par rapport au sol: ");
                scanf("%lf", &y0);
                if (y0 < 0 || y0 > HEIGHT)
                    printf("Votre hauteur doit etre superieur a 0 et inferieur ou egale a 800 \n");

            } while (y0 < 0 || y0 > HEIGHT);

        } while (!v && !alpha && !g && !y0);


        double alpha_rad = alpha * M_PI / 180.0;
        y0 = HEIGHT - y0;

        while (sfRenderWindow_isOpen(window)) {

            while (sfRenderWindow_pollEvent(window, &event))
            {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
            }
            double x = v * cos(alpha_rad) * t;
            double y = -0.5 * g * t * t + v * sin(alpha_rad) * t + y0;


            sfVertex vertex1 = {.position = {x, HEIGHT - y}, .color = sfRed};
            sfVertexArray_append(trajectory, vertex1);

            t += 0.1;

            x = v * cos(alpha_rad) * t;
            y = -0.5 * g * t * t + v * sin(alpha_rad) * t + y0;

            sfVertex vertex2 = {.position = {x, HEIGHT - y}, .color = sfRed};
            sfVertexArray_append(trajectory, vertex2);

            t += 0.1;

            sfRenderWindow_clear(window, sfWhite);
            sfRenderWindow_drawVertexArray(window, trajectory, NULL);
            sfRenderWindow_drawVertexArray(window, line_x, NULL);
            sfRenderWindow_drawVertexArray(window, line_y, NULL);
            sfRenderWindow_display(window);
        }

        printf("\nVoulez-vous relancer le programme ? Taper 1 si oui, 0 sinon : ");
        scanf("%d", &run);
        window = create_window();
    }

    sfVertexArray_destroy(line_x);
    sfVertexArray_destroy(line_y);
    sfVertexArray_destroy(trajectory);
    sfRenderWindow_destroy(window);

    return 0;
}

