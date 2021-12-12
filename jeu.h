#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include "joueur.h"
#include "terrain.h"
#include "bariere.h"

typedef struct list//strucure encre de la liste chainer
{
    t_joueur *j;
}t_list;

typedef struct lastmouve//structure pour l'enregistement du derniere mouvement
{
    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;
    t_bariere bariere[20];
    int actif;
}t_lastmouve;
typedef struct jeu//structure pour le jeu
{
    t_terrain terrain;
    t_joueur j1;
    t_joueur j2;
    t_joueur j3;
    t_joueur j4;
    t_list ordrejeu;
    t_bariere bariere[20];
    int etat;//0 partie pas encore commencere et premiere tours ,1 partie en cours, 2 parti fini
    int nbjoueur;
    t_lastmouve mouve;
}t_jeu;


struct jeu creeJeu(void);//methode de creation de la structure jeu
struct lastmouve creeLastmouve();//methode de creation de la stucture lastmouve
void newGame(struct jeu *jeu);//methode pour cree une nouvelle partie
void oldGame(struct jeu *jeu);//methode pour cree une partie insrive dans un fichier
void startGame(int load);//methode pour le demarage de partie
int round(struct joueur *j,struct jeu *jeu);//methode de fonctionement du round
void deplacement(struct joueur *j, struct jeu *jeu);//methode de deplacement du pion
int deplacementPossible(struct jeu jeu, struct joueur j, int x, int y,char sens);//methode de verification si une bariere ne gene pas
int joueurPresent(struct jeu jeu, struct joueur j, int x, int y);//methode pour verifier que un pion ne gene pas le deplacement
void placerBariere(struct jeu *jeu,struct joueur *j);//methode de placement de bariere
void deplacementBariere(struct jeu *j,int nb,int x,int y,int direction);//methode pour deplacer la bariere
int testFinJeu(struct joueur *j);//methode de verification de fin de jeu
int enregistrement(struct jeu jeu);//methode pour enregister une partie
void affichageJoueur(struct jeu j);//methode d'affichage des joueur
void afficherBariere(struct jeu jeu);//methode d'affichage des bariere
void affichage(struct jeu jeu,struct joueur j);//methode d'affichage du plateau de jeu
int toucheAppuiez();//methode pour recupere les touche appuiez
#endif // JEU_H_INCLUDED
