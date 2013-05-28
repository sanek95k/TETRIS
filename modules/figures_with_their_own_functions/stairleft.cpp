#include "stairleft.h"

using namespace cell;

StairLeft::StairLeft(short x, short y):
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
                if(j<2)
                    ptr[i][j]=red;
                else
                    ptr[i][j]=empty;
            }
            if (i==1)
            {
                if(j>0)
                    ptr[i][j]=red;
                else
                    ptr[i][j]=empty;
            }
        }
    }
    coords.x=x;
    coords.y=y;

}
StairLeft::~StairLeft()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
    ptr=0;
}


bool StairLeft::StopDown(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x+a][coords.y]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x+1][coords.y]>border
           ||p[coords.x+2][coords.y+1]>border
           ||p[coords.x+2][coords.y+2]>border)
           return true;
    }
    else
    {
        if(p[coords.x+3][coords.y]>border
           ||p[coords.x+2][coords.y+1]>border)
        return true;
    }
    return false;
}

bool StairLeft::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x][coords.y-1]>border
           ||p[coords.x+1][coords.y]>border)
           return true;
    }
    else
    {
        if(p[coords.x][coords.y]>border
           ||p[coords.x+1][coords.y-1]>border
           ||p[coords.x+2][coords.y-1]>border)
        return true;
    }
    return false;
}

bool StairLeft::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x][coords.y+2]>border
           ||p[coords.x+1][coords.y+3]>border)
           return true;
    }
    else
    {
        if(p[coords.x][coords.y+2]>border
           ||p[coords.x+1][coords.y+2]>border
           ||p[coords.x+2][coords.y+1]>border)
        return true;
    }
    return false;
}

void StairLeft::Rotate()
{
    short *temP=ptr[0];
    ptr[0]=ptr[1];
    ptr[1]=temP;
    short temp=a;
    a=b;
    b=temp;
}

