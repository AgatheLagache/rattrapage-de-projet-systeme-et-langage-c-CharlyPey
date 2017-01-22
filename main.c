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
//#include "clavier.c"


int main()
{


    int x,y,i,x1,y1,xvoiture,yvoiture;
    Pbm image;
    int tab[28][31]= {0};
    FILE* file = NULL;
    y=28;
    y1=40;
    char* colision = "faux";
    while(strcmp(colision,"vrai") !=0)
    {



        srand(time(NULL));
        rout(x, y,  tab, file, &image);
        voiture(&xvoiture, &yvoiture,  tab, file, &image);
        obs(&x, y, tab, file, &image);
        obs(&x1, y1, tab, file, &image);
        //  clav(x, y,  tab, file, &image);


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
        colision = jeu(x,y,x1,y1,xvoiture,yvoiture);

    }

    return 0;


}

