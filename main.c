#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include <time.h>
#include <windows.h>

int main()
{
    srand(time(NULL));
    //menu();
    //printf("QUORIDOR le projet trop eclate!\n");
    int chargerJeu=0;
    startGame(chargerJeu);
    printf(",%c,",0x00);
    while(1)
    {
        int cara=toucheAppuiez();
        printf("%c\n",cara);
    }
    return 0;
}
int toucheAppuiez()
{
    int cara;
    while(1)
    {
        if(GetAsyncKeyState(VK_UP)&0x27)
        {
            cara='z';
            break;
        }
        if(GetAsyncKeyState(VK_LEFT)&0x25)
        {
            cara='q';
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT)&0x27)
        {
            cara='d';
            break;
        }
        if(GetAsyncKeyState(VK_DOWN)&0x25)
        {
            cara='s';
            break;
        }
        if(GetAsyncKeyState(VK_SPACE)&0x20)
        {
            cara=' ';
            break;
        }
        if(GetAsyncKeyState(VK_RETURN)&0x0D)
        {
            cara='r';
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE)&0x1B)
        {
            cara='v';
            break;
        }
    }
    return cara;
}
