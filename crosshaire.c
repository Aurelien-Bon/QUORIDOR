#include "crosshaire.h"
#include <stdlib.h>

char choixType(void)//methode de selection de pion
{
    int nb=rand()%8;//hasard entre 0 et 7
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
struct crosshaire creeCrossaire(void)//methode de creation de pion
{
    t_crosshaire cross={0};
    cross.type=choixType();
    cross.cor_x=-1;
    cross.cor_y=-1;
    return cross;
}
