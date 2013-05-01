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
    char ***p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
        if (a==startA)
            p[coords.x+i][coords.y+j]=ptr[i][j];
        else
            p[coords.x+i][coords.y+j]=ptr[j][i];
}

void Block::Clear(Field *arg)
{
    char ***p=arg->GetP();
    for (short i=coords.x; i<coords.x+a; ++i)
        for (short j=coords.y; j<coords.y+b; ++j)
            p[i][j]=" ";
}
