#include "square.h"

using namespace cell;

Square::Square(short x, short y):
    Block(2,2)
{
    degreeOfRotation=zero;
    ptr=new short* [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new short [startB];
        for (short j=0; j<startB; ++j)
            ptr[i][j]=green;
    }
    coords.x=x;
    coords.y=y;

}
Square::~Square()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}

