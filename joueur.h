#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "crosshaire.h"
typedef struct joueur
{
    char nom[50];
    int score;
    t_crosshaire crosshaire;
    int nb_bariere;
}t_joueur;
#endif // JOUEUR_H_INCLUDED