#include "pbm.h"

void voiture(int* yvoiture, int tab[28][31], FILE *file, Pbm *image, int* positionActuel)
{
        int x,y;
        *yvoiture=5;
        x = *positionActuel;
        y = *yvoiture;
        file = fopen("MyVehicle.pbm", "r");
         prendreDimensionsImage(file, &image);
         mettreImageDansTab(file, &image, tab, x, y);
         fclose(file);


}
