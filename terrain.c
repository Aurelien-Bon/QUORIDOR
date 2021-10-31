#include "terrain.h"
#include <stdio.h>

struct terrain creeTerrain()
{
    t_terrain grille={0};
    grille.grille[2][0]='1';
    grille.grille[4][0]='2';
    grille.grille[6][0]='3';
    grille.grille[8][0]='4';
    grille.grille[10][0]='5';
    grille.grille[12][0]='6';
    grille.grille[14][0]='7';
    grille.grille[16][0]='8';
    grille.grille[18][0]='9';
    grille.grille[0][6]=0x41;
    grille.grille[0][10]='B';
    grille.grille[0][14]='C';
    grille.grille[0][18]='D';
    grille.grille[0][22]='E';
    grille.grille[0][26]='F';
    grille.grille[0][30]='G';
    grille.grille[0][34]='H';
    grille.grille[0][38]='I';
    for(int i=0;i<19;i++)
    {
        if(i%2==1)
        {
            grille.grille[i][0]=0xC4;
            grille.grille[i][1]=0xC4;
            grille.grille[i][2]=0xC4;
            grille.grille[i][3]=0xC4;
        }
    }
    for(int j=4;j<40;j++)
    {
        if(j%4==0)
        {
            grille.grille[1][j]=0xc5;
            grille.grille[0][j]=0xb3;
        }
        else
        {
            grille.grille[1][j]=0xc4;
        }
    }
    for(int i=2;i<19;i++)
    {
        if(i%2!=0)
        {
            for(int j=4;j<40;j++)
            {
                if(j%4==0)
                {
                    grille.grille[i][j]=0xC5;
                }
                else{
                    grille.grille[i][j]=0xC4;
                }

            }
        }
        else
        {
            for(int j=4;j<40;j++)
            {
                if(j%4==0)
                {
                    grille.grille[i][j]=0xB3;
                }
                else{
                    grille.grille[i][j]=0x00;
                }
            }
        }
    }
    return grille;
}
void affichage( struct terrain terrain)
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        {
            printf("%c",terrain.grille[i][j]);
        }
        printf("\n");
    }
}
void changecarac(char terrain[20][40],char type,int colone,int ligne)
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(terrain[i][j]==type)
                terrain[i][j]=0x00;
        }
    }
    terrain[((int)ligne*2)+2][(colone*4)+6]=type;
}
void addbariere(t_terrain terrain)
{

}

