#include "pbm.h"

char* jeu(int x, int y, int x1, int y1, int xvoiture, int yvoiture)
{

    if (((xvoiture == x) && (y>5) && (y<9)) || ((y1>5) && (y1<9) && (xvoiture == x1)))
    {
        return "vrai";
    }
    else
    {
        return "faux";
    }

}

