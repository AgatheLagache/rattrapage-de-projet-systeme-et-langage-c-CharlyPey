#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
typedef struct Pbm Pbm;
struct Pbm
{
    int largeur;
    int hauteur;
    char nomImage[256];
};
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

int main()
{

    int x,y;
    x=0;
    Pbm image;
    int tab[24][31]= {0};
    FILE* file = NULL;
    strcpy(image.nomImage, "Ditch.pbm");
   //
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
        for(x=11;x<18;x=x+6)
        {
        for(y=0;y<24;y=y+4)
        {
        file = fopen(image.nomImage, "r");
            prendreDimensionsImage(file, &image);
            mettreImageDansTab(file, &image, tab, x, y);
            fclose(file);

}
}




        //mettreImageDansTab(file, &image, tab, x, y);
        AfficherTab(tab);

return 0;


}

