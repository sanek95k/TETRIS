#include "testfigure.h"

using namespace cell;

TestFigure::TestFigure(short x, short y):
    Block(3,7)
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
                if(j==1||(j>startB-4&&j<startB-1))
                    ptr[i][j]=empty;
                else
                    ptr[i][j]=green;
            }
            if (i==1)
            {
                if(j==3||j==startB-1)
                    ptr[i][j]=green;
                else
                    ptr[i][j]=empty;
            }
            if (i==2)
            {
                if(j>2)
                    ptr[i][j]=green;
                else
                    ptr[i][j]=empty;
            }
        }
    }
    coords.x=x;
    coords.y=y;

}
TestFigure::~TestFigure()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}
