#ifndef SQUARE_H
#define SQUARE_H

#include "block.h"
#include "field.h"

class Square: public Block
{
public:
    Square(short, short);
    ~Square();

    void Rotate();
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);
};

#endif
