#ifndef SQUARE_H
#define SQUARE_H

#include "block.h"

class Square: public Block
{
public:

    Square(short, short);
    ~Square();
    
    bool StopRotate(Field *);
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);
    
};

#endif
