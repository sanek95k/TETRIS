#include "block.h"

Block::Block(short arg, short brg):
    startA(arg), startB(brg), ptr(0)
{
    a=startA;
    b=startB;
    coords.x=0;
    coords.y=0;
}

Block::~Block()
{
    a=0;
    b=0;
    startA=0;
    startB=0;
    ptr=0;
}

void Block::Rotate(Field *arg)
{
}

bool Block::StopDown(Field *arg)
{
    short **p=arg->GetP();
    if (p[coords.x+a][coords.y]==border)
        return true;
    if (a==startA)
    {
        for (short i=0; i<b; ++i)
            for (short j=0; j<a; ++j)
            {
                if (j<a-1)
                {
                    if (p[coords.x+j+1][coords.y+i]==full
                            &&ptr[j+1][i]==empty
                            &&ptr[j][i]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+j+1][coords.y+i]==full&&ptr[j][i]==full)
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
                    if (p[coords.x+j+1][coords.y+i]==full
                            &&ptr[i][j+1]==empty
                            &&ptr[i][j]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+j+1][coords.y+i]==full&&ptr[i][j]==full)
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
                    if (p[coords.x+i][coords.y+startB-j-2]==full
                            &&ptr[i][startB-j-2]==empty
                            &&ptr[i][startB-j-1]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+startB-j-2]==full&&ptr[i][startB-j-1]==full)
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
                    if (p[coords.x+i][coords.y+startA-j-2]==full
                            &&ptr[startA-j-2][i]==empty
                            &&ptr[startA-j-1][i]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+startA-j-2]==full&&ptr[startA-j-1][i]==full)
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
                    if (p[coords.x+i][coords.y+j+1]==full
                            &&ptr[i][j+1]==empty
                            &&ptr[i][j]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+j+1]==full&&ptr[i][j]==full)
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
                    if (p[coords.x+i][coords.y+j+1]==full
                            &&ptr[j+1][i]==empty
                            &&ptr[j][i]==full)
                        return true;
                }
                else
                {
                    if(p[coords.x+i][coords.y+j+1]==full&&ptr[j][i]==full)
                        return true;
                }
            }
    }
    return false;
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

void Block::Enter(Field *arg)
{
    short **p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
        {
            if (a==startA)
            {
                if (p[coords.x+i][coords.y+j]!=full)
                    p[coords.x+i][coords.y+j]=ptr[i][j];
            }
            else
            {
                if (ptr[j][i]!=empty)
                    p[coords.x+i][coords.y+j]=ptr[j][i];
            }

        }
}

void Block::Clear(Field *arg)
{
    short **p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
        {
            if(a==startA)
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
