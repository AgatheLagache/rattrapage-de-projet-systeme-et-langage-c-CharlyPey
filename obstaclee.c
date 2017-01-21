#include "pbm.h"
#include "route.c"
int rand_a_b(int a, int b){
    a = 1;
    b = 3;
    srand(time(NULL));
    int c = rand()%((b+1)-a)+a;
  }
void obs(int x, int y, int tab[24][31], FILE *file, Pbm *image)
{




    switch (c)
    {
    case 1:
        x=7;
        y=19;
        break;
    case 2:
        x=13;
        y=19;
        break;
    case 3:
        x=19;
        y=19;
        break;
    default:
        printf("Erreur");
        break;

   }

    strcpy(image->nomImage, "Obstacle.pbm");
    file = fopen(image->nomImage, "r");
    prendreDimensionsImage(file, &image);
    mettreImageDansTab(file, &image, tab, x, y);
    fclose(file);


}
