#ifndef STAIRLEFT_H
#define STAIRLEFT_H

#include "block.h"

class StairLeft: public Block
{
public:

    StairLeft(short, short);
    ~StairLeft();
    
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);

    void Rotate();
    
};

#endif
