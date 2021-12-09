#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include "joueur.h"
#include "terrain.h"
#include "bariere.h"

typedef struct list
{
    t_joueur *j;
}t_list;

typedef struct lastmouve
{
    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;
    t_bariere bariere[20];
    int actif;
}t_lastmouve;
typedef struct jeu
{
    t_terrain terrain;
    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;
    t_list ordrejeu;
    t_bariere bariere[20];
    int etat;//0 partie pas encore commencer, 1 premiere tours ,2 partie en cours, 3 parti fini
    int nbjoueur;
    t_lastmouve mouve;
}t_jeu;


struct jeu creeJeu(void);
struct lastmouve creeLastmouve();
void newGame(struct jeu *jeu);//nouvelle parti
void oldGame(struct jeu *jeu);//chargement d'une ancienne partie
void startGame(int load);
int round(struct joueur *j,struct jeu *jeu);
void deplacement(struct joueur *j, struct jeu *jeu);
int deplacementPossible(struct jeu jeu, struct joueur j, int x, int y,char sens);
void placerBariere(struct jeu *jeu,struct joueur *j);
void deplacementBariere(struct jeu *j,int nb,int x,int y,int direction);
int testFinJeu(struct joueur *j);
void affichageJoueur(struct jeu j);
void afficherBariere(struct jeu jeu);
void affichage(struct jeu jeu,struct joueur j);
int toucheAppuiez();
#endif // JEU_H_INCLUDED
