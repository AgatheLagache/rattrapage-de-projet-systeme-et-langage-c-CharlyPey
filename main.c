
#include "pbm.h"
#include "pbm.c"
#include "voiture.c"
#include "voiture.h"
#include "obstaclee.c"
//#include "clavier.c"


int main()
{


    int x,y;
    x=0;
    Pbm image;
    int tab[24][31]= {0};
    FILE* file = NULL;
    strcpy(image.nomImage, "Ditch.pbm");
    for (x=0; x<29; x=x+23)
    {
        for(y=0; y<24; y=y+4)
        {
            file = fopen(image.nomImage, "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);


        }
    }

    x=0;
    y=0;
    strcpy(image.nomImage, "Macadam.pbm");
    for(x=11; x<18; x=x+6)
    {
        for(y=0; y<24; y=y+4)
        {
            file = fopen(image.nomImage, "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);

        }
    }

 voiture(x, y,  tab, file, &image);
 obs(x, y,  tab, file, &image);
//  clav(x, y,  tab, file, &image);



    AfficherTab(tab);

    return 0;


}

