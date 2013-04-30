#include "block.h"
#include "source.h"

Block::Block(short arg, short brg):
a(arg), b(brg), ptr(0)
{
    coords.x=0;
    coords.y=0;
}

Block::~Block()
{
    a=0;
    b=0;
    ptr=0;
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

void Block::Enter(Source *arg)
{
    char ***p=arg->GetP();
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
            p[coords.x+i][coords.y+j]=ptr[i][j];

}

void Block::Clear(Source *arg)
{
    char ***p=arg->GetP();
    for (short i=coords.x; i<coords.x+a; ++i)
        for (short j=coords.y; j<coords.y+b; ++j)
            p[i][j]=" ";
}
