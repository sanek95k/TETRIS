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


bool Line::StopDown(Field *arg)
{
    short **p=arg->GetP();
    for (short i=coords.y; i<coords.y+b; ++i)
        if (p[coords.x+a][i]>empty)
            return true;
    return false;
}

bool Line::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y-1]>border)
            return true;
    return false;
}

bool Line::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y+b]>border)
            return true;
    return false;
}

void Line::Rotate()
{
    short temp=a;
    a=b;
    b=temp;
}
