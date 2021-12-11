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
    j.chrono=0;
    return j;
}
void affichierJoueur(struct joueur j)
{
    printf("Pseudo: %s, ",j.nom);
    printf("Score: %d, ",j.score);
    printf("Barrieres restantes: %d, ",j.nb_bariere);
    printf("Crossaire: %c en coordonnee x=%d et y=%d.\n",j.crosshaire.type,j.crosshaire.cor_x,j.crosshaire.cor_y);

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
            fprintf(f,"\n%s,0",pseudo);
            score=0;
        }
        fclose(f);
    }
    return score;
}
void setScore(char *pseudo,int score)
{
    FILE *f=NULL;
    int nb=0;
    int lignePseudo;
    char ligne[70];
    char pseudoLue[50];
    char *token;
    char buffer[100][100]={0};
    f=fopen("joueur.txt","r");
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%s",buffer[nb]);
            //printf("%d: %s \n",nb,buffer[nb]);
            strcpy(ligne,buffer[nb]);
            token = strtok(ligne, ",");
            if(token!=NULL)
            {
                strcpy(pseudoLue,token);
                if(strcmp(pseudoLue,pseudo)==0)
                {
                    lignePseudo=nb;
                }
            }
            nb++;
        }
    }
    fclose(f);
    int nb2=0;
    FILE *f2=NULL;
    f2=fopen("joueur.txt","w");
    if(f2==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(nb2<nb)
        {
            if(nb!=0)
            {
               fprintf(f2,"\n");
            }
            if(nb2==lignePseudo)
            {
                fprintf(f2,"%s,%d",pseudo,score);
            }
            else
            {
                fprintf(f2,"%s",buffer[nb2]);
            }
            nb2++;
        }
    }
    fclose(f2);
}
