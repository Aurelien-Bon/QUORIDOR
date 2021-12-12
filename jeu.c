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
struct lastmouve creeLastmouve()
{
    t_lastmouve mouve={0};
    mouve.actif=0;
    return mouve;
}
void newGame(struct jeu *jeu)
{
    jeu->etat=0;
    jeu->mouve=creeLastmouve();
    int nb=1;
    int quitter=0;
    char c;
    while(quitter==0)
    {
        system("cls");
        printf("   ______________________________________________\n");
        printf("  |                                              |\n");
        printf("  |  A COMBIEN DE JOUEUR SOUHAITEZ-VOUS JOUER ?  |\n");
        printf("  |                 2 JOUEURS                    |\n");
        printf("  |                 4 JOUEURS                    |\n");
        printf("  |______________________________________________|\n");
        gotoligcol(nb+2,17);
        Color(10,0);
        printf("->");
        gotoligcol(nb+2,30);
        printf("<-");
        Color(15,0);
        gotoligcol(0,0);
        c=toucheAppuiez();
        if(c=='z'&&nb>1)
        {
            nb--;
        }
        if(c=='s'&&nb<2)
        {
            nb++;
        }
        if(c==' ')
        {
            quitter=1;
        }
    }
    system("cls");
    if(nb==1)
    {
        jeu->j1=creeJoueur();
        int ok=0;
        while(ok==0)
        {
            jeu->j2=creeJoueur();
            if(strcmp(jeu->j2.nom,jeu->j1.nom)==0)
            {
                printf("Erreur joueur deja conecter\n");
            }
            else
            {
                ok=1;
            }
        }

        ok=0;
        while(ok==0)
        {
           if(jeu->j2.crosshaire.type==jeu->j1.crosshaire.type)
           {
               jeu->j2.crosshaire=creeCrossaire();
           }
           else
           {
               ok=1;
           }
        }
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
    else if(nb==2)
    {
        jeu->j1=creeJoueur();
        int ok=0;
        while(ok==0)
        {
            jeu->j2=creeJoueur();
            if(strcmp(jeu->j2.nom,jeu->j1.nom)==0)
            {
                printf("Erreur joueur deja conecter\n");
            }
            else
            {
                ok=1;
            }
        }
        ok=0;
        while(ok==0)
        {
            jeu->j3=creeJoueur();
            if(strcmp(jeu->j3.nom,jeu->j1.nom)==0||strcmp(jeu->j3.nom,jeu->j2.nom)==0)
            {
                printf("Erreur joueur deja conecter\n");
            }
            else
            {
                ok=1;
            }
        }
        ok=0;
        while(ok==0)
        {
            jeu->j4=creeJoueur();
            if(strcmp(jeu->j4.nom,jeu->j1.nom)==0||strcmp(jeu->j4.nom,jeu->j2.nom)==0||strcmp(jeu->j4.nom,jeu->j3.nom)==0)
            {
                printf("Erreur joueur deja conecter\n");
            }
            else
            {
                ok=1;
            }
        }
        ok=0;
        while(ok==0)
        {
           if(jeu->j2.crosshaire.type==jeu->j1.crosshaire.type)
           {
               jeu->j2.crosshaire=creeCrossaire();
           }
           else
           {
               ok=1;
           }
        }
        ok=0;
        while(ok==0)
        {
           if(jeu->j3.crosshaire.type==jeu->j1.crosshaire.type||jeu->j3.crosshaire.type==jeu->j2.crosshaire.type)
           {
               jeu->j3.crosshaire=creeCrossaire();
           }
           else
           {
               ok=1;
           }
        }
        ok=0;
        while(ok==0)
        {
           if(jeu->j4.crosshaire.type==jeu->j1.crosshaire.type||jeu->j4.crosshaire.type==jeu->j2.crosshaire.type||jeu->j4.crosshaire.type==jeu->j3.crosshaire.type)
           {
               jeu->j4.crosshaire=creeCrossaire();
           }
           else
           {
               ok=1;
           }
        }
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
    jeu->terrain=creeTerrain();
    FILE *f=NULL;
    f=fopen("oldGame.txt","r");
    if(f==NULL)
    {
        printf("ERREUR ouverture fichier");
        return -1;
    }
    else
    {
        int test;
        char chaine[70];
        fscanf(f,"%d",&test);
        jeu->nbjoueur=test;
        char *d=',';
        if(jeu->nbjoueur==2)
        {
            jeu->ordrejeu.j=&jeu->j1;
            jeu->j1.startside='B';
            jeu->j2.startside='H';
            jeu->j1.next=&jeu->j2;
            jeu->j2.next=&jeu->j1;
        }
        else if(jeu->nbjoueur==4)
        {
            jeu->ordrejeu.j=&jeu->j1;
            jeu->j1.next=&jeu->j2;
            jeu->j2.next=&jeu->j3;
            jeu->j3.next=&jeu->j4;
            jeu->j4.next=&jeu->j1;
            jeu->j1.startside='B';
            jeu->j2.startside='G';
            jeu->j3.startside='H';
            jeu->j4.startside='D';
        }
        struct joueur *nextj=jeu->ordrejeu.j;
        for(int i=0;i<jeu->nbjoueur;i++)
        {
            fscanf(f,"%s",&chaine);
            printf("%s\n",chaine);
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
            nextj->chrono=atoi(p);
            nextj=nextj->next;
        }
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
    t_joueur *nextj=jeu.ordrejeu.j;
    int finJeu=0;

    while(finJeu==0)
    {
        time_t start = time (NULL);
        if(nextj->crosshaire.cor_x==-1&&nextj->crosshaire.cor_y==-1)
        {
            jeu.etat=0;
        }
        else
        {
            jeu.etat=1;
        }
        if(jeu.etat==0)
        {
            deplacement(nextj,&jeu);
        }
        else
        {
            finJeu=round(nextj,&jeu);
        }
        nextj->chrono+=(int) (time (NULL) - start);
        if(testFinJeu(nextj)==1)
        {
            setScore(jeu.j1.nom,jeu.j1.score);
            setScore(jeu.j2.nom,jeu.j2.score);
            if(jeu.nbjoueur==4)
            {
                setScore(jeu.j3.nom,jeu.j3.score);
                setScore(jeu.j4.nom,jeu.j4.score);
            }
            int quitter=0;
            system("cls");
            gotoligcol(0,0);
            while(quitter==0)
            {
                printf("Victoire de %s il remporte 5 point\n",nextj->nom);
                nextj->score+=5;
                finJeu=1;
                if(jeu.j1.chrono>jeu.j2.chrono&&jeu.j1.chrono>jeu.j3.chrono&&jeu.j1.chrono>jeu.j4.chrono)
                {
                    printf("Le joueur le plus lent a ete: %s avec %d s\n",jeu.j1.nom,jeu.j1.chrono);
                    nextj->score-=2;
                }
                if(jeu.j2.chrono>jeu.j1.chrono&&jeu.j2.chrono>jeu.j3.chrono&&jeu.j2.chrono>jeu.j4.chrono)
                {
                    printf("Le joueur le plus lent a ete: %s avec %d s\n",jeu.j2.nom,jeu.j2.chrono);
                    nextj->score-=2;
                }
                if(jeu.j3.chrono>jeu.j2.chrono&&jeu.j3.chrono>jeu.j1.chrono&&jeu.j3.chrono>jeu.j4.chrono)
                {
                    printf("Le joueur le plus lent a ete: %s avec %d s\n",jeu.j3.nom,jeu.j3.chrono);
                    nextj->score-=2;
                }
                if(jeu.j4.chrono>jeu.j2.chrono && jeu.j4.chrono>jeu.j3.chrono && jeu.j4.chrono>jeu.j1.chrono)
                {
                    printf("Le joueur le plus lent a ete: %s avec %d s\n",jeu.j4.nom,jeu.j4.chrono);
                    nextj->score-=2;
                }
                printf("Appuiez sur espace pour revenir au menue principal\n");
                char c=toucheAppuiez();
                if(c==' ')
                {
                    quitter=1;
                }
            }
        }
        nextj=nextj->next;
    }
}
int round(struct joueur *j, struct jeu *jeu)
{
    char message[100]={' '};

    int choix=1;
    char c;
    int tourjouer=0;
    while(tourjouer==0)
    {

        int quitter=0;
        while(quitter==0)
        {
            affichage(*jeu,*j);
            gotoligcol(25,40);
            Color(4,0);
            printf("%s",message);
            Color(15,0);
            gotoligcol(20,0);
            printf("         DEPLACER MON PION      \n");
            printf("        POSER UNE BARRIERE      \n");
            printf("           NE RIEN FAIRE        \n");
            printf("   ANNULER LE DERNIER MOUVEMENT \n");
            Color(12,0);
            printf("              QUITTER           \n");
            gotoligcol(19+choix,0);
            Color(10,0);
            printf("->");
            gotoligcol(19+choix,32);
            printf("<-");
            Color(15,0);
            gotoligcol(30,0);
            c=toucheAppuiez();
            if(c=='z'&&choix>1)
            {
               choix--;
            }
            if(c=='s'&&choix<5)
            {
                choix++;
            }
            if(c==' ')
            {
                quitter=1;
            }
        }
        switch (choix)
        {
            case 1:
                jeu->mouve.actif=1;
                jeu->mouve.j1.crosshaire.cor_x=jeu->j1.crosshaire.cor_x;
                jeu->mouve.j1.crosshaire.cor_y=jeu->j1.crosshaire.cor_y;
                jeu->mouve.j2.crosshaire.cor_x=jeu->j2.crosshaire.cor_x;
                jeu->mouve.j2.crosshaire.cor_y=jeu->j2.crosshaire.cor_y;
                jeu->mouve.j3.crosshaire.cor_x=jeu->j3.crosshaire.cor_x;
                jeu->mouve.j3.crosshaire.cor_y=jeu->j3.crosshaire.cor_y;
                jeu->mouve.j4.crosshaire.cor_x=jeu->j4.crosshaire.cor_x;
                jeu->mouve.j4.crosshaire.cor_y=jeu->j4.crosshaire.cor_y;
                jeu->mouve.j1.nb_bariere=jeu->j1.nb_bariere;
                jeu->mouve.j2.nb_bariere=jeu->j2.nb_bariere;
                jeu->mouve.j3.nb_bariere=jeu->j3.nb_bariere;
                jeu->mouve.j4.nb_bariere=jeu->j4.nb_bariere;
                for(int i=0;i<20;i++)
                {
                    jeu->mouve.bariere[i].active=jeu->bariere[i].active;
                    jeu->mouve.bariere[i].cord_x1=jeu->bariere[i].cord_x1;
                    jeu->mouve.bariere[i].cord_x2=jeu->bariere[i].cord_x2;
                    jeu->mouve.bariere[i].cord_y2=jeu->bariere[i].cord_y2;
                    jeu->mouve.bariere[i].cord_y1=jeu->bariere[i].cord_y1;
                    jeu->mouve.bariere[i].sens=jeu->bariere[i].sens;
                }
                deplacement(j,jeu);
                tourjouer=1;
                break;
            case 2:
                if(j->nb_bariere>0)
                {
                    jeu->mouve.actif=1;
                    jeu->mouve.j1.crosshaire.cor_x=jeu->j1.crosshaire.cor_x;
                    jeu->mouve.j1.crosshaire.cor_y=jeu->j1.crosshaire.cor_y;
                    jeu->mouve.j2.crosshaire.cor_x=jeu->j2.crosshaire.cor_x;
                    jeu->mouve.j2.crosshaire.cor_y=jeu->j2.crosshaire.cor_y;
                    jeu->mouve.j3.crosshaire.cor_x=jeu->j3.crosshaire.cor_x;
                    jeu->mouve.j3.crosshaire.cor_y=jeu->j3.crosshaire.cor_y;
                    jeu->mouve.j4.crosshaire.cor_x=jeu->j4.crosshaire.cor_x;
                    jeu->mouve.j4.crosshaire.cor_y=jeu->j4.crosshaire.cor_y;
                    jeu->mouve.j1.nb_bariere=jeu->j1.nb_bariere;
                    jeu->mouve.j2.nb_bariere=jeu->j2.nb_bariere;
                    jeu->mouve.j3.nb_bariere=jeu->j3.nb_bariere;
                    jeu->mouve.j4.nb_bariere=jeu->j4.nb_bariere;
                    for(int i=0;i<20;i++)
                    {
                        jeu->mouve.bariere[i].active=jeu->bariere[i].active;
                        jeu->mouve.bariere[i].cord_x1=jeu->bariere[i].cord_x1;
                        jeu->mouve.bariere[i].cord_x2=jeu->bariere[i].cord_x2;
                        jeu->mouve.bariere[i].cord_y2=jeu->bariere[i].cord_y2;
                        jeu->mouve.bariere[i].cord_y1=jeu->bariere[i].cord_y1;
                        jeu->mouve.bariere[i].sens=jeu->bariere[i].sens;
                    }
                    placerBariere(jeu,j);
                    tourjouer=1;
                }
                else
                {
                    strcpy(message,"ERREUR: vous n'avez plus de bariere a placer");
                }
                break;
            case 3:
                tourjouer=1;
                break;
            case 4:
                if(jeu->mouve.actif!=0)
                {
                    jeu->mouve.actif=0;
                    jeu->j1.crosshaire.cor_x=jeu->mouve.j1.crosshaire.cor_x;
                    jeu->j1.crosshaire.cor_y=jeu->mouve.j1.crosshaire.cor_y;
                    jeu->j2.crosshaire.cor_x=jeu->mouve.j2.crosshaire.cor_x;
                    jeu->j2.crosshaire.cor_y=jeu->mouve.j2.crosshaire.cor_y;
                    jeu->j3.crosshaire.cor_x=jeu->mouve.j3.crosshaire.cor_x;
                    jeu->j3.crosshaire.cor_y=jeu->mouve.j3.crosshaire.cor_y;
                    jeu->j4.crosshaire.cor_x=jeu->mouve.j4.crosshaire.cor_x;
                    jeu->j4.crosshaire.cor_y=jeu->mouve.j4.crosshaire.cor_y;
                    jeu->j1.nb_bariere=jeu->mouve.j1.nb_bariere;
                    jeu->j2.nb_bariere=jeu->mouve.j2.nb_bariere;
                    jeu->j3.nb_bariere=jeu->mouve.j3.nb_bariere;
                    jeu->j4.nb_bariere=jeu->mouve.j4.nb_bariere;
                    for(int i=0;i<20;i++)
                    {
                        jeu->bariere[i].active=jeu->mouve.bariere[i].active;
                        jeu->bariere[i].cord_x1=jeu->mouve.bariere[i].cord_x1;
                        jeu->bariere[i].cord_x2=jeu->mouve.bariere[i].cord_x2;
                        jeu->bariere[i].cord_y2=jeu->mouve.bariere[i].cord_y2;
                        jeu->bariere[i].cord_y1=jeu->mouve.bariere[i].cord_y1;
                        jeu->bariere[i].sens=jeu->mouve.bariere[i].sens;
                    }
                    tourjouer=1;
                }
                else
                {
                    strcpy(message,"Il n'y a pas eu de mouvement sur le plateau pour l'instant");
                }
                break;
            case 5:
                enregistrement(*jeu);
                tourjouer=1;
                return 1;
                break;
        }
    }
    return 0;
}
void deplacement(struct joueur *j,struct jeu *jeu)
{
    int x=j->crosshaire.cor_x;
    int y=j->crosshaire.cor_y;
    if(jeu->etat==0)
    {
        int quitter=0;
        if(j->startside=='B')
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=8;
            while(quitter==0)
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'q':
                        if(j->crosshaire.cor_x-1>=0)
                        {
                            j->crosshaire.cor_x-=1;
                        }
                        break;
                    case 'd':
                        if(j->crosshaire.cor_x+1<9)//on sort par la droit
                        {
                            j->crosshaire.cor_x+=1;
                        }
                        break;
                    case ' ':
                        quitter=1;
                        break;
                }
            }
        }
        if(j->startside=='H')
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=0;
            while(quitter==0)
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'q':
                        if(j->crosshaire.cor_x-1>=0)
                        {
                            j->crosshaire.cor_x-=1;
                        }
                        break;
                    case 'd':
                        if(j->crosshaire.cor_x+1<9)//on sort par la droit
                        {
                            j->crosshaire.cor_x+=1;
                        }
                        break;
                    case ' ':
                        quitter=1;
                        break;
                }
            }
        }
        if(j->startside=='G')
        {
            j->crosshaire.cor_x=0;
            j->crosshaire.cor_y=5;
            while(quitter==0)
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'z':
                        if(j->crosshaire.cor_y-1>=0)
                        {
                            j->crosshaire.cor_y-=1;
                        }
                        break;
                    case 's':
                        if(j->crosshaire.cor_y+1<9)//on sort par le bas
                        {
                            j->crosshaire.cor_y+=1;
                        }
                        break;
                    case ' ':
                        quitter=1;
                        break;
                }
            }
        }
        if(j->startside=='D')
        {
            j->crosshaire.cor_x=8;
            j->crosshaire.cor_y=5;
            while(quitter==0)
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'z':
                        if(j->crosshaire.cor_y-1>=0)
                        {
                            j->crosshaire.cor_y-=1;
                        }
                        break;
                    case 's':
                        if(j->crosshaire.cor_y+1<9)//on sort par le bas
                        {
                            j->crosshaire.cor_y+=1;
                        }
                        break;
                    case ' ':
                        quitter=1;
                        break;
                }
            }
        }
    }
    else
    {
        int quitter=0;
        do
        {
            affichage(*jeu,*j);
            char c;
            fflush(stdin);
            c = toucheAppuiez();
            int possible=0;
            fflush(stdin);
            int debug;
            switch(c)
            {
                case 'q':
                    if(j->crosshaire.cor_x-1>=0)//on sort par la gauche
                    {
                        if(j->crosshaire.cor_x-1>x-2&&j->crosshaire.cor_y==y)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x-1,j->crosshaire.cor_y,'g')==0)
                            {
                               j->crosshaire.cor_x-=1;
                            }
                        }
                    }
                    break;
                case 'd':
                    if(j->crosshaire.cor_x+1<9)//on sort par la droit
                        if(j->crosshaire.cor_x+1<x+2&&j->crosshaire.cor_y==y)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x+1,j->crosshaire.cor_y,'d')==0)
                            {
                               j->crosshaire.cor_x+=1;
                            }
                        }
                    break;
                case 'z':
                    if(j->crosshaire.cor_y-1>=0)//on sort par le haut
                        if(j->crosshaire.cor_y-1>y-2&&j->crosshaire.cor_x==x)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y-1,'h')==0)
                            {
                               j->crosshaire.cor_y-=1;
                            }
                        }
                    break;
                case 's':
                    if(j->crosshaire.cor_y+1<9)//on sort par le bas
                        if(j->crosshaire.cor_y+1<y+2&&j->crosshaire.cor_x==x)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y+1,'b')==0)
                            {
                               j->crosshaire.cor_y+=1;
                            }
                        }
                    break;
                case 'v':
                    quitter=1;
                    j->crosshaire.cor_x=x;
                    j->crosshaire.cor_y=y;
                    break;
                case ' ':
                    quitter=1;
                    break;
            }
        }while(quitter==0);
    }
}
int deplacementPossible(struct jeu jeu, struct joueur j, int x, int y,char sens)
{
    int pos=0;
    gotoligcol(30,0);
    for(int i=0;i<20;i++)
    {

        if(jeu.bariere[i].active==1)
        {

            if(sens=='h')
            {
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y-1)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y-1)
                {
                    pos=1;
                }
            }
            if(sens=='b')
            {
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1-1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2-1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
            }
            if(sens=='d')
            {
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x1-1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x2-1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
            }
            if(sens=='g')
            {
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x1==j.crosshaire.cor_x-1&&jeu.bariere[i].cord_y1==j.crosshaire.cor_y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x2==j.crosshaire.cor_x-1&&jeu.bariere[i].cord_y2==j.crosshaire.cor_y)
                {
                    pos=1;
                }
            }
        }
    }
    struct joueur *nextj=jeu.ordrejeu.j;
    for(int i=0;i<jeu.nbjoueur;i++)
    {
        if(strcmp(nextj->nom,j.nom)!=0)
        {
            //printf("%s:%d,%d,%d,%d\n",nextj->nom,nextj->crosshaire.cor_x,nextj->crosshaire.cor_y,x,y);
            if(nextj->crosshaire.cor_x==x&&nextj->crosshaire.cor_x==y)
            {
                pos=1;
            }
        }

        nextj=nextj->next;
    }
    return pos;
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
    jeu->bariere[nb].cord_x2 = 1;
    jeu->bariere[nb].cord_y2 = 0;
    jeu->bariere[nb].sens='h';
    jeu->bariere[nb].active=2;
    do
    {
        affichage(*jeu,*j);
        char c;
        fflush(stdin);
        c = toucheAppuiez();
        switch (c)
        {
            case 'q': //gauche
                if(jeu->bariere[nb].cord_x1-1<8&&jeu->bariere[nb].cord_x1-1>=0)
                    deplacementBariere(jeu,nb,-1,0,0);
                break;
            case 'd'://droite
                if(jeu->bariere[nb].cord_x1+1<8&&jeu->bariere[nb].cord_x1+1>=0)
                    deplacementBariere(jeu,nb,1,0,0);
                break;
            case 'z'://haut
                if(jeu->bariere[nb].cord_y1-1<8&&jeu->bariere[nb].cord_y1-1>=0)
                    deplacementBariere(jeu,nb,0,-1,0);
                break;
            case 's'://bas
                if(jeu->bariere[nb].cord_y1+1<8&&jeu->bariere[nb].cord_y1+1>=0)
                    deplacementBariere(jeu,nb,0,1,0);
                break;
            case 'e'://rotation droite
                deplacementBariere(jeu,nb,0,0,1);
                break;
            case 'a'://rotation gauche
                deplacementBariere(jeu,nb,0,0,-1);
                break;
            case ' '://valider
                if(jeu->bariere[nb].active==2)
                {
                    placer=1;
                    jeu->bariere[nb].active=1;
                    j->nb_bariere--;
                }
                break;
            case 'v'://annuler
                placer=1;
                jeu->bariere[nb].active=0;
                break;
        }
        gotoligcol(30,0);
        ///VERIF SI ON PEUT POSSER LA BARIERE
        if(jeu->bariere[nb].active!=0)
        {
            for(int i=0;i<20;i++)
            {
                //printf("nb: %d,sens:%c,x1:%d,y1:%d,x2:%d,y2:%d \n ",jeu->bariere[i].id,jeu->bariere[i].sens,jeu->bariere[i].cord_x1,jeu->bariere[i].cord_y1,jeu->bariere[i].cord_x2,jeu->bariere[i].cord_y2);
                if(jeu->bariere[i].id!=nb+1&&jeu->bariere[i].active==1)
                {
                    if(jeu->bariere[i].sens==jeu->bariere[nb].sens)
                    {
                        if(jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                    }
                    if(jeu->bariere[i].sens=='h'&&jeu->bariere[nb].sens=='b')
                    {
                        if(jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y1-1 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y2-1 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y2-1 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y1-1 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                    }
                    if(jeu->bariere[i].sens=='b'&&jeu->bariere[nb].sens=='h')
                    {
                        if(jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1-1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y1-1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y2-1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y2-1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                    }
                    if(jeu->bariere[i].sens=='g'&&jeu->bariere[nb].sens=='d')
                    {
                        if(jeu->bariere[i].cord_x1-1 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2-1 == jeu->bariere[nb].cord_x1 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2-1 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if (jeu->bariere[i].cord_x1-1 == jeu->bariere[nb].cord_x2 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                    }
                    if(jeu->bariere[i].sens=='d'&&jeu->bariere[nb].sens=='g')
                    {
                        if(jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x1-1 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x1-1 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y1)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if(jeu->bariere[i].cord_x2 == jeu->bariere[nb].cord_x2-1 && jeu->bariere[i].cord_y2 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                        if (jeu->bariere[i].cord_x1 == jeu->bariere[nb].cord_x2-1 && jeu->bariere[i].cord_y1 == jeu->bariere[nb].cord_y2)
                        {
                            jeu->bariere[nb].active = 3;
                        }
                    }
                }
            }
            struct joueur *nextj=jeu->ordrejeu.j;
            for(int i=0;i<jeu->nbjoueur;i++)
            {
                if(jeu->bariere[nb].cord_x1==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y1==nextj->crosshaire.cor_y || jeu->bariere[nb].cord_x2==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y2==nextj->crosshaire.cor_y)
                {
                    jeu->bariere[nb].active = 3;
                }
                if(jeu->bariere[nb].sens=='h')
                {
                    if(jeu->bariere[nb].cord_x1==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y1-1==nextj->crosshaire.cor_y || jeu->bariere[nb].cord_x2==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y2-1==nextj->crosshaire.cor_y)
                    {
                        jeu->bariere[nb].active = 3;
                    }
                }
                if(jeu->bariere[nb].sens=='b')
                {
                    if(jeu->bariere[nb].cord_x1==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y1==nextj->crosshaire.cor_y-1 || jeu->bariere[nb].cord_x2==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y2==nextj->crosshaire.cor_y-1)
                    {
                        jeu->bariere[nb].active = 3;
                    }
                }
                if(jeu->bariere[nb].sens=='g')
                {
                    if(jeu->bariere[nb].cord_x1-1==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y1==nextj->crosshaire.cor_y || jeu->bariere[nb].cord_x2-1==nextj->crosshaire.cor_x&&jeu->bariere[nb].cord_y2==nextj->crosshaire.cor_y)
                    {
                        jeu->bariere[nb].active = 3;
                    }
                }
                if(jeu->bariere[nb].sens=='d')
                {
                    if(jeu->bariere[nb].cord_x1==nextj->crosshaire.cor_x-1&&jeu->bariere[nb].cord_y1==nextj->crosshaire.cor_y || jeu->bariere[nb].cord_x2==nextj->crosshaire.cor_x-1&&jeu->bariere[nb].cord_y2==nextj->crosshaire.cor_y)
                    {
                        jeu->bariere[nb].active = 3;
                    }
                }
                nextj=nextj->next;
            }
        }
    }while(placer==0);
}
void deplacementBariere(struct jeu *j,int nb,int x,int y,int direction)
{
    j->bariere[nb].cord_x1+=x;
    j->bariere[nb].cord_y1+=y;
    j->bariere[nb].active=2;

    if(j->bariere[nb].sens=='h')
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='b')
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='g')
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='d')
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    if(direction==1)
    {
        if(j->bariere[nb].sens=='h')
        {
            j->bariere[nb].sens='d';
            j->bariere[nb].cord_x2-=1;
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='b')
        {
            j->bariere[nb].sens='g';
            j->bariere[nb].cord_x2-=1;
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='g')
        {
            j->bariere[nb].sens='h';
            j->bariere[nb].cord_x2+=1;
            j->bariere[nb].cord_y2-=1;
        }
        else if(j->bariere[nb].sens=='d')
        {
            j->bariere[nb].sens='b';
            j->bariere[nb].cord_x2+=1;
            j->bariere[nb].cord_y2-=1;
        }
    }
    if(direction==-1)
    {
        if(j->bariere[nb].sens=='h')
        {
            j->bariere[nb].sens='g';
            j->bariere[nb].cord_x2-=1;
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='b')
        {
            j->bariere[nb].sens='d';
            j->bariere[nb].cord_x2-=1;
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='g')
        {
            j->bariere[nb].sens='b';
            j->bariere[nb].cord_x2+=1;
            j->bariere[nb].cord_y2-=1;
        }
        else if(j->bariere[nb].sens=='d')
        {
            j->bariere[nb].sens='h';
            j->bariere[nb].cord_x2+=1;
            j->bariere[nb].cord_y2-=1;
        }
    }
}
int testFinJeu(struct joueur *j)
{
    if(j->startside=='B')
        if(j->crosshaire.cor_y==0)
            return 1;
    else if(j->startside=='D')
        if(j->crosshaire.cor_x==0)
            return 1;
    else if(j->startside=='G')
        if(j->crosshaire.cor_x==8)
            return 1;
    else if(j->startside=='H')
        if(j->crosshaire.cor_y==8)
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
            fprintf(f,"%s,%d,%c,%d,%d,%d,%d\n",nextj->nom,nextj->score,nextj->crosshaire.type,nextj->crosshaire.cor_x,nextj->crosshaire.cor_y,nextj->nb_bariere,nextj->chrono);
            nextj=nextj->next;
        }
        for(int i=0;i<20;i++)
        {
            fprintf(f,"%d,%d,%d,%d,%d,%c,%d\n",jeu.bariere[i].id,jeu.bariere[i].cord_x1,jeu.bariere[i].cord_y1,jeu.bariere[i].cord_x2,jeu.bariere[i].cord_y2,jeu.bariere[i].sens,jeu.bariere[i].active);
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
        if(jeu.bariere[i].active!=0)
        {
            if(jeu.bariere[i].active==1)
            {
                Color(15,0);
            }
            if(jeu.bariere[i].active==2)
            {
                Color(2,0);
            }
            if(jeu.bariere[i].active==3)
            {
                Color(4,0);
            }

            if(jeu.bariere[i].sens=='h')
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+1,jeu.bariere[i].cord_x1*4+5);
                printf("%c%c%c%c%c%c%c",0xcd,0xcd,0xcd,0xce,0xcd,0xcd,0xcd);
            }
            if(jeu.bariere[i].sens=='b')
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+3,jeu.bariere[i].cord_x1*4+5);
                printf("%c%c%c%c%c%c%c",0xcd,0xcd,0xcd,0xce,0xcd,0xcd,0xcd);
            }
            if(jeu.bariere[i].sens=='d')
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+2,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xba);
                gotoligcol(jeu.bariere[i].cord_y1*2+3,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xce);
                gotoligcol(jeu.bariere[i].cord_y1*2+4,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xba);
            }
            if(jeu.bariere[i].sens=='g')
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+2,jeu.bariere[i].cord_x1*4+4);
                printf("%c",0xba);
                gotoligcol(jeu.bariere[i].cord_y1*2+3,jeu.bariere[i].cord_x1*4+4);
                printf("%c",0xce);
                gotoligcol(jeu.bariere[i].cord_y1*2+4,jeu.bariere[i].cord_x1*4+4);
                printf("%c",0xba);
            }
        }
        Color(15,0);
    }
}
void affichage(struct jeu jeu,struct joueur j)
{
    system("cls");
    affichageTerrain(jeu.terrain);
    afficherBariere(jeu);
    affichageJoueur(jeu);
    gotoligcol(0,50);
    printf("NOMBRE DE JOUEURS : %d",jeu.nbjoueur);
    gotoligcol(4,50);
    printf("JOUEUR : %s",j.nom);
    gotoligcol(8,50);
    printf("SCORE PARTIE : %d",j.score);
    gotoligcol(12,50);
    printf("JETON : %c",j.crosshaire.type);
    gotoligcol(16,50);
    printf("BARRIERES RESTANTES : %d",j.nb_bariere);
    gotoligcol(19,50);
    printf("    [%c]",0x18);
    gotoligcol(20,50);
    printf("[<-][%c][->]  Pour se deplacer",0x19);
    gotoligcol(21,50);
    Color(10,0);
    printf("  [SPACE]    Pour valider");
    gotoligcol(22,50);
    Color(12,0);
    printf("  [ESCAPE]   Pour annuler");
    gotoligcol(23,50);
    Color(15,0);
    printf("  [CRTL]     Pour rotation anti-horaire");
    gotoligcol(24,50);
    printf("  [ALT]      Pour rotation horaire");
    gotoligcol(20,0);
    gotoligcol(10,50);
    printf("DUREE : %d sec",j.chrono);
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
        if(GetAsyncKeyState(VK_CONTROL)&0x11)
        {
            cara='a';
            break;
        }
        if(GetAsyncKeyState(VK_MENU)&0x11)
        {
            cara='e';
            break;
        }
    }
    return cara;
}
