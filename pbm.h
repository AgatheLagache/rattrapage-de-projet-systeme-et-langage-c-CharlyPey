#ifndef PBM_H_INCLUDED
#define PBM_H_INCLUDED

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
void mettreImageDansTab(FILE *file, Pbm* image, int tabImage[28][31], int x, int y);
void prendreDimensionsImage(FILE *file, Pbm* p);
void AfficherTab(int tab[24][31]);
#endif // PBM_H_INCLUDED
