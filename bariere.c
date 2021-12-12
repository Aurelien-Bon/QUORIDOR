#include "bariere.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct bariere creeBariere(void)//methode de creation des bariere
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
void Color(int couleurDuTexte,int couleurDeFond) //methode chagement de couleur de console donner par l'ecole
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
