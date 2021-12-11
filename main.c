#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>
#include <windows.h>
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void regleJeu()
{
    int quitter = 0;
    char c;
    c=toucheAppuiez();
    while (quitter == 0)
    {
        printf("   ______________________________________________________________________         \n");
        printf("  |                                                                      |        \n");
        printf("  |                      +-+-+-+-+-+-+ +-+-+ +-+-+-+                     |        \n");
        printf("  |                      |R|E|G|L|E|S| |D|U| |J|E|U|                     |        \n");
        printf("  |                      +-+-+-+-+-+-+ +-+-+ +-+-+-+                     |        \n");
        printf("  |______________________________________________________________________|        \n");
        printf("  |                                                                      |        \n");
        printf("  |                          ( - BUT DU JEU - )                          |        \n");
        printf("  |                                                                      |        \n");
        printf("  |             Deux modes de jeu possibles : 2 ou 4 joueurs.            |        \n");
        printf("  |  Etre le premier a atteindre la ligne opposee a sa ligne de depart.  |        \n");
        printf("  |     Un tirage au sors de facon aleatoire determine qui commence.     |        \n");
        printf("  |    Les barrieres sont reparties equitablement entre les joueurs.     |        \n");
        printf("  |        Pour 2 joueurs : chaque joueur dispose de 10 barrieres        |        \n");
        printf("  |        Pour 4 joueurs : chaque joueur dispose de 5 barrieres         |        \n");
        printf("  |                                                                      |        \n");
        printf("  |                                                                      |        \n");
        printf("  |                         ( - DEPLACEMENTS - )                         |        \n");
        printf("  |                                                                      |        \n");
        printf("  |                A tour de role chaque joueur choisi de :              |        \n");
        printf("  |  1) Deplacer son pion d'une case (Vertical/Horizontal/Avant/Arriere) |        \n");
        printf("  |  2) Poser une de ses barrieres. Une barriere doit etre posee entre 2 |        \n");
        printf("  |   blocs de 2 cases. Lorsqu'il n'a plus de barrieres, un joueur est   |        \n");
        printf("  |                     oblige de deplacer son pion.                     |        \n");
        printf("  |  => Objectif : creer son propre chemin ou ralentir son adversaire    |        \n");
        printf("  |                                                                      |        \n");
        printf("  |                        ( - SPECIFICATIONS - )                        |        \n");
        printf("  |                                                                      |        \n");
        printf("  |         /!\\  Interdiction de fermer totalement l'acces  /!\\          |      \n");
        printf("  |  Si 2 pions se retrouvent face a face le joueur a le droit de sauter |        \n");
        printf("  |                      par dessus sont adversaire.                     |        \n");
        printf("  |  Si une barriere se trouve derriere le pion saute, le joueur peut    |        \n");
        printf("  |       choisir de bifurquer a droite ou a gauche du pion saute.       |        \n");
        printf("  |______________________________________________________________________|      \n\n");
        Color(12,0);
        printf("                 APPUYER SUR LA TOUCHE ENTREE POUR QUITTER                        \n");
        scanf("%c", &c);
        Color(15,0);
        if(c==' ')
            {
                quitter=1;
            }
    }
}

/*
void scoreJoueur()
{
    FILE* fichier = NULL;
    int score[3] = {0}; // Tableau des 3 meilleurs scores

    fichier = fopen("joueur.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        printf("Les meilleurs scores sont : %d, %d et %d", score[0], score[1], score[2]);

        fclose(fichier);
    }

    return 0;
}*/

void menu()
{
    int finpartie = 0;
    while(finpartie == 0)
    {
        int choix=1;
        int quitter=0;
        char c;
        while(quitter==0)
        {
            system("cls");
            Color(11,0);
            printf("\n");
            printf("_______/\\\\\\\\\\_________/\\\\\\________/\\\\\\_________/\\\\\\\\\\___________/\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\\\\\\\\\\\\\\\\\\\____________/\\\\\\\\\\\___________/\\\\\\\\\\\\\\\\\\_______________\n");
            printf("______/\\\\\\///\\\\\\______\\/\\\\\\_______\\/\\\\\\_______/\\\\\\///\\\\\\_______/\\\\\\///////\\\\\\_____\\/////\\\\\\///____\\/\\\\\\////////\\\\\\________/\\\\\\///\\\\\\_______/\\\\\\///////\\\\\\_____________\n");
            printf("_____/\\\\\\/__\\///\\\\\\____\\/\\\\\\_______\\/\\\\\\_____/\\\\\\/__\\///\\\\\\____\\/\\\\\\_____\\/\\\\\\_________\\/\\\\\\_______\\/\\\\\\______\\//\\\\\\_____/\\\\\\/__\\///\\\\\\____\\/\\\\\\_____\\/\\\\\\_____________\n");
            printf("___ /\\\\\\_______\\//\\\\\\___\\/\\\\\\_______\\/\\\\\\____/\\\\\\______\\//\\\\\\___\\/\\\\\\\\\\\\\\\\\\\\\\/__________\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\____/\\\\\\______\\//\\\\\\___\\/\\\\\\\\\\\\\\\\\\\\\\/______________\n");
            printf("____\\/\\\\\\_______\\/\\\\\\____\\/\\\\\\_______\\/\\\\\\___\\/\\\\\\_______\\/\\\\\\___\\/\\\\\\//////\\\\\\__________\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\___\\/\\\\\\_______\\/\\\\\\___\\/\\\\\\//////\\\\\\______________\n");
            printf("_____\\//\\\\\\______/\\\\\\_____\\/\\\\\\_______\\/\\\\\\___\\//\\\\\\______/\\\\\\____\\/\\\\\\____\\//\\\\\\_________\\/\\\\\\_______\\/\\\\\\_______\\/\\\\\\___\\//\\\\\\______/\\\\\\____\\/\\\\\\____\\//\\\\\\_____________\n");
            printf("_______\\///\\\\\\__/\\\\\\_______\\//\\\\\\______/\\\\\\_____\\///\\\\\\__/\\\\\\______\\/\\\\\\_____\\//\\\\\\________\\/\\\\\\_______\\/\\\\\\_______/\\\\\\_____\\///\\\\\\__/\\\\\\______\\/\\\\\\_____\\//\\\\\\____________\n");
            printf("__________\\///\\\\\\\\\//\\\\\\\\_____\\///\\\\\\\\\\\\\\\\\\/________\\///\\\\\\\\\\/_______\\/\\\\\\______\\//\\\\\\____/\\\\\\\\\\\\\\\\\\\\\\___\\/\\\\\\\\\\\\\\\\\\\\\\\\/________\\///\\\\\\\\\\/_______\\/\\\\\\______\\//\\\\\\___________\n");
            printf("_____________\\/////_\\///________\\/////////____________\\/////_________\\///________\\///____\\///////////____\\////////////____________\\/////_________\\///________\\///____________\n");
            gotoligcol(20,0);
            Color(15,0);
            printf("                                                                    _________________________________________         \n");
            printf("                                                                   /                                         \\       \n");
            printf("                                                                  /       1. LANCER UNE NOUVELLE PARTIE       \\      \n");
            printf("                                                                 /     2. REPRENDRE UNE PARTIE SAUVEGARDEE     \\     \n");
            printf("                                                                (         3. AFFICHER LES REGLES DU JEU         )     \n");
            printf("                                                                 \\     4. AFFICHER LES SCORES DES JOUEURS      /     \n");
            printf("                                                                  \\           5. QUITTER LE JEU               /      \n");
            printf("                                                                   \\_________________________________________/       \n");
            Color(10,0);
            gotoligcol(21+choix,68);
            printf("->");
            gotoligcol(21+choix,107);
            printf("<-");
            gotoligcol(20,0);
            Color(15,0);
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
        system("cls");
        switch(choix)
        {
            case 1 :
                startGame(0);
                break;

            case 2 :
                startGame(1);
                break;

            case 3 :
                regleJeu();
                break;

            case 4 :
                //scoreJoueur();
                break;

            case 5 :
                quitter = 1;
                finpartie = 1;
                system("cls");
            break;
        }
    }

}
