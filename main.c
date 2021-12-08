#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>
#include <windows.h>
int main()
{
    srand(time(NULL));
    //menu();
    //printf("QUORIDOR le projet trop eclate!\n");
    int chargerJeu=1;
    startGame(chargerJeu);
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
