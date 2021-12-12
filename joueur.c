#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
struct joueur creeJoueur(void)//methode de creation de joueur
{
	t_joueur j = {0};
    j.nb_bariere=0;
    printf("Entrez votre pseudo(50 caractere max):");//on recupere le pseudo du joueur
    scanf_s("%s",j.nom);
    j.score=getScore(j.nom);//on recupere son score garce a la methode getScore
    j.crosshaire=creeCrossaire();//on cree son pion
    j.chrono=0;
    return j;
}
int getScore(char *pseudo)//methode pour recuper le score d'un joueur dans un fichier
{
    FILE *f=NULL;
    char ligne[70];
    char pseudoLue[50];
    char *token;
    int score=-1;
    f=fopen("joueur.txt","r");//on ouvre le fichier
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(!feof(f))//on le lit jusqu'a la fin
        {
            fscanf(f,"%s",&ligne);
            token = strtok(ligne, ",");
            strcpy(pseudoLue,token);
            if(strcmp(pseudoLue,pseudo)==0)//si le pseudo est le meme
            {
                token = strtok(NULL, ",");
                score = atoi(token);//on recupere le score
            }
        }
    }
    fclose(f);
    if(score==-1)//si le pseudo n'est pas trouver
    {
        FILE *f=NULL;
        f=fopen("joueur.txt","a");
        if(f==NULL)
        {
            printf("Erreur ouverture fichier");
        }
        else
        {
            fprintf(f,"\n%s,0",pseudo);//on l'ajoute a la fin du fichier
            score=0;
        }
        fclose(f);
    }
    return score;//on retourne le score
}
void setScore(char *pseudo,int score)//methode pour ajouter le score d'un joueur dans un fichier
{
    FILE *f=NULL;
    int nb=0;
    int lignePseudo;
    char ligne[70];
    char pseudoLue[50];
    char *token;
    char buffer[100][100]={0};
    f=fopen("joueur.txt","r");//on ouvre le fichier
    if(f==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(!feof(f))//on le lit jusqu'a la fin
        {
            fscanf(f,"%s",buffer[nb]);//on enregistre la ligne
            strcpy(ligne,buffer[nb]);
            token = strtok(ligne, ",");
            if(token!=NULL)
            {
                strcpy(pseudoLue,token);
                if(strcmp(pseudoLue,pseudo)==0)//on recupere la ligne du pseudo dans le document
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
    f2=fopen("joueur.txt","w");//on ouvre le fichier en write
    if(f2==NULL)
    {
        printf("Erreur ouverture fichier");
    }
    else
    {
        while(nb2<nb)//on reecrit le fichier avec les pseudo et score enregister
        {
            if(nb!=0)
            {
               fprintf(f2,"\n");
            }
            if(nb2==lignePseudo)
            {
                fprintf(f2,"%s,%d",pseudo,score);//on ecrit le bon score pour le bon pseudo
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
