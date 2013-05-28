#include "stairright.h"

using namespace cell;

StairRight::StairRight(short x, short y):
    Block(2,3)
{
    degreeOfRotation=two;
    ptr=new short* [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new short [startB];
        for (short j=0; j<startB; ++j)
        {
            if (i==0)
            {
                if(j>0)
                    ptr[i][j]=blue;
                else
                    ptr[i][j]=empty;
            }
            if (i==1)
            {
                if(j<2)
                    ptr[i][j]=blue;
                else
                    ptr[i][j]=empty;
            }
        }
    }
    coords.x=x;
    coords.y=y;

}
StairRight::~StairRight()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}

