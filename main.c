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


    int x,y,i;
    Pbm image;
    int tab[24][31]= {0};
    FILE* file = NULL;
    for (y=24; y<-10; y--)
    {
        printf("%d",y);
        rout(x, y, i,  tab, file, &image);
        voiture(x, y,  tab, file, &image);
        obs(x, y,  tab, file, &image);
        //  clav(x, y,  tab, file, &image);



        sleep(1);
        fflush(stdout);
    }
    AfficherTab(tab);
    return 0;


}

