#include "bariere.h"
#include <stdio.h>
struct bariere creeBariere(void)
{
    t_bariere c={0};
    c.active=0;
    c.cord_x=0;
    c.cord_y=0;
    c.id=0;
    c.sens='h';
    return c;
}
void afficherBariere(struct bariere b)
{
    printf("Barriere n°%d, active:%d, au coordonner x=%d, y=%d, de sens: %c\n",b.id,b.active,b.cord_x,b.cord_y,b.sens);
}