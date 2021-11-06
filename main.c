#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    //printf("QUORIDOR le projet trop eclate!\n");
    startGame(0);
    return 0;
}