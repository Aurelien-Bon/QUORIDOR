#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("QUORIDOR le projet trop eclate!\n");
    t_jeu jeu=creeJeu();
    startGame(&jeu);
    affichierJoueur(jeu.j1);
    affichierJoueur(jeu.j2);
    affichierJoueur(jeu.j3);
    affichierJoueur(jeu.j4);
    affichage(jeu.terrain);
    printf("jeu etat: %d\n",jeu.etat);
    return 0;
}