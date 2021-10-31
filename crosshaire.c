#include "crosshaire.h"
#include <stdlib.h>

char choixType(void)
{
    int nb=rand()%7;
    switch (nb) {
        case 0:
            return '@';
            break;
        case 1:
            return '*';
            break;
        case 2:
            return '#';
            break;
        case 3:
            return '&';
            break;
        case 4:
            return '%';
            break;
        case 5:
            return '?';
            break;
        case 6:
            return 0xBE;
            break;
        case 7:
            return '$';
            break;
    }
}
struct crosshaire creeCrossaire(void)
{
    t_crosshaire cross={0};
    cross.type=choixType();
    cross.cor_x=0;
    cross.cor_y=0;
    return cross;
}
int getX(struct crosshaire c)
{
    return c.cor_x;
}
int getY(struct crosshaire c)
{
    return c.cor_y;
}
char getType(struct crosshaire c)
{
    return c.type;
}