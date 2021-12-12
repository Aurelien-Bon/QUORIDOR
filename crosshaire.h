#ifndef CROSSHAIRE_H_INCLUDED
#define CROSSHAIRE_H_INCLUDED
typedef struct crosshaire
{
    char type;
    int cor_x;//colonne
    int cor_y;//ligne
}t_crosshaire;
char choixType(void);//methode de selection de pion
struct crosshaire creeCrossaire(void);//methode de creation de pion
#endif // JOUEUR_H_INCLUDED

