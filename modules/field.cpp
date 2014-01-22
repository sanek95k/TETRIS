#include "field.h"
//s#include "../source/source.h"

using namespace cell;

Field::Field(short x, short y):
    l(x), m(y), p(0)
{
    p=new short* [l];
    for (short i=0; i<l; ++i)
    {
        p[i]=new short [m];
        for (short j=0; j<m; ++j)
            if (i==0||i==l-1||j==0||j==m-1)
                p[i][j]=border;
            else
                p[i][j]=empty;
    }
}

Field::~Field()
{
    for (short i=0; i<l; ++i)
        delete [] p[i];
    delete [] p;
    p=0;
}

short Field::KillLine()
{
    short score=0;
    for (short i1=l-2; i1>0; --i1)
        for (short i2=1; i2<m-1; ++i2)
        {
            if (p[i1][i2]==empty)
                break;
            if (i2==m-2)
            {
                for (short i3=1; i3<m-1; ++i3)
                    p[i1][i3]=empty;
                for (short i4=i1; i4>0; --i4)
                    for (short i5=1; i5<m-1; ++i5)
                        if (i4==1)
                            p[1][i5]=empty;
                        else
                            p[i4][i5]=p[i4-1][i5];
                i1++;
                score++;
            }
        }
    return score;
}

void Field::ClearField()
{
    for (short i=1; i<l-1; ++i)
        for (short j=1; j<m-1; ++j)
            p[i][j]=empty;
}

short** Field::GetP() const
{
    return p;
}
