#include "pbm.h"

void rout(int x, int y, int tab[28][31], FILE *file, Pbm *image)
{
    int i=0;
    if(y%2==0)
    {
        i=1;
    }
    x=0;


    for(y=i; y<28+i; y=y+4)
    {

        for (x=0; x<29; x=x+24)
        {
            file = fopen("Ditch.pbm", "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);


        }
    }



    for(y=i; y<28+i; y=y+4)
    {

        for(x=6; x<19; x=x+6)
        {
            file = fopen("Macadam.pbm", "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);

        }
    }

}
