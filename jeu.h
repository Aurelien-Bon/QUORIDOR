#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "joueur.h"
#include "terrain.h"
#include "bariere.h"
typedef struct jjeu
{
    char nom[50];
    int score;
    t_crosshaire crosshaire;
    int nb_bariere;
}t_jeu;
#endif // JEU_H_INCLUDED