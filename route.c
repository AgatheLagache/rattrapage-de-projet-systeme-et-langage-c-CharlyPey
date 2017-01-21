#include "pbm.h"

void route(int x, int y, int i, int tab[24][31], FILE *file, Pbm *image)
{
    i=0;
    if(y%2==0)
    {
        i=1;
    }
    x=0;


    for(y=i; y<24+i; y=y+4)
    {

        for (x=0; x<29; x=x+23)
        {
            file = fopen("Ditch.pbm", "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);


        }
        }



        for(y=i; y<24+i; y=y+4)
    {

        for(x=11; x<18; x=x+6)
        {
            file = fopen("Macadam.pbm", "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);

        }
        }

}
