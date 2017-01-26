#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "conio.h"
#define TAILLE_MESSAGE 256

void touche(int descripteurTube[2])
{
    char toucheD[1];
    char toucheD2, toucheD3;
    toucheD[0]=getch();
    toucheD2=getch();
    toucheD3=getch();
    if (toucheD[0]==27 && toucheD2==91)
    {
        if (toucheD3==68)
        {
            close(descripteurTube[0]);
            write(descripteurTube[1], "1", 256);
        }
        else if (toucheD3==67)
        {
            close(descripteurTube[0]);
            write(descripteurTube[1], "2", 256);
        }
    }
}


int changementPositions (int descripteurTube[2], int positionActuel)
{
    int flags = fcntl(descripteurTube[0], F_GETFL, 0);
    fcntl(descripteurTube[0], F_SETFL, flags | O_NONBLOCK);
    int toucheD;
    unsigned char directionnelle[256];
    close (descripteurTube[1]);
    toucheD = read(descripteurTube[0], directionnelle, 256);
    if (toucheD>=0)
    {
        switch(*directionnelle)
        {
        case '1':
            positionActuel-=6;
            //printf("%d\n", toucheD);
            //printf("%d\n", positionActuel);
            break;
        case '2':
            positionActuel+=6;
            //printf("%d\n", toucheD);
            //printf("%d\n", positionActuel);
            break;
        default:
            break;
        }
    }
    else
    {
        printf("Mamelle\n");
        toucheD = read(descripteurTube[0], directionnelle, 256);
    }
    return positionActuel;
}
