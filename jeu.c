#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
struct jeu creeJeu(void)
{
    t_jeu jeu={0};
    return jeu;
}
 void startGame(struct jeu *jeu)
{
    jeu->etat=0;
    int nb;
    do
    {
        printf("A combien de joueur voulez vous jouer? \n");
        printf("1- 2 joueurs\n");
        printf("2- 4 joueurs\n");
        fflush(stdin);
        scanf("%d",&nb);
    }while(nb<1 || nb>2);
    if(nb==1)
    {
        jeu->j1=creeJoueur();
        jeu->j2=creeJoueur();
        jeu->nbjoueur=2;
    }
    else
    {
        jeu->j1=creeJoueur();
        jeu->j2=creeJoueur();
        jeu->j3=creeJoueur();
        jeu->j4=creeJoueur();
        jeu->nbjoueur=4;
    }
    jeu->terrain=creeTerrain();
}