#ifndef SQUARE_H
#define SQUARE_H

#include "block.h"
#include "source.h"

class Square: public Block
{
public:
    Square(short, short);
    ~Square();

    void Rotate();
    bool StopDown(Source *);
    bool StopLeft(Source *);
    bool StopRight(Source *);
};

#endif
