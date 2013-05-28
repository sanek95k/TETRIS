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

    enum
    {
        first, second
    } shape;

    enum
    {
        zero, two, four
    } degreeOfRotation;

public:

    Block(short, short);
    virtual ~Block();

    virtual bool StopRotate(Field *arg);
    virtual bool StopDown(Field *);
    virtual bool StopLeft(Field *);
    virtual bool StopRight(Field *);

    virtual void Rotate();
    void MoveLeft();
    void MoveDown();
    void MoveRight();

    bool Enter(Field *);
    void Clear(Field *);
    void ToDefault (short, short);
};

#endif
