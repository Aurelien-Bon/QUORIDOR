#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

struct jeu creeJeu(void)
{
    t_jeu jeu={0};
    return jeu;
}
void newGame(struct jeu *jeu)
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
        jeu->j1.nb_bariere=10;
        jeu->j2.nb_bariere=10;
        jeu->j1.next=&jeu->j2;
        jeu->j2.next=&jeu->j1;
        int nb=rand()%2;
        if(nb==0)
        {
            jeu->ordrejeu.j=&(jeu->j1);
            jeu->j1.startside='B';
            jeu->j2.startside='H';
        }
        if(nb==1)
        {
            jeu->ordrejeu.j=&(jeu->j2);
            jeu->j1.startside='H';
            jeu->j2.startside='B';
        }
    }
    else
    {
        jeu->j1=creeJoueur();
        jeu->j2=creeJoueur();
        jeu->j3=creeJoueur();
        jeu->j4=creeJoueur();
        jeu->nbjoueur=4;
        jeu->j1.nb_bariere=5;
        jeu->j2.nb_bariere=5;
        jeu->j3.nb_bariere=5;
        jeu->j4.nb_bariere=5;
        jeu->j1.next=&jeu->j2;
        jeu->j2.next=&jeu->j3;
        jeu->j3.next=&jeu->j4;
        jeu->j4.next=&jeu->j1;
        int nb=rand()%4;
        if(nb==0)
        {
            jeu->ordrejeu.j=&(jeu->j1);
            jeu->j1.startside='B';
            jeu->j2.startside='G';
            jeu->j3.startside='H';
            jeu->j4.startside='D';
        }
        if(nb==1)
        {
            jeu->ordrejeu.j=&(jeu->j2);
            jeu->j1.startside='D';
            jeu->j2.startside='B';
            jeu->j3.startside='G';
            jeu->j4.startside='H';
        }
        if(nb==2)
        {
            jeu->ordrejeu.j=&(jeu->j3);
            jeu->j1.startside='H';
            jeu->j2.startside='D';
            jeu->j3.startside='B';
            jeu->j4.startside='G';
        }
        if(nb==3)
        {
            jeu->ordrejeu.j=&(jeu->j4);
            jeu->j1.startside='G';
            jeu->j2.startside='H';
            jeu->j3.startside='D';
            jeu->j4.startside='B';
        }
    }
    jeu->terrain=creeTerrain();
    for(int i=0;i<20;i++)
    {
        jeu->bariere[i]=creeBariere();
        jeu->bariere[i].id=i+1;
    }
}
void oldGame(struct jeu *jeu)
{

    ///RECUPERATION DU JEU PAR LECTURE DE FICHIER
}
void startGame(int load)
{
    t_jeu jeu=creeJeu();
    if(load==0)
        newGame(&jeu);
    else
        oldGame(&jeu);
    affichierJoueur(jeu.j1);
    affichierJoueur(jeu.j2);
    affichierJoueur(jeu.j3);
    affichierJoueur(jeu.j4);
    /*affichage(jeu.terrain);
    for(int i=0;i<20;i++)
    {
        afficherBariere(jeu.bariere[i]);
    }
    printf("jeu etat: %d, ",jeu.etat);
    printf("next joueur: %s\n", jeu.ordrejeu.j->nom);*/
    struct joueur *nextj=jeu.ordrejeu.j;
    int finJeu=0;

    while(finJeu==0)
    {
        if(nextj->crosshaire.cor_x==-1)
        {
            deplacement(nextj,&jeu);
        }
        finJeu=round(nextj,&jeu);
        if(testFinJeu(nextj)==1)
        {
            printf("Victoire de %s il remporte 5 point",nextj->nom);
            nextj->score+=5;
        }
        nextj=nextj->next;
        //affichage(jeu.terrain);
    }
}
int round(struct joueur *j, struct jeu *jeu)
{
    printf("C'est au tour de %s.\n",j->nom);
    affichierJoueur(*j);
    int choix;
    do
    {
        printf("1-Deplacer mon pions \n");
        printf("2-Posser une bariere\n");
        printf("3-Ne rien faire\n");
        printf("4-Annuler le derniere mouvement\n");
        printf("5-Quitter\n");
        printf("Quelle est votre choix: ");
        scanf("%d",&choix);
    }while(choix<1||choix>5);
    switch (choix)
    {
        case 1:
            deplacement(j,jeu);
            break;
        case 2:
            if(j->nb_bariere>0)
            {
                placerBariere(jeu,j);
            }
            else
            {
                printf("ERREUR: vous n'avez plus de bariere a placer");
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            return 1;
            break;
    }
    return 0;
}
void deplacement(struct joueur *j,struct jeu *jeu)
{
    int x=j->crosshaire.cor_x;
    int y=j->crosshaire.cor_y;
    if(x==-1&&y==-1)
    {
        if(j->startside=='B')
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=8;
        }
        if(j->startside=='H')
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=0;
        }
        if(j->startside=='G')
        {
            j->crosshaire.cor_x=0;
            j->crosshaire.cor_y=5;
        }
        if(j->startside=='D')
        {
            j->crosshaire.cor_x=8;
            j->crosshaire.cor_y=5;
        }
    }
    else
    {
        deplacementCrossair(j,jeu);
    }
}
void deplacementCrossair(struct joueur *j,struct jeu *jeu)
{
    int x=j->crosshaire.cor_x;
    int y=j->crosshaire.cor_y;
    printf("%d,%d\n",x,y);
    int newX=x;
    int newY=y;
    int quitter=0;
    do
    {
        char c=' ';
        fflush(stdin);
        c = getchar();
        int possible=0;
        switch(c)
        {
            case 'z':
                if(y-1>=0&&y-1<9)
                {
                    possible=deplacementchoisi(j,0,-1,jeu,&newX,&newY);
                }
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 's':
                if(y+1>=0&&y+1<9)
                    possible=deplacementchoisi(j,0,1,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 'q':
                if(x-1>=0&&x-1<9)
                    possible=deplacementchoisi(j,-1,0,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 'd':
                if(x+1>=0&&x+1<9)
                    possible=deplacementchoisi(j,1,0,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case ' ':
                quitter=1;
                break;
            case 'e':
                newX=x;
                newY=y;
                break;
        }
        if(possible==1)
        {
            changecarac(jeu->terrain.grille,j->crosshaire.type,newX,newY);
        }
        printf("%d,%d\n",newX,newY);
        affichage(jeu->terrain);
    }while(quitter==0);
    j->crosshaire.cor_x=newX;
    j->crosshaire.cor_y=newY;
}
int deplacementchoisi(struct joueur *j,int x,int y,struct jeu *jeu,int *newX,int *newY)
{
    *newX=x+j->crosshaire.cor_x;
    *newY=y+j->crosshaire.cor_y;
    return checkMouve(jeu->terrain,*newX,*newY);
}
void placerBariere(struct jeu *jeu,struct joueur *j)
{
    int placer=0;
    int nb=-1;
    int i=0;
    while(nb==-1)
    {
        if(jeu->bariere[i].active==0)
        {
            nb=i;
        }
        i++;
    }
    jeu->bariere[nb].cord_x=0;
    jeu->bariere[nb].cord_y=0;
    jeu->bariere[nb].sens='h';
    do
    {
        afficherBariere(jeu->bariere[nb]);
        char c;
        c=getc(stdin);
        switch (c)
        {
            case 'z': //monter
                if(jeu->bariere[nb].cord_x-1<7&&jeu->bariere[nb].cord_x-1>=0)
                    deplacementBariere(&jeu->bariere[nb],-1,0,0);
                break;
            case 's'://decendre
                if(jeu->bariere[nb].cord_x+1<7&&jeu->bariere[nb].cord_x+1>=0)
                    deplacementBariere(&jeu->bariere[nb],1,0,0);
                break;
            case 'q'://gauche
                if(jeu->bariere[nb].cord_y-1<7&&jeu->bariere[nb].cord_y-1>=0)
                    deplacementBariere(&jeu->bariere[nb],0,-1,0);
                break;
            case 'd'://droite
                if(jeu->bariere[nb].cord_y+1<7&&jeu->bariere[nb].cord_y+1>=0)
                    deplacementBariere(&jeu->bariere[nb],0,1,0);
                break;
            case 'e'://rotation droit
                deplacementBariere(&jeu->bariere[nb],0,0,1);
                break;//rotation gauche
            case 'a'://rotation droite
                deplacementBariere(&jeu->bariere[nb],0,0,-1);
                break;
            case ' '://valider
                placer=1;
                jeu->bariere[nb].active=1;
                j->nb_bariere--;
                break;
            case 'r'://annuler
                placer=1;
                jeu->bariere[nb].active=2;
                break;
        }
        for(int i=0;i<20;i++)
        {
            if(jeu->bariere[i].id!=jeu->bariere[nb].id)
            {
                if (jeu->bariere[i].cord_x == jeu->bariere[nb].cord_x) {
                    if (jeu->bariere[i].cord_y == jeu->bariere[nb].cord_y &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {

                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'h') {
                    if (jeu->bariere[i].cord_x - 1 == jeu->bariere[nb].cord_x - 1 &&
                        jeu->bariere[i].cord_y == jeu->bariere[nb].cord_y &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens){
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'd') {
                    if (jeu->bariere[i].cord_x == jeu->bariere[nb].cord_x &&
                        jeu->bariere[i].cord_y + 1 == jeu->bariere[nb].cord_y + 1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'b') {
                    if (jeu->bariere[i].cord_x + 1 == jeu->bariere[nb].cord_x + 1 &&
                        jeu->bariere[i].cord_y == jeu->bariere[nb].cord_y &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'g') {
                    if (jeu->bariere[i].cord_x == jeu->bariere[nb].cord_x &&
                        jeu->bariere[i].cord_y - 1 == jeu->bariere[nb].cord_y - 1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
            }
        }
    }while(placer==0);
}
void deplacementBariere(struct bariere *b,int x,int y,int direction)
{
    b->cord_x+=x;
    b->cord_y+=y;
    if(direction==1)
    {
        if(b->sens=='h')
        {
            b->sens='d';
        }
        else if(b->sens=='b')
        {
            b->sens='g';
        }
        else if(b->sens=='g')
        {
            b->sens='h';
        }
        else if(b->sens=='d')
        {
            b->sens='b';
        }
    }
    if(direction==-1)
    {
        if(b->sens=='h')
        {
            b->sens='g';
        }
        else if(b->sens=='b')
        {
            b->sens='d';
        }
        else if(b->sens=='g')
        {
            b->sens='b';
        }
        else if(b->sens=='d')
        {
            b->sens='h';
        }
    }
}
int testFinJeu(struct joueur *j)
{
    if(j->startside=='b')
        if(j->crosshaire.cor_x==0)
            return 1;
    else if(j->startside=='d')
        if(j->crosshaire.cor_y==0)
            return 1;
    else if(j->startside=='g')
        if(j->crosshaire.cor_y==8)
            return 1;
    else if(j->startside=='h')
        if(j->crosshaire.cor_x==8)
            return 1;
    return 0;

}
void enregistrement(struct jeu j)
{

}