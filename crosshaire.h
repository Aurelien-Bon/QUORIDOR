#ifndef CROSSHAIRE_H_INCLUDED
#define CROSSHAIRE_H_INCLUDED
typedef struct crosshaire
{
    char type;
    int cor_x;//colonne
    int cor_y;//ligne
}t_crosshaire;
char choixType(void);
struct crosshaire creeCrossaire(void);
int getX(struct crosshaire c);
int getY(struct crosshaire c);
char getType(struct crosshaire c);

#endif // JOUEUR_H_INCLUDED

