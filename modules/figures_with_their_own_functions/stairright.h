#ifndef STAIRRIGHT_H
#define STAIRRIGHT_H

#include "block.h"

class StairRight: public Block
{
public:

    StairRight(short, short);
    ~StairRight();
    
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);

    void Rotate();
    
};

#endif
