#include "pbm.h"

char* jeu(int x, int y, int x1, int y1, int xvoiture, int yvoiture)
{

    if ((((xvoiture == x) && (y<9)) || (y1<9) && (xvoiture == x1)) || (xvoiture<8) || (xvoiture>20))
    {
        return "vrai";
    }
    else
    {
        return "faux";
    }

}

