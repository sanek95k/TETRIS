#ifndef BLOCK_H
#define BLOCK_H

#include "field.h"

class Field;

class Block
{
protected:
    short startA, startB, a, b;
    char ***ptr;
    struct
    {
        short x, y;
    }coords;
public:

    Block(short, short);
    ~Block();

    virtual void Rotate(Field *);
    virtual bool StopDown(Field *)=0;
    virtual bool StopLeft(Field *)=0;
    virtual bool StopRight(Field *)=0;
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void Enter(Field *);
    void Clear(Field *);
};

#endif


