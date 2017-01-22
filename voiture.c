#include "pbm.h"

void voiture(int* xvoiture, int* yvoiture, int tab[28][31], FILE *file, Pbm *image)
{
        int x,y;
        *xvoiture=14;
        *yvoiture=5;
        x = *xvoiture;
        y = *yvoiture;
        file = fopen("MyVehicle.pbm", "r");
         prendreDimensionsImage(file, &image);
         mettreImageDansTab(file, &image, tab, x, y);
         fclose(file);


}
