#ifndef SQUARE_H
#define SQUARE_H

#include "block.h"

class Square: public Block
{
public:
    Square(short, short);
    ~Square();

    void Rotate();
    bool StopDown(char ***&);
    bool StopLeft(char ***&);
    bool StopRight(char ***&);
};

#endif
