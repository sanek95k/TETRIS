#include "line.h"

using namespace cell;

Line::Line(short x, short y):
    Block(1,4)
{
    degreeOfRotation=two;
    ptr=new short* [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new short [startB];
        for (short j=0; j<startB; ++j)
            ptr[i][j]=yellow;
    }
    coords.x=x;
    coords.y=y;

}

Line::~Line()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}

