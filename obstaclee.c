#include "pbm.h"

int rand_a_b(int a, int b){
    a = 1;
    b = 3;
    int c = rand()%((b+1)-a)+a;
    return c;
  }
void obs(int* x1, int y, int tab[28][31], FILE *file, Pbm *image)
{
    int c, a, b, x;
    if (y==27)
    {
    c=rand_a_b(a,b);
       switch (c)
    {
    case 1:
        *x1=8;
        break;
    case 2:
        *x1=14;
        break;
    case 3:
        *x1=20;
        break;
    default:
        printf("Erreur");
        break;


   }

    }

    x = *x1;
    file = fopen("Obstacle.pbm", "r");
    prendreDimensionsImage(file, &image);
    mettreImageDansTab(file, &image, tab, x, y);
    fclose(file);


}
