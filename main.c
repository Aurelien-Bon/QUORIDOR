#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>
#include <windows.h>
int main()
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
        printf("                                                                    _________________________________________        \n");
        printf("                                                                   /                                         \\       \n");
        printf("                                                                  /       1. Lancer une nouvelle partie       \\      \n");
        printf("                                                                 /     2. Reprendre une partie sauvegardee     \\     \n");
        printf("                                                                (         3. Afficher les regles du jeu         )     \n");
        printf("                                                                 \\     4. Afficher les scores des joueurs      /     \n");
        printf("                                                                  \\           5. Quitter le jeu               /      \n");
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

    /*
    Color(15,0);
    gotoligcol(20,0);
    printf("Veuillez faire votre choix: \n");
    Color(9,0);
    gotoligcol(21,0);
    printf("1. Lancer une nouvelle partie\n");
    Color(10,0);
    gotoligcol(22,0);
    printf("2. Reprendre une partie sauvegardee\n");
    Color(12,0);
    gotoligcol(23,0);
    printf("3. Afficher l'aide\n");
    Color(14,0);
    gotoligcol(24,0);
    printf("4. Afficher les scores des joueurs\n");
    Color(5,0);
    gotoligcol(25,0);
    printf("5. Quitter le jeu\n");
    scanf("%d", &choix);*/

    switch(choix)
        {
            case 1 :
                startGame(0);
                break;

            case 2 :
                startGame(1);
                break;

            case 3 :

            break;

            case 4 :

            break;

            case 5 :
                    quitter = 1;
                    system("cls");
            break;
        }

    srand(time(NULL));
    //menu();
    //printf("QUORIDOR le projet trop eclate!\n");
    //prinft("menu");
    //int chargerJeu=1;
    //startGame(chargerJeu);
    //printf(",%c,",0x00);
    //testTouche();
    //testFichier();
    return 0;
}
void testTouche()
{
    while(1)
    {
        char c=toucheAppuiez();
        printf("%c\n",c);
    }
}
void testFichier()
{
    char *token;
    char rest[50];
    FILE* f=NULL;
    f=fopen("oldGame.txt","r");
    fscanf(f,"%s",rest);
    while(!feof(f))
    {
        fscanf(f,"%s",&rest);
        printf("%s\n",rest);
        token = strtok(rest, ",");
        for(int i=0;i<10;i++)
        {
            printf("%s,", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
}
