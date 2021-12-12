#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
typedef struct CaseBonus//Structure des case bonus
{
    int x;
    int y;
    int valeur;
    int active;
}t_CaseBonus;
typedef struct terrain//Structure du terrain
{
    char grille[20][40];
    t_CaseBonus casebonus[7];
}t_terrain;
struct CaseBonus CaseRand()//methode pour cree les case bonnus
struct terrain creeTerrain();//methode pour cree le terrain
void affichageTerrain(struct terrain terrain);//methode pour afficher le terrain
int checkCase(int x,int y,struct terrain *t);//methode pour verifier si le joueur est sur une case bonnus
void afficherCase(struct terrain terrain);//methode pour afficher les case bonnus
#endif // TERRAIN_H_INCLUDED
