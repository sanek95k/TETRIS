#include "square.h"

Square::Square(short x, short y):
    Block(2,2)
{
    ptr=new short* [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new short [startB];
        for (short j=0; j<startB; ++j)
            ptr[i][j]=full;
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

bool Square::StopDown(Field *arg)
{
    short **p=arg->GetP();
    for (short i=coords.y; i<coords.y+b; ++i)
        if (p[coords.x+a][i]==border||p[coords.x+a][i]==full)
            return true;
    return false;
}

bool Square::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y-1]==full)
            return true;
    return false;
}

bool Square::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y+b]==full)
            return true;
    return false;
}
