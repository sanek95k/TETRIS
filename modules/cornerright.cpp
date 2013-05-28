#include "cornerright.h"

using namespace cell;

CornerRight::CornerRight(short x, short y):
    Block(2,3)
{
    degreeOfRotation=four;
    ptr=new short* [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new short [startB];
        for (short j=0; j<startB; ++j)
        {
            if (i==0)
                ptr[i][j]=cyan;
            if (i==1)
            {
                if(j==startA)
                    ptr[i][j]=cyan;
                else
                    ptr[i][j]=empty;
            }
        }
    }
    coords.x=x;
    coords.y=y;

}
CornerRight::~CornerRight()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}
