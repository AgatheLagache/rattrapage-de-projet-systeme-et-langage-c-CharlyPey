#include "pbm.h"

void voiture(int x, int y, int tab[24][31], FILE *file, Pbm* image)
{
         x=13;
         y=0;
        strcpy(image->nomImage, "MyVehicle.pbm");
         file = fopen(image->nomImage, "r");
         prendreDimensionsImage(file, &image);
         mettreImageDansTab(file, &image, tab, x, y);
         fclose(file);


}
