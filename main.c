#include "pbm.h"
#include "pbm.c"
#include "voiture.c"
#include "voiture.h"
#include "obstaclee.c"
#include "route.c"
#include <time.h>
//#include "clavier.c"


int main()
{


    int x,y,i,c;
    Pbm image;
    int tab[24][31]= {0};
    FILE* file = NULL;
    for (y=24; y<1; y--)
    {
        printf("%d",y);
        route(x, y, i,  tab, file, &image);
        voiture(x, y,  tab, file, &image);
        obs(x, y, c, tab, file, &image);
        //  clav(x, y,  tab, file, &image);



        sleep(1);
        fflush(stdout);
    }
    AfficherTab(tab);
    return 0;


}

