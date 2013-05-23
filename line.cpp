#include "line.h"

Line::Line(short x, short y):
    Block(1,4)
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
Line::~Line()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}

void Line::Rotate(Field *arg)
{
    short m=arg->GetM();
    short l=arg->GetL();
    short **p=arg->GetP();
    if (coords.x+a>=l-1||coords.y+a>=m)
        return;
    if (a==startA)
    {
    for (short i=0; i<b; ++i)
        if (p[coords.x+a][coords.y+i]==full)
            return;
    }
    else
    {
    for (short i=0; i<a; ++i)
        if (p[coords.x+i][coords.y+b]==full)
            return;
    }
    short temp=a;
    a=b;
    b=temp;
}

bool Line::StopDown(Field *arg)
{
    short **p=arg->GetP();
    for (short i=coords.y; i<coords.y+b; ++i)
        if (p[coords.x+a][i]==border||p[coords.x+a][i]==full)
            return true;
    return false;
}

bool Line::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y-1]==full)
            return true;
    return false;
}

bool Line::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    for (short i=coords.x; i<coords.x+a; ++i)
        if (p[i][coords.y+b]==full)
            return true;
    return false;
}
