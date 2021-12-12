#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.h"
#include <windows.h>
#include <string.h>

struct jeu creeJeu(void)//methode de creation de la structure jeu
{
    t_jeu jeu={NULL};
    return jeu;
}
struct lastmouve creeLastmouve()//methode de creation de la stucture lastmouve
{
    t_lastmouve mouve={0};
    mouve.actif=0;
    return mouve;
}
void newGame(struct jeu *jeu)//methode pour cree une nouvelle partie
{
    jeu->etat=0;
    jeu->mouve=creeLastmouve();//appel de la methode de creation de la structure
    int nb=1;
    int quitter=0;
    char c;
    while(quitter==0)//demande si l'utilisateur veux jouer a 2 ou 4
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
    if(nb==1)//choix 2 joueur
    {
        jeu->j1=creeJoueur();//creation j1
        int ok=0;
        while(ok==0)
        {
            jeu->j2=creeJoueur();//creation j2
            if(strcmp(jeu->j2.nom,jeu->j1.nom)==0)//verifiaction si le pseudo est pas le meme
            {
                printf("Erreur joueur deja conecter\n");
            }
            else
            {
                ok=1;
            }
        }

        ok=0;
        while(ok==0)//verification que les pion des joueur ne sont pas les meme
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
        jeu->j1.nb_bariere=10;//on assigne 1O bariere a chaque joueur
        jeu->j2.nb_bariere=10;
        jeu->j1.next=&jeu->j2;//on assigne les joueur suivant de chaque joueur
        jeu->j2.next=&jeu->j1;
        int nb=rand()%2;//on tire au hasard le joueur qui commence
        if(nb==0)//j1 commence
        {
            jeu->ordrejeu.j=&(jeu->j1);
            jeu->j1.startside='B';//on leur assigne un coté de demarage
            jeu->j2.startside='H';
        }
        if(nb==1)//j2 commence
        {
            jeu->ordrejeu.j=&(jeu->j2);
            jeu->j1.startside='H';//on leur assigne un coté de demarage
            jeu->j2.startside='B';
        }
    }
    else if(nb==2)//si 4 joueur
    {
        jeu->j1=creeJoueur();//creation j1
        int ok=0;
        while(ok==0)//creation j2 en verifiant qu'il ai pas le meme pseudo que les joueur deja connecter
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
        while(ok==0)//creation j3 en verifiant qu'il ai pas le meme pseudo que les joueur deja connecter
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
        while(ok==0)//creation j4 en verifiant qu'il ai pas le meme pseudo que les joueur deja connecter
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
        while(ok==0)//on verifie que les joueur n'ont pas les meme pion
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
        while(ok==0)//on verifie que les joueur n'ont pas les meme pion
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
        while(ok==0)//on verifie que les joueur n'ont pas les meme pion
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
        jeu->j1.nb_bariere=5;//on assigne 5 bariere par joueur
        jeu->j2.nb_bariere=5;
        jeu->j3.nb_bariere=5;
        jeu->j4.nb_bariere=5;
        jeu->j1.next=&jeu->j2;//on assigne les joueur suivant de chaque joueur
        jeu->j2.next=&jeu->j3;
        jeu->j3.next=&jeu->j4;
        jeu->j4.next=&jeu->j1;
        int nb=rand()%4;//on tire au sort le joueur qui commence
        if(nb==0)//si c'est le j1
        {
            jeu->ordrejeu.j=&(jeu->j1);
            jeu->j1.startside='B';//on leur assigne un coté de demarage
            jeu->j2.startside='G';
            jeu->j3.startside='H';
            jeu->j4.startside='D';
        }
        if(nb==1)//si c'est le j2
        {
            jeu->ordrejeu.j=&(jeu->j2);
            jeu->j1.startside='D';
            jeu->j2.startside='B';//on leur assigne un coté de demarage
            jeu->j3.startside='G';
            jeu->j4.startside='H';
        }
        if(nb==2)//si c'est le j3
        {
            jeu->ordrejeu.j=&(jeu->j3);
            jeu->j1.startside='H';//on leur assigne un coté de demarage
            jeu->j2.startside='D';
            jeu->j3.startside='B';
            jeu->j4.startside='G';
        }
        if(nb==3)//si c'est le j4
        {
            jeu->ordrejeu.j=&(jeu->j4);
            jeu->j1.startside='G';//on leur assigne un coté de demarage
            jeu->j2.startside='H';
            jeu->j3.startside='D';
            jeu->j4.startside='B';
        }
    }
    jeu->terrain=creeTerrain();//on cree le terrain
    for(int i=0;i<20;i++)//on cree les bariere
    {
        jeu->bariere[i]=creeBariere();
        jeu->bariere[i].id=i+1;
    }
}
void oldGame(struct jeu *jeu)//methode pour cree une partie insrive dans un fichier
{
    jeu->terrain=creeTerrain();//on cree le terrain
    FILE *f=NULL;
    f=fopen("oldGame.txt","r");//on ouvre le fichier de la partie
    if(f==NULL)//verif si pb d'ouverture
    {
        printf("ERREUR ouverture fichier");
        return -1;
    }
    else
    {
        int test;
        char chaine[70];
        fscanf(f,"%d",&test);
        jeu->nbjoueur=test;//on recupere le nb de joueur
        char *d=',';
        if(jeu->nbjoueur==2)//si il y a 2 joueur
        {
            jeu->ordrejeu.j=&jeu->j1;//on designe le joueur qui commence
            jeu->j1.startside='B';//on leur assigne un coté de demarage
            jeu->j2.startside='H';
            jeu->j1.next=&jeu->j2;//on assigne les joueur suivant de chaque joueur
            jeu->j2.next=&jeu->j1;
        }
        else if(jeu->nbjoueur==4)
        {
            jeu->ordrejeu.j=&jeu->j1;//on designe le joueur qui commence
            jeu->j1.next=&jeu->j2;//on assigne les joueur suivant de chaque joueur
            jeu->j2.next=&jeu->j3;
            jeu->j3.next=&jeu->j4;
            jeu->j4.next=&jeu->j1;
            jeu->j1.startside='B';//on leur assigne un coté de demarage
            jeu->j2.startside='G';
            jeu->j3.startside='H';
            jeu->j4.startside='D';
        }
        else//verif si le fichier est bien ecrit
        {
            return -1;
        }
        struct joueur *nextj=jeu->ordrejeu.j;//on prend le premier joueur
        for(int i=0;i<jeu->nbjoueur;i++)//autant de fois qu'il y a de joueur
        {
            fscanf(f,"%s",&chaine);//on recupere la ligne du fichier
            char *p = strtok(chaine, ",");//on split la ligne au niveau de la virgule
            strcpy(nextj->nom,p);//on enregiste le nom
            p=strtok(NULL, ",");
            nextj->score=atoi(p);//on enregiste le score
            p=strtok(NULL, ",");
            nextj->crosshaire.type=p[0];//on enregiste le caractere du pion
            p= strtok(NULL, ",");
            nextj->crosshaire.cor_x=atoi(p);//on enregiste ses coordoner x et y
            p= strtok(NULL, ",");
            nextj->crosshaire.cor_y=atoi(p);
            p= strtok(NULL, ",");
            nextj->nb_bariere=atoi(p);//on enregiste le nb de bariere qu'il lui reste
            p= strtok(NULL, ",");
            nextj->chrono=atoi(p);//on enregiste le temps de jeu depuis le debut
            nextj=nextj->next;//on passe au joueur suivant
        }
        for(int i=0;i<20;i++)//on enregistre chaque bariere
        {
            fscanf(f,"%s",&chaine);
            char *p=strtok(chaine, ",");//on recupere la ligne dans le fichier
            jeu->bariere[i].id=atoi(p);//on enregiste son id
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_x1=atoi(p);//on enregiste ses cordonne x et y de chaque case
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_y1=atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_x2 = atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].cord_y2 = atoi(p);
            p=strtok(NULL, ",");
            jeu->bariere[i].sens=p[0];//on enregistre son sens
            p=strtok(NULL, ",");
            jeu->bariere[i].active=atoi(p);//on enregiste si elle est active ou pas
        }
        fscanf(f,"%d",&jeu->etat);//on enregiste l'etat du jeu
        for(int i=0;i<7;i++)// on enregistre chaque case bonus
        {
            fscanf(f,"%s",&chaine);//on recupere la chaine
            char *p=strtok(chaine, ",");
            jeu->terrain.casebonus[i].active=atoi(p);//on enregiste si elle a deja ete recupere
            p=strtok(NULL, ",");
            jeu->terrain.casebonus[i].x=atoi(p);//on enregiste ses cordonner x et y
            p=strtok(NULL, ",");
            jeu->terrain.casebonus[i].y=atoi(p);
            p=strtok(NULL, ",");
            jeu->terrain.casebonus[i].valeur=atoi(p);//on enregiste sa valeur
        }
    }
    fclose(f);
}
void startGame(int load)//methode pour le demarage de partie
{
    t_jeu jeu=creeJeu();//cree la partie
    if(load==0)//si on cree une nouvelle partie
        newGame(&jeu);
    else
        oldGame(&jeu);//si on charge une partie a partir d'un fichier
    t_joueur *nextj=jeu.ordrejeu.j;//on recupere le premiere joueur qui joue
    int finJeu=0;

    while(finJeu==0)//boucle de jeu qui s'arrete si in choisi d'arreter la partie ou si la partie est fini
    {
        time_t start = time (NULL);//on demare le timer du joueur
        if(nextj->crosshaire.cor_x==-1&&nextj->crosshaire.cor_y==-1)//si c'est le premier tour
        {
            jeu.etat=0;
        }
        else
        {
            jeu.etat=1;
        }
        if(jeu.etat==0)//si c'est le premier tour
        {
            deplacement(nextj,&jeu);//le joueur choisi ou se placer
        }
        else if(jeu.etat==1)//tours suivant
        {
            finJeu=round(nextj,&jeu);//le joueur choisi son action
        }
        nextj->chrono+=(int) (time (NULL) - start);//on stop le chrono et on incremente pour le joueur
        if(testFinJeu(nextj)==1||jeu.etat==2)//si un joueur a gagner
        {
            jeu.etat=2;
            enregistrement(jeu);//on enregistre le jeu
            setScore(jeu.j1.nom,jeu.j1.score);//on ajoute le nouveau score des joueur
            setScore(jeu.j2.nom,jeu.j2.score);
            if(jeu.nbjoueur==4)
            {
                setScore(jeu.j3.nom,jeu.j3.score);
                setScore(jeu.j4.nom,jeu.j4.score);
            }
            int quitter=0;
            system("cls");//on affiche l'ecan de fin de partie
            gotoligcol(0,0);
            while(quitter==0)
            {
                printf("Victoire de %s il remporte 5 point\n",nextj->nom);
                nextj->score+=5;
                finJeu=1;
                if(jeu.j1.chrono>jeu.j2.chrono&&jeu.j1.chrono>jeu.j3.chrono&&jeu.j1.chrono>jeu.j4.chrono)//on affiche le joueur avec le plus long timer
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
                printf("Appuiez sur espace pour revenir au menue principal\n");//on attend que le joueur appuie sur espace pour revenir au menu
                char c=toucheAppuiez();
                if(c==' ')
                {
                    quitter=1;
                }
            }
        }
        nextj=nextj->next;//on passe au joueur suivant
    }
}
int round(struct joueur *j, struct jeu *jeu)//methode de fonctionement du round
{
    char message[100]={' '};

    int choix=1;
    char c;
    int tourjouer=0;
    while(tourjouer==0)//tant que le tour n'a pas ete jouer par le joueur
    {

        int quitter=0;
        while(quitter==0)//on attend le choix du joueur et on lui propose ce qu'il peut faire
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
            case 1://si le joeur veux bouger son pion
                jeu->mouve.actif=1;
                jeu->mouve.j1.crosshaire.cor_x=jeu->j1.crosshaire.cor_x;//on enregistre les derniere valeur des coordonner de chaque joueur et bariere pour pouvoir annulez le coup plus tard
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
                deplacement(j,jeu);//appelle de la mathode de deplacement du pion
                tourjouer=1;
                break;
            case 2://si le choix est de placer une bariere
                if(j->nb_bariere>0)
                {
                    jeu->mouve.actif=1;
                    jeu->mouve.j1.crosshaire.cor_x=jeu->j1.crosshaire.cor_x;//on enregistre les derniere valeur des coordonner de chaque joueur et bariere pour pouvoir annulez le coup plus tard
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
                    placerBariere(jeu,j);//appelle de la mathode de deplacement des bariere
                    tourjouer=1;
                }
                else
                {
                    strcpy(message,"ERREUR: vous n'avez plus de bariere a placer");// si le joueur ne peut plus placer de bariere
                }
                break;
            case 3://si le joueur ne veux rien faire
                tourjouer=1;
                break;
            case 4://si le joueur veux annuler le dernier mouvement sur le plateau
                if(jeu->mouve.actif!=0)//on met a joueur les donnée avec celle enregister avant le dernier tour jouer seulement si il y a deja eu un tour jouer
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
                else//si il y a pas eu de tour jouer
                {
                    strcpy(message,"Il n'y a pas eu de mouvement sur le plateau pour l'instant");
                }
                break;
            case 5://si le joueur veux quitter
                enregistrement(*jeu);
                tourjouer=1;
                return 1;
                break;
        }
    }
    return 0;
}
void deplacement(struct joueur *j,struct jeu *jeu)//methode de deplacement du pion
{
    int x=j->crosshaire.cor_x;
    int y=j->crosshaire.cor_y;
    if(jeu->etat==0)//si c'est le premier tour
    {
        int quitter=0;
        if(j->startside=='B')//pour le joueur qui demare en bas
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=8;
            while(quitter==0)//il choisi sa case de depart
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'q':
                        if(j->crosshaire.cor_x-1>=0)//pour pas sortir du plateau
                        {
                            j->crosshaire.cor_x-=1;
                        }
                        break;
                    case 'd':
                        if(j->crosshaire.cor_x+1<9)//pour pas sortir du plateau
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
        if(j->startside=='H')//pour le joueur qui demare en haut
        {
            j->crosshaire.cor_x=5;
            j->crosshaire.cor_y=0;
            while(quitter==0)//il choisi sa case de depart
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'q':
                        if(j->crosshaire.cor_x-1>=0)//pour pas sortir du plateau
                        {
                            j->crosshaire.cor_x-=1;
                        }
                        break;
                    case 'd':
                        if(j->crosshaire.cor_x+1<9)//pour pas sortir du plateau
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
        if(j->startside=='G')//pour le joueur qui demare a gauche
        {
            j->crosshaire.cor_x=0;
            j->crosshaire.cor_y=5;
            while(quitter==0)//il choisi sa case de depart
            {
                affichage(*jeu,*j);
                gotoligcol(22,0);
                printf("Placer votre pion pour commencer");
                char c=toucheAppuiez();
                switch(c)
                {
                    case 'z':
                        if(j->crosshaire.cor_y-1>=0)//pour pas sortir du plateau
                        {
                            j->crosshaire.cor_y-=1;
                        }
                        break;
                    case 's':
                        if(j->crosshaire.cor_y+1<9)//pour pas sortir du plateau
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
        if(j->startside=='D')//pour le joueur qui demare a droite
        {
            j->crosshaire.cor_x=8;
            j->crosshaire.cor_y=5;
            while(quitter==0)//il choisi sa case de depart
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
    else//si c'est les autre tours
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
                case 'q'://si le joueur veux allez a gauche
                    if(j->crosshaire.cor_x-1>=0)//pour pas sortir du plateau
                    {
                        if(j->crosshaire.cor_x-1>x-2&&j->crosshaire.cor_y==y)//le joueur ne peut pas allez plus loin que 1 case de sa case de depart
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x-1,j->crosshaire.cor_y,'g')==0)//si il y a pas de bariere qui gene
                            {
                                if(joueurPresent(*jeu,*j,j->crosshaire.cor_x-1,j->crosshaire.cor_y)==1)//si il y a un pion qui gene
                                {
                                    if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x-2,j->crosshaire.cor_y,'g')==0)// si il y a pas de bariere apres le pion genant
                                    {
                                        j->crosshaire.cor_x-=2;//on saute par dessus le pion
                                    }
                                }
                                else
                                {
                                   j->crosshaire.cor_x-=1;//on avance d'une case vers la gauche
                                }
                            }
                        }
                    }
                    break;
                case 'd':
                    if(j->crosshaire.cor_x+1<9)//si le joueur veux allez a droite
                        if(j->crosshaire.cor_x+1<x+2&&j->crosshaire.cor_y==y)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x+1,j->crosshaire.cor_y,'d')==0)
                            {
                                if(joueurPresent(*jeu,*j,j->crosshaire.cor_x+1,j->crosshaire.cor_y)==1)
                                {
                                    if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x+2,j->crosshaire.cor_y,'d')==0)
                                    {
                                        j->crosshaire.cor_x+=2;
                                    }
                                }
                                else
                                {
                                   j->crosshaire.cor_x+=1;
                                }
                            }
                        }
                    break;
                case 'z':
                    if(j->crosshaire.cor_y-1>=0)//si le joueur veux allez en haut
                        if(j->crosshaire.cor_y-1>y-2&&j->crosshaire.cor_x==x)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y-1,'h')==0)
                            {
                                if(joueurPresent(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y-1)==1)
                                {
                                    if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y-2,'h')==0)
                                    {
                                        j->crosshaire.cor_y-=2;
                                    }
                                }
                                else
                                {
                                   j->crosshaire.cor_y-=1;
                                }
                            }
                        }
                    break;
                case 's':
                    if(j->crosshaire.cor_y+1<9)//si le joueur veux allez en bas
                        if(j->crosshaire.cor_y+1<y+2&&j->crosshaire.cor_x==x)
                        {
                            if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y+1,'b')==0)
                            {
                                if(joueurPresent(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y+1)==1)
                                {
                                    if(deplacementPossible(*jeu,*j,j->crosshaire.cor_x,j->crosshaire.cor_y+2,'b')==0)
                                    {
                                        j->crosshaire.cor_y+=2;
                                    }
                                }
                                else
                                {
                                   j->crosshaire.cor_y+=1;
                                }
                            }
                        }
                    break;
                case 'v'://si le joueur veux annuer son mouvement
                    quitter=1;
                    j->crosshaire.cor_x=x;
                    j->crosshaire.cor_y=y;
                    break;
                case ' '://si le joueur valide son mouvement
                    quitter=1;
                    j->score+=checkCase(j->crosshaire.cor_x,j->crosshaire.cor_y,&jeu->terrain);
                    break;
            }
        }while(quitter==0);
    }
}
int deplacementPossible(struct jeu jeu, struct joueur j, int x, int y,char sens)//methode de verification si une bariere ne gene pas
{
    int pos=0;
    gotoligcol(30,0);
    for(int i=0;i<20;i++)//on regarde pour chaque bariere
    {

        if(jeu.bariere[i].active==1)//si elle est active
        {

            if(sens=='h')//si le depalcement est vers le haut
            {
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1-1==y)//si la bariere est vers le haut et au meme coordonner que la case du pion
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2-1==y)//si la bariere est vers le haut et au meme coordon que la case du pion
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1==y)//si la bariere est vers le bas et juste au dessus de la case du pion
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2==y)//si la bariere est vers le bas et juste au dessus de la case du pion
                {
                    pos=1;
                }
            }
            if(sens=='b')//si le depalcement est vers le bas
            {
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1==y-1)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='b'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2==y-1)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='h'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2==y)
                {
                    pos=1;
                }
            }
            if(sens=='d')//si le depalcement est vers la droite
            {
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x1==x-1&&jeu.bariere[i].cord_y1==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x2==x-1&&jeu.bariere[i].cord_y2==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2==y)
                {
                    pos=1;
                }
            }
            if(sens=='g')//si le depalcement est vers la gauche
            {
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x1-1==x&&jeu.bariere[i].cord_y1==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='g'&&jeu.bariere[i].cord_x2-1==x&&jeu.bariere[i].cord_y2==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x1==x&&jeu.bariere[i].cord_y1==y)
                {
                    pos=1;
                }
                if(jeu.bariere[i].sens=='d'&&jeu.bariere[i].cord_x2==x&&jeu.bariere[i].cord_y2==y)
                {
                    pos=1;
                }
            }
        }
    }
    return pos;//retourne 0 si possible et 1 sinon
}
int joueurPresent(struct jeu jeu, struct joueur j, int x, int y)//methode pour verifier que un pion ne gene pas le deplacement
{
    int pos;
    struct joueur *nextj=jeu.ordrejeu.j;//on verfie chaque joueur
    for(int i=0;i<jeu.nbjoueur;i++)
    {
        if(strcmp(nextj->nom,j.nom)!=0)//si c'est pas celui qui se deplace
        {
            if(nextj->crosshaire.cor_x==x&&nextj->crosshaire.cor_y==y)//on verifi que la case est libre
            {
                pos=1;
            }
        }
        nextj=nextj->next;//on passe au joueur suivant
    }
    return pos;
}
void placerBariere(struct jeu *jeu,struct joueur *j)//methode de placement de bariere
{
    int placer=0;
    int nb=-1;
    int i=0;
    while(nb==-1)//on recupere une bariere pas encore placer
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
    do//jusqu'a ce que la bariere soit placer
    {
        affichage(*jeu,*j);
        char c;
        fflush(stdin);
        c = toucheAppuiez();
        switch (c)
        {
            case 'q': //decalage vers la gauche
                if(jeu->bariere[nb].cord_x1-1<8&&jeu->bariere[nb].cord_x1-1>=0)//si on sort pas du plateau de jeu
                    deplacementBariere(jeu,nb,-1,0,0);//on appelle la methode de deplacement de bariere
            case 'd'://decalage vers la droite
                if(jeu->bariere[nb].cord_x1+1<8&&jeu->bariere[nb].cord_x1+1>=0)//si on sort pas du plateau de jeu
                    deplacementBariere(jeu,nb,1,0,0);//on appelle la methode de deplacement de bariere
                break;
            case 'z'://decalage vers le haut
                if(jeu->bariere[nb].cord_y1-1<8&&jeu->bariere[nb].cord_y1-1>=0)//si on sort pas du plateau de jeu
                    deplacementBariere(jeu,nb,0,-1,0);//on appelle la methode de deplacement de bariere
                break;
            case 's'://decalage vers le bas
                if(jeu->bariere[nb].cord_y1+1<8&&jeu->bariere[nb].cord_y1+1>=0)//si on sort pas du plateau de jeu
                    deplacementBariere(jeu,nb,0,1,0);//on appelle la methode de deplacement de bariere
                break;
            case 'e'://rotation vers la droite
                deplacementBariere(jeu,nb,0,0,1);//on appelle la methode de deplacement de bariere
                break;
            case 'a'://rotation vers la gauche
                deplacementBariere(jeu,nb,0,0,-1);//on appelle la methode de deplacement de bariere
                break;
            case ' '://valider
                if(jeu->bariere[nb].active==2)//on appelle la methode de deplacement de bariere
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
            for(int i=0;i<20;i++)//on verfi pour toute les bariere
            {

                if(jeu->bariere[i].id!=nb+1&&jeu->bariere[i].active==1)//si elle est active
                {
                    if(jeu->bariere[i].sens==jeu->bariere[nb].sens)//si elle sont dans le meme sens on regarde si elle ne sont pas sur les meme case
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
                    if(jeu->bariere[i].sens=='h'&&jeu->bariere[nb].sens=='b')//si elle sont de sens opposer on verfie qu'elle sont pas l'une au dessus de l'autre
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
                    if(jeu->bariere[i].sens=='b'&&jeu->bariere[nb].sens=='h')//si elle sont de sens opposer on verfie qu'elle sont pas l'une au dessus de l'autre
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
                    if(jeu->bariere[i].sens=='g'&&jeu->bariere[nb].sens=='d')//si elle sont de sens opposer on verfie qu'elle sont pas l'une a cote de l'autre
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
                    if(jeu->bariere[i].sens=='d'&&jeu->bariere[nb].sens=='g')//si elle sont de sens opposer on verfie qu'elle sont pas l'une a cote de l'autre
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
            struct joueur *nextj=jeu->ordrejeu.j;//on regarde les possition de chaque joueur pour empecher qu'une bariere soit posser a coter
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
                nextj=nextj->next;//on passe au joueur suivant
            }
        }
    }while(placer==0);
}
void deplacementBariere(struct jeu *j,int nb,int x,int y,int direction)//methode pour deplacer la bariere
{
    j->bariere[nb].cord_x1+=x;//on modifi les coorder x
    j->bariere[nb].cord_y1+=y;//on modifi les coorder y
    j->bariere[nb].active=2;

    if(j->bariere[nb].sens=='h')//on modifi les coorder x et y de la deuxieme case
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='b')//on modifi les coorder x et y de la deuxieme case
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='g')//on modifi les coorder x et y de la deuxieme case
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    else if(j->bariere[nb].sens=='d')//on modifi les coorder x et y de la deuxieme case
    {
        j->bariere[nb].cord_x2+=x;
        j->bariere[nb].cord_y2+=y;
    }
    if(direction==1)
    {
        if(j->bariere[nb].sens=='h')//quand on change la direction
        {
            j->bariere[nb].sens='d';
            j->bariere[nb].cord_x2-=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='b')//quand on change la direction
        {
            j->bariere[nb].sens='g';
            j->bariere[nb].cord_x2-=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='g')//quand on change la direction
        {
            j->bariere[nb].sens='h';
            j->bariere[nb].cord_x2+=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2-=1;
        }
        else if(j->bariere[nb].sens=='d')//quand on change la direction
        {
            j->bariere[nb].sens='b';
            j->bariere[nb].cord_x2+=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2-=1;
        }
    }
    if(direction==-1)
    {
        if(j->bariere[nb].sens=='h')//quand on change la direction
        {
            j->bariere[nb].sens='g';
            j->bariere[nb].cord_x2-=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='b')//quand on change la direction
        {
            j->bariere[nb].sens='d';
            j->bariere[nb].cord_x2-=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2+=1;
        }
        else if(j->bariere[nb].sens=='g')//quand on change la direction
        {
            j->bariere[nb].sens='b';
            j->bariere[nb].cord_x2+=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2-=1;
        }
        else if(j->bariere[nb].sens=='d')//quand on change la direction
        {
            j->bariere[nb].sens='h';
            j->bariere[nb].cord_x2+=1;//on modifi les coorder x et y de la deuxieme case
            j->bariere[nb].cord_y2-=1;
        }
    }
}
int testFinJeu(struct joueur *j)//methode de verification de fin de jeu
{
    if(j->startside=='B')//si le joueur est partie en bas
        if(j->crosshaire.cor_y==0)//si est arriver a l'opposer
            return 1;
    else if(j->startside=='D')//si le joueur est partie a droit
        if(j->crosshaire.cor_x==0)//si est arriver a l'opposer
            return 1;
    else if(j->startside=='G')//si le joueur est partie a gauche
        if(j->crosshaire.cor_x==8)//si est arriver a l'opposer
            return 1;
    else if(j->startside=='H')//si le joueur est partie en haut
        if(j->crosshaire.cor_y==8)//si est arriver a l'opposer
            return 1;
    return 0;

}
int enregistrement(struct jeu jeu)//methode pour enregister une partie
{
    FILE *f=NULL;
    f=fopen("oldGame.txt","w");//ouverture du fichier
    if(f==NULL)//verif de l'ouverture
    {
        printf("Erreur ouverture fichier");
        return -1;
    }
    else
    {
        fprintf(f,"%d\n",jeu.nbjoueur);//on enregistre le nb de joueur
        struct joueur *nextj=jeu.ordrejeu.j;
        for(int i=0;i<jeu.nbjoueur;i++)//on enregistre les info de chaque joueur
        {
            fprintf(f,"%s,%d,%c,%d,%d,%d,%d\n",nextj->nom,nextj->score,nextj->crosshaire.type,nextj->crosshaire.cor_x,nextj->crosshaire.cor_y,nextj->nb_bariere,nextj->chrono);
            nextj=nextj->next;
        }
        for(int i=0;i<20;i++)//on enregistre les info de chaque bariere
        {
            fprintf(f,"%d,%d,%d,%d,%d,%c,%d\n",jeu.bariere[i].id,jeu.bariere[i].cord_x1,jeu.bariere[i].cord_y1,jeu.bariere[i].cord_x2,jeu.bariere[i].cord_y2,jeu.bariere[i].sens,jeu.bariere[i].active);
        }
        fprintf(f,"%d\n",jeu.etat);//on enregistre les info de chaque case  bonus
        for(int i=0;i<7;i++)
        {
            fprintf(f,"%d,%d,%d,%d\n",jeu.terrain.casebonus[i].active,jeu.terrain.casebonus[i].x,jeu.terrain.casebonus[i].y,jeu.terrain.casebonus[i].valeur);
        }
    }
    fclose(f);

}
void affichageJoueur(struct jeu jeu)//methode d'affichage des joueur
{
    struct joueur *nextj=jeu.ordrejeu.j;
    for(int i=0;i<jeu.nbjoueur;i++)//pour chaque joueur
    {
        if(nextj->crosshaire.cor_y!=-1)
        {
            gotoligcol(nextj->crosshaire.cor_y*2+2,nextj->crosshaire.cor_x*4+6);//on se place au coordoner pour affichier le pion
            printf("%c",nextj->crosshaire.type);
        }
        nextj=nextj->next;
        gotoligcol(20,0);
    }

}
void afficherBariere(struct jeu jeu)//methode d'affichage des bariere
{
    int x;
    int y;
    for(int i=0;i<20;i++)//pour chaque bariere
    {
        if(jeu.bariere[i].active!=0)//si elle est active
        {
            if(jeu.bariere[i].active==1)//en blanc si elle est placer
            {
                Color(15,0);
            }
            if(jeu.bariere[i].active==2)//en vert si on peut la placer
            {
                Color(2,0);
            }
            if(jeu.bariere[i].active==3)//en rouge si elle est pas placable
            {
                Color(4,0);
            }

            if(jeu.bariere[i].sens=='h')//on affiche la bariere
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+1,jeu.bariere[i].cord_x1*4+5);
                printf("%c%c%c%c%c%c%c",0xcd,0xcd,0xcd,0xce,0xcd,0xcd,0xcd);
            }
            if(jeu.bariere[i].sens=='b')//on affiche la bariere
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+3,jeu.bariere[i].cord_x1*4+5);
                printf("%c%c%c%c%c%c%c",0xcd,0xcd,0xcd,0xce,0xcd,0xcd,0xcd);
            }
            if(jeu.bariere[i].sens=='d')//on affiche la bariere
            {
                gotoligcol(jeu.bariere[i].cord_y1*2+2,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xba);
                gotoligcol(jeu.bariere[i].cord_y1*2+3,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xce);
                gotoligcol(jeu.bariere[i].cord_y1*2+4,jeu.bariere[i].cord_x1*4+8);
                printf("%c",0xba);
            }
            if(jeu.bariere[i].sens=='g')//on affiche la bariere
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
void affichage(struct jeu jeu,struct joueur j)//methode d'affichage du plateau de jeu
{
    system("cls");//on efface la console
    affichageTerrain(jeu.terrain);//on affiche le terrain
    afficherCase(jeu.terrain);//on affiche les case bonus
    afficherBariere(jeu);//on affiche les bariere
    affichageJoueur(jeu);//on affiche les joueur
    gotoligcol(0,50);
    printf("NOMBRE DE JOUEURS : %d",jeu.nbjoueur);//on affiche les autre info
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

int toucheAppuiez()//methode pour recupere les touche appuiez
{
    int cara;
    while(1)
    {
        if(GetAsyncKeyState(VK_UP)&0x27)//on appuie sur la fleche du haut
        {
            cara='z';
            break;
        }
        if(GetAsyncKeyState(VK_LEFT)&0x25)//on appuie sur la fleche de gauche
        {
            cara='q';
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT)&0x27)//on appuie sur la fleche de droite
        {
            cara='d';
            break;
        }
        if(GetAsyncKeyState(VK_DOWN)&0x25)//on appuie sur la fleche du bas
        {
            cara='s';
            break;
        }
        if(GetAsyncKeyState(VK_SPACE)&0x21)//on appuie sur espace
        {
            cara=' ';
            break;
        }
        if(GetAsyncKeyState(VK_RETURN)&0x0D)//on appuie sur entrez
        {
            cara='r';
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE)&0x1B)//on appuie sur echape
        {
            cara='v';
            break;
        }
        if(GetAsyncKeyState(VK_CONTROL)&0x11)//on appuie sur controle
        {
            cara='a';
            break;
        }
        if(GetAsyncKeyState(VK_MENU)&0x11)//on appuie sur alt
        {
            cara='e';
            break;
        }
    }
    return cara;
}
