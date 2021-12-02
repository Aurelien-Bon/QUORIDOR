#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.h"
#include <windows.h>
#include <string.h>

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
    FILE *f=NULL;
    f=fopen("oldGame.txt","r");
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
        return -1;
    }
    else
    {
        int test;
        fscanf(f,"%d",&test);
        jeu->nbjoueur=test;
        //printf("%d\n",test);
        char chaine[70];
        char *d=',';
        if(jeu->nbjoueur==2)
        {
            jeu->ordrejeu.j=&jeu->j1;
            jeu->j1.next=&jeu->j2;
            jeu->j2.next=&jeu->j1;
        }
        else if(jeu->nbjoueur==4)
        {
            jeu->ordrejeu.j=&jeu->j1;
            jeu->j1.next=&jeu->j2;
            jeu->j2.next=&jeu->j3;
            jeu->j1.next=&jeu->j4;
            jeu->j2.next=&jeu->j1;
        }
        struct joueur *nextj=jeu->ordrejeu.j;
        for(int i=0;i<jeu->nbjoueur;i++)
        {
            fscanf(f,"%s",&chaine);
            char *p = strtok(chaine, ",");
            strcpy(nextj->nom,p);
            p=strtok(NULL, ",");
            nextj->score=atoi(p);
            p=strtok(NULL, ",");
            nextj->crosshaire.type=p[0];
            p= strtok(NULL, ",");
            nextj->crosshaire.cor_x=atoi(p);
            p= strtok(NULL, ",");
            nextj->crosshaire.cor_y=atoi(p);
            p= strtok(NULL, ",");
            nextj->nb_bariere=atoi(p);
            p= strtok(NULL, ",");
            nextj->startside=atoi(p);
            nextj=nextj->next;
        }
        printf("etd");
        for(int i=0;i<20;i++)
        {
            fscanf(f,"%s",&chaine);
            char *p=strtok(chaine, ",");
            jeu->bariere[i].id=atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_x1=atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_y1=atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_x2 = atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_y2 = atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].sens=p[0];
            p=strtok(NULL, ",");
            jeu->bariere[i].active=atoi(p);
        }
        fscanf(f,"%d",&jeu->etat);
    }
    fclose(f);
}
void startGame(int load)
{
    t_jeu jeu=creeJeu();
    if(load==0)
        newGame(&jeu);
    else
        oldGame(&jeu);
    printf("jeu etat: %d, ",jeu.etat);
    //printf("next joueur: %s\n", jeu.ordrejeu.j->nom);
    t_joueur *nextj=jeu.ordrejeu.j;
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
            finJeu=1;
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
            enregistrement(*jeu);
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
        affichage(*jeu,*j);
        char c;
        fflush(stdin);
        c = toucheAppuiez();
        int possible=0;
        switch(c)
        {
            case 'z':
                if(newX-1>=0&&newX-1<9)
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
                if(newX+1>=0&&newX+1<9)
                    possible=deplacementchoisi(j,0,1,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 'q':
                if(newY-1>=0&&newY-1<9)
                    possible=deplacementchoisi(j,-1,0,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 'd':
                if(newY+1>=0&&newY+1<9)
                    possible=deplacementchoisi(j,1,0,jeu,&newX,&newY);
                else
                {
                    newX=x;
                    newY=y;
                }
                break;
            case 'v':
                quitter=1;
                break;
            case ' ':
                newX=x;
                newY=y;
                break;
        }
        if(possible==1)
        {
            j->crosshaire.cor_x=newX;
            j->crosshaire.cor_y=newY;
        }
        printf("%d,%d\n",newX,newY);

    }while(quitter==0);
}
int deplacementchoisi(struct joueur *j,int x,int y,struct jeu *jeu,int *newX,int *newY)
{
    *newX=x+j->crosshaire.cor_x;
    *newY=y+j->crosshaire.cor_y;
    struct joueur *nextj=jeu->ordrejeu.j;
    for(int i=0;i<jeu->nbjoueur;i++)
    {
        if(j->crosshaire.cor_x==nextj->crosshaire.cor_x&&j->crosshaire.cor_y==nextj->crosshaire.cor_y&&j->nom!=nextj->nom)
        {
            return 0;
        }
    }
    return 1;
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
    jeu->bariere[nb].cord_x1=0;
    jeu->bariere[nb].cord_y1=0;
    jeu->bariere[nb].cord_x2 = 0;
    jeu->bariere[nb].cord_y2 = 0;
    jeu->bariere[nb].sens='h';
    do
    {
        //afficherBariere(jeu->bariere[nb]);
        char c;
        c=getc(stdin);
        switch (c)
        {
            case 'z': //monter
                if(jeu->bariere[nb].cord_x1-1<7&&jeu->bariere[nb].cord_x1-1>=0)
                    deplacementBariere(&jeu->bariere[nb],-1,0,0);
                break;
            case 's'://decendre
                if(jeu->bariere[nb].cord_x1+1<7&&jeu->bariere[nb].cord_x1+1>=0)
                    deplacementBariere(&jeu->bariere[nb],1,0,0);
                break;
            case 'q'://gauche
                if(jeu->bariere[nb].cord_y1-1<7&&jeu->bariere[nb].cord_y1-1>=0)
                    deplacementBariere(&jeu->bariere[nb],0,-1,0);
                break;
            case 'd'://droite
                if(jeu->bariere[nb].cord_y1+1<7&&jeu->bariere[nb].cord_y1+1>=0)
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
                if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1) {
                    if (jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {

                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'h') {
                    if (jeu->bariere[i].cord_x1 - 1 == jeu->bariere[nb].cord_x1 - 1 &&
                        jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens){
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'd') {
                    if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1 &&
                        jeu->bariere[i].cord_y1 + 1 == jeu->bariere[nb].cord_y1 + 1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'b') {
                    if (jeu->bariere[i].cord_x1 + 1 == jeu->bariere[nb].cord_x1 + 1 &&
                        jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1 &&
                        jeu->bariere[i].sens == jeu->bariere[nb].sens) {
                        printf("Un barriere est deja placer la! \n");
                        jeu->bariere[nb].active = 2;
                    }
                }
                if (jeu->bariere[i].sens == 'g') {
                    if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1 &&
                        jeu->bariere[i].cord_y1 - 1 == jeu->bariere[nb].cord_y1 - 1 &&
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
    b->cord_x1+=x;
    b->cord_y1+=y;
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
int enregistrement(struct jeu jeu)
{
    FILE *f=NULL;
    f=fopen("oldGame.txt","w");
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
        return -1;
    }
    else
    {
        fprintf(f,"%d\n",jeu.nbjoueur);
        struct joueur *nextj=jeu.ordrejeu.j;
        for(int i=0;i<jeu.nbjoueur;i++)
        {
            fprintf(f,"%s,%d,%c,%d,%d,%d,%c\n",nextj->nom,nextj->score,nextj->crosshaire.type,nextj->crosshaire.cor_x,nextj->crosshaire.cor_y,nextj->nb_bariere,nextj->startside);
            nextj=nextj->next;
        }
        for(int i=0;i<20;i++)
        {
            fprintf(f,"%d,%d,%d,%d,%d,%c,%d\n",jeu.bariere[i].id,jeu.bariere[i].cord_x1,jeu.bariere[i].cord_y1,jeu.bariere->cord_x2,jeu.bariere->cord_y2,jeu.bariere[i].sens,jeu.bariere[i].active);
        }
        fprintf(f,"%d",jeu.etat);
    }
    fclose(f);

}
void affichageJoueur(struct jeu jeu)
{
    struct joueur *nextj=jeu.ordrejeu.j;
    for(int i=0;i<jeu.nbjoueur;i++)
    {
        //printf("%d %d ",nextj->crosshaire.cor_x,nextj->crosshaire.cor_y);
        //printf("%d %d",nextj->crosshaire.cor_y*4+6,nextj->crosshaire.cor_x*2+2);
        if(nextj->crosshaire.cor_y!=-1)
        {
            gotoligcol(nextj->crosshaire.cor_y*2+2,nextj->crosshaire.cor_x*4+6);
            printf("%c",nextj->crosshaire.type);
        }
        nextj=nextj->next;
        gotoligcol(20,0);
    }

}
void afficherBariere(struct jeu jeu)
{
    int x;
    int y;
    for(int i=0;i<20;i++)
    {
        if(jeu.bariere[i].active==1)
        {
            if(jeu.bariere[i].sens=='h')
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+1,jeu.bariere[i].cord_x1*4+6);
                printf("%c%c%c",0xcd,0xcd,0xec);

            }
            if(jeu.bariere[i].sens=='b')
            {

            }
            if(jeu.bariere[i].sens=='d')
            {

            }
            if(jeu.bariere[i].sens=='g')
            {

            }
        }
    }
}
void affichage(struct jeu jeu,struct joueur j)
{
    system("cls");
    affichageTerrain(jeu.terrain);
    afficherBariere(jeu);
    affichageJoueur(jeu);
}

int toucheAppuiez()
{
    int cara;
    while(1)
    {
        if(GetAsyncKeyState(VK_UP)&0x27)
        {
            cara='z';
            break;
        }
        if(GetAsyncKeyState(VK_LEFT)&0x25)
        {
            cara='q';
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT)&0x27)
        {
            cara='d';
            break;
        }
        if(GetAsyncKeyState(VK_DOWN)&0x25)
        {
            cara='s';
            break;
        }
        if(GetAsyncKeyState(VK_SPACE)&0x21)
        {
            cara=' ';
            break;
        }
        if(GetAsyncKeyState(VK_RETURN)&0x0D)
        {
            cara='r';
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE)&0x1B)
        {
            cara='v';
            break;
        }
    }
    return cara;
}
