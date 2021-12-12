#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "crosshaire.h"
typedef struct joueur//structure joueur
{
    char nom[50];
    int score;
    t_crosshaire crosshaire;
    int nb_bariere;
    char startside;
    struct joueur *next;
    int chrono;
}t_joueur;
struct joueur creeJoueur(void);//methode de creation de joueur
int getScore(char *pseudo);//methode pour recuper le score d'un joueur dans un fichier
void setScore(char *pseudo,int score);//methode pour ajouter le score d'un joueur dans un fichier
#endif // JOUEUR_H_INCLUDED
