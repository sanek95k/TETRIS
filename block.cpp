#include "block.h"

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

void Block::Enter(char ***arg)
{
    for (short i=0; i<a; ++i)
        for (short j=0; j<b; ++j)
            arg[coords.x+i][coords.y+j]=ptr[i][j];

}

short Block::GetX()
{
    return coords.x;
}

short Block::GetY()
{
    return coords.y;
}

short Block::GetA()
{
    return a;
}

short Block::GetB()
{
    return b;
}
