#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
typedef struct terrain
{
    char grille[20][40];
}t_terrain;
struct terrain creeTerrain();
void affichageTerrain(struct terrain terrain);
int checkMouve(t_terrain t,int x,int y);
#endif // TERRAIN_H_INCLUDED
