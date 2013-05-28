#include "pedestal.h"

using namespace cell;

Pedestal::Pedestal(short x, short y):
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
            {
                if(j==1)
                    ptr[i][j]=white;
                else
                    ptr[i][j]=empty;
            }
            if (i==1)
                ptr[i][j]=white;
        }
    }
    coords.x=x;
    coords.y=y;

}

Pedestal::~Pedestal()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}
