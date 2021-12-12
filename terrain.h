#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
typedef struct CaseBonus
{
    int x;
    int y;
    int valeur;
    int active;
}t_CaseBonus;
typedef struct terrain
{
    char grille[20][40];
    t_CaseBonus casebonus[7];
}t_terrain;
struct terrain creeTerrain();
void affichageTerrain(struct terrain terrain);
int checkMouve(t_terrain t,int x,int y);
int checkCase(int x,int y,struct terrain *t);
void afficherCase(struct terrain terrain);
#endif // TERRAIN_H_INCLUDED
