#include "terrain.h"

void creaTerrain(char terrain[20][40])
{
    terrain[2][0]='1';
    terrain[4][0]='2';
    terrain[6][0]='3';
    terrain[8][0]='4';
    terrain[10][0]='5';
    terrain[12][0]='6';
    terrain[14][0]='7';
    terrain[16][0]='8';
    terrain[18][0]='9';
    terrain[0][6]='A';
    terrain[0][10]='B';
    terrain[0][14]='C';
    terrain[0][18]='D';
    terrain[0][22]='E';
    terrain[0][26]='F';
    terrain[0][30]='G';
    terrain[0][34]='H';
    terrain[0][38]='I';
    for(int i=0;i<19;i++)
    {
        if(i%2==1)
        {
            terrain[i][0]=0xc4;
            terrain[i][1]=0xc4;
            terrain[i][2]=0xc4;
            terrain[i][3]=0xc4;
        }
    }
    for(int j=4;j<40;j++)
    {
        if(j%4==0)
        {
            terrain[1][j]=0xc5;
            terrain[0][j]=0xb3;
        }
        else
        {
            terrain[1][j]=0xc4;
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
                    terrain[i][j]=0xC5;
                }
                else{
                    terrain[i][j]=0xC4;
                }

            }
        }
        else
        {
            for(int j=4;j<40;j++)
            {
                if(j%4==0)
                {
                    terrain[i][j]=0xB3;
                }
                else{
                    terrain[i][j]=0x00;
                }
            }
        }
    }
}
void affichage( t_terrain terrain)
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
void gereTerrain()
{
    t_terrain terrain={0x00};
    for(int i=0;i<20;i++)
    {
        terrain.list->id=i;
        terrain.list->cord_x=0;
        terrain.list->cord_y=0;
        terrain.list->active=0;
    }
    creaTerrain(terrain.grille);
    affichage(terrain);
    printf("\n");
    changecarac(terrain.grille,'@',0,0);
    affichage(terrain);
    changecarac(terrain.grille,'@',1,0);
    affichage(terrain);
}
