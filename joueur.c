#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
struct joueur creeJoueur(void)
{
	t_joueur j = {0};
    j.nb_bariere=0;
    printf("Entrez votre pseudo(50 caractere max):");
    scanf_s("%s",j.nom);
    j.score=getScore(j.nom);
    j.crosshaire=creeCrossaire();
    return j;
}
void affichierJoueur(struct joueur j)
{
    printf("Pseudo: %s, ",j.nom);
    printf("Score: %d, ",j.score);
    printf("bariere restantante: %d, ",j.nb_bariere);
    printf("crossaire: %c en coordoner x=%d et y=%d.\n",j.crosshaire.type,j.crosshaire.cor_x,j.crosshaire.cor_y);

}

int getScore(char *pseudo)
{
    FILE *f=NULL;
    char ligne[70];
    char pseudoLue[50];
    char *token;
    int score=-1;
    f=fopen("joueur.txt","r");
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%s",&ligne);
            token = strtok(ligne, ",");
            strcpy(pseudoLue,token);
            if(strcmp(pseudoLue,pseudo)==0)
            {
                token = strtok(NULL, ",");
                score = atoi(token);
            }
        }
    }
    fclose(f);
    if(score==-1)
    {
        FILE *f=NULL;
        f=fopen("joueur.txt","a");
        if(f==NULL)
        {
            printf("Erreur ouverture fichier");
        }
        else
        {
            fprintf(f,"%s,0\n",pseudo);
            score=0;
        }
        fclose(f);
    }
    return score;
}
void setScore(char *pseudo,int score)
{
    FILE *f=NULL;
    int nb=1;
    int lignePseudo;
    char ligne[70];
    char pseudoLue[50];
    char *token;
    f=fopen("joueur.txt","r+");
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%s",&ligne);
            token = strtok(ligne, ",");
            strcpy(pseudoLue,token);
            if(strcmp(pseudoLue,pseudo)==0)
            {
                token = strtok(NULL, ",");
                score=atoi(token);
            }
        }
    }
}
