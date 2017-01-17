#include "pbm.h"

void mettreImageDansTab(FILE *file, Pbm* image, int tabImage[24][31], int x, int y)
{
    char lectureLigne[29] = "";
    int valeurCase;
    //fgets(lectureLigne, 29, file);
    int z,k;
    while (fgets(lectureLigne, 29, file) != NULL)
    {

        for(k = 0; k < image->hauteur; k++)
        {
                 for(z = 0; z < image->largeur; z++)
            {

                fscanf(file, "%d", &valeurCase);
                tabImage[k+y][z+x] = valeurCase;

            }
        }
    }
}

void prendreDimensionsImage(FILE *file, Pbm* p)
{
    char lectureLigne[50] = "";
    int i;

    for(i = 0; i < 2; i++)
    {
        fgets(lectureLigne, 50, file);
    }
    fscanf(file, "%d %d", &p->largeur, &p->hauteur);
}
void AfficherTab(int tab[24][31])
{
    int i;
    int j;
    char carreBlanc[]= {226,150,136,0};
    for (i=0; i<24; i++)
    {
        for (j=0; j<31; j++)
        {
            if (tab[i][j] == 1)
            {
                printf("%s", carreBlanc);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
