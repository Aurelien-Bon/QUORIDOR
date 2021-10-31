#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
struct joueur creeJoueur(void)
{
	t_joueur j = {0};
    j.nb_bariere=0;
    printf("Entrez votre pseudo(50 caractere max):");
    scanf("%s",j.nom);
    j.score=0;
    j.crosshaire=creeCrossaire();
    return j;
}
void affichierJoueur(struct joueur j)
{
    printf("Pseudo: %s, ",j.nom);
    printf("Score: %d, ",j.score);
    printf("bariere restantante: %d, ",j.nb_bariere);
    printf("crossaire: %c.\n",j.crosshaire);
}