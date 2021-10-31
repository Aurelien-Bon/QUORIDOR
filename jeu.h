#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "joueur.h"
#include "terrain.h"
#include "bariere.h"
typedef struct jeu
{
    t_terrain terrain;
    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;
    t_bariere bariere[20];
    int etat;//0 partie pas encore commencer, 1 premiere tours ,2 partie en cours, 3 parti fini
    int nbjoueur;
}t_jeu;
struct jeu creeJeu(void);

void startGame(struct jeu *jeu);
#endif // JEU_H_INCLUDED
