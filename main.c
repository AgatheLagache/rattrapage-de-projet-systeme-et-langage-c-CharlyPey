#include "pbm.h"
#include "pbm.c"
#include "voiture.c"
#include "voiture.h"
#include "obstaclee.c"
#include "routee.c"
#include <time.h>
#include "Jeu.c"
#include "obstaclee.h"
#include "Jeu.h"
#include "routee.h"
#include "touche.c"


int main()
{

    system("setterm -cursor off");
    int x,y,i,x1,y1,xvoiture,yvoiture,descripteurTube[2],positionActuel;
    positionActuel = 14;
    pid_t pidFils;
    pipe(descripteurTube);
    pidFils = fork();
    Pbm image;
    int tab[28][31]= {0};
    FILE* file = NULL;
    y=28;
    y1=40;
    char* colision = "faux";
    while(strcmp(colision,"vrai") !=0)
    {



                 if (pidFils==0)
        {
            touche(descripteurTube);
        }
        else
        {
            rout(x, y,  tab, file, &image);
            positionActuel = changementPositions(descripteurTube, positionActuel);
            voiture(&yvoiture,  tab, file, &image, &positionActuel);
                    srand(time(NULL));


        obs(&x1, y1, tab, file, &image);
        obs(&x, y, tab, file, &image);
         colision = jeu(x,y,x1,y1,positionActuel,yvoiture);
        AfficherTab(tab);
        usleep(100000);
        fflush(stdout);
        if (y==0)
        {
            y=28;
        }
        if (y1==0)
        {
            y1=28;
        }
        y--;
        y1--;





        }



    }

    system("setterm -cursor on");
    printf("rekt\n");
    return 0;


}

