#include "bariere.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct bariere creeBariere(void)
{
    t_bariere c={0};
    c.active=0;
    c.cord_x1=0;
    c.cord_y1=0;
    c.cord_x2=0;
    c.cord_y2=0;
    c.id=0;
    c.sens='h';
    return c;
}
void afficherBariereText(struct bariere b)
{
    printf("Barriere n°%d, active:%d, au coordonner x1=%d, y1=%d, et x2=%d, y2=%d de sens: %c\n",b.id,b.active,b.cord_x1,b.cord_y1,b.cord_x2,b.cord_y2,b.sens);
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
