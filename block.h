#ifndef BLOCK_H
#define BLOCK_H

#include "field.h"

class Field;

class Block
{
protected:
    short startA, startB, a, b;
    short **ptr;
    struct
    {
        short x, y;
    } coords;
public:
    Block(short, short);
    virtual ~Block();

    virtual void Rotate(Field *);
    virtual bool StopDown(Field *);
    virtual bool StopLeft(Field *);
    virtual bool StopRight(Field *);
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void Enter(Field *);
    void Clear(Field *);
};

#endif
