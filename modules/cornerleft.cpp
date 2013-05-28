#include "cornerleft.h"

using namespace cell;

CornerLeft::CornerLeft(short x, short y):
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
                ptr[i][j]=magenta;
            if (i==1)
            {
                if(j==0)
                    ptr[i][j]=magenta;
                else
                    ptr[i][j]=empty;
            }
        }
    }
    coords.x=x;
    coords.y=y;

}
CornerLeft::~CornerLeft()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}
