#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
typedef struct terrain
{
    char grille[20][40];
}t_terrain;
struct terrain creeTerrain();
void affichage(struct terrain terrain);
void addbariere(struct terrain terrain);
void changecarac(char terrain[20][40],char type,int colone,int ligne);
#endif // TERRAIN_H_INCLUDED
