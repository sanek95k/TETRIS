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


bool StairRight::StopDown(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x+a][coords.y]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x+2][coords.y]>border
           ||p[coords.x+2][coords.y+1]>border
           ||p[coords.x+1][coords.y+2]>border)
           return true;
    }
    else
    {
        if(p[coords.x+2][coords.y]>border
           ||p[coords.x+3][coords.y+1]>border)
        return true;
    }
    return false;
}


bool StairRight::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x][coords.y]>border
           ||p[coords.x+1][coords.y-1]>border)
           return true;
    }
    else
    {
        if(p[coords.x][coords.y-1]>border
           ||p[coords.x+1][coords.y-1]>border
           ||p[coords.x+2][coords.y]>border)
        return true;
    }
    return false;
}

bool StairRight::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    if (a==startA)
    {
        if(p[coords.x][coords.y+3]>border
           ||p[coords.x+1][coords.y+2]>border)
           return true;
    }
    else
    {
        if(p[coords.x][coords.y+1]>border
           ||p[coords.x+1][coords.y+2]>border
           ||p[coords.x+2][coords.y+2]>border)
        return true;
    }
    return false;
}

void StairRight::Rotate()
{
    short *temP=ptr[0];
    ptr[0]=ptr[1];
    ptr[1]=temP;
    short temp=a;
    a=b;
    b=temp;
}

