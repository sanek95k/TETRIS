#include "block.h"

using namespace cell;

Block::Block(short arg, short brg):
    startA(arg), startB(brg), ptr(0), shape(first), degreeOfRotation(zero)
{
    a=startA;
    b=startB;
    coords.x=0;
    coords.y=0;
}

Block::~Block()
{
    startA=0;
    startB=0;
    ptr=0;
}

bool Block::StopRotate(Field *arg)
{
    short **p=arg->GetP();
    if (a==startA)
    {
        for (short i=0; i<b; ++i)
            for (short j=0; j<b-a; ++j)
                if (p[coords.x+a+j][coords.y+i]>empty)
                    return true;
    }
    else
    {
        for (short i=0; i<a; ++i)
            for (short j=0; j<a-b; ++j)
                if (p[coords.x+i][coords.y+b+j]>empty)
                    return true;
    }
    return false;
}

bool Block::StopDown(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x+a][coords.y]==border)
        return true;
    if (a==startA&&shape==first)
    {
        for (short i=0; i<b; ++i)
            for (short j=0; j<a; ++j)
            {
                if (j<a-1)
                {
                    if (p[coords.x+j+1][coords.y+i]>border
                            &&ptr[j+1][i]==empty
                            &&ptr[j][i]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+j+1][coords.y+i]>border&&ptr[j][i]>border)
                        return true;
                }
            }
    }
    else
    {
        for (short i=0; i<b; ++i)
            for (short j=0; j<a; ++j)
            {
                if (j<a-1)
                {
                    if (p[coords.x+j+1][coords.y+i]>border
                            &&ptr[i][j+1]==empty
                            &&ptr[i][j]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+j+1][coords.y+i]>border&&ptr[i][j]>border)
                        return true;
                }
            }
    }
    return false;
}

bool Block::StopLeft(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y-1]==border)
        return true;
    if (a==startA)
    {
        for (short i=0; i<a; ++i)
            for (short j=0; j<b; ++j)
            {
                if (j<b-1)
                {
                    if (p[coords.x+i][coords.y+startB-j-2]>border
                            &&ptr[i][startB-j-2]==empty
                            &&ptr[i][startB-j-1]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+startB-j-2]>border&&ptr[i][startB-j-1]>border)
                        return true;
                }
            }
    }
    else
    {
        for (short i=0; i<a; ++i)
            for (short j=0; j<b; ++j)
            {
                if (j<b-1)
                {
                    if (p[coords.x+i][coords.y+startA-j-2]>border
                            &&ptr[startA-j-2][i]==empty
                            &&ptr[startA-j-1][i]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+startA-j-2]>border&&ptr[startA-j-1][i]>border)
                        return true;
                }
            }
    }
    return false;
}

bool Block::StopRight(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x][coords.y+b]==border)
        return true;
    if (a==startA)
    {
        for (short i=0; i<a; ++i)
            for (short j=0; j<b; ++j)
            {
                if (j<b-1)
                {
                    if (p[coords.x+i][coords.y+j+1]>border
                            &&ptr[i][j+1]==empty
                            &&ptr[i][j]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+j+1]>border&&ptr[i][j]>border)
                        return true;
                }
            }
    }
    else
    {
        for (short i=0; i<a; ++i)
            for (short j=0; j<b; ++j)
            {
                if (j<b-1)
                {
                    if (p[coords.x+i][coords.y+j+1]>border
                            &&ptr[j+1][i]==empty
                            &&ptr[j][i]>border)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+j+1]>border&&ptr[j][i]>border)
                        return true;
                }
            }
    }
    return false;
}

void Block::Rotate()
{
    if (degreeOfRotation==zero)
        return;
    if (shape==first)
    {
        short *temP=ptr[0];
        for (short i=0; i<startA/2; ++i)
        {
            temP=ptr[i];
            ptr[i]=ptr[startA-i-1];
            ptr[startA-i-1]=temP;
        }
        if (degreeOfRotation==four)
            shape=second;
    }
    else
    {
        if (degreeOfRotation==four)
        {
            short *temP2=new short [startA];
            for (short j=0; j<startB/2; ++j)
                for (short k=0; k<startA; ++k)
                {
                    temP2[k]=ptr[k][j];
                    ptr[k][j]=ptr[k][startB-j-1];
                    ptr[k][startB-j-1]=temP2[k];
                }
            delete [] temP2;
            temP2=0;
        }
        shape=first;
    }
    short temp=a;
    a=b;
    b=temp;
}

void Block::MoveRight()
{
    coords.y++;
}

void Block::MoveLeft()
{
    coords.y--;
}

void Block::MoveDown()
{
    coords.x++;
}

bool Block::Enter(Field *arg)
{
    short **p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
        {

            if (a==startA&&shape==first)
            {
                if (p[coords.x+i][coords.y+j]>border&&ptr[i][j]>border)
                    return false;
                if (p[coords.x+i][coords.y+j]<=border)
                    p[coords.x+i][coords.y+j]=ptr[i][j];
            }
            else
            {
                if (p[coords.x+i][coords.y+j]>border&&ptr[j][i]>border)
                    return false;
                if (ptr[j][i]!=empty)
                    p[coords.x+i][coords.y+j]=ptr[j][i];
            }

        }
    return true;
}

void Block::Clear(Field *arg)
{
    short **p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
        {
            if(a==startA&&shape==first)
            {
                if (ptr[i][j]!=empty)
                    p[coords.x+i][coords.y+j]=empty;
            }
            else
            {
                if (ptr[j][i]!=empty)
                    p[coords.x+i][coords.y+j]=empty;
            }
        }
}

void Block::ToDefault(short x, short y)
{
    while(a!=startA)
        Rotate();
    coords.x=x;
    coords.y=y;
}
