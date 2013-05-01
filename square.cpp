#include "square.h"

Square::Square(short x, short y):
Block(2,2)
{
    ptr=new char** [startA];
    for (short i=0; i<startA; ++i)
    {
        ptr[i]=new char* [startB];
        for (short j=0; j<startB; ++j)
            ptr[i][j]="\356\202\252";
    }
    coords.x=x;
    coords.y=y;

}
Square::~Square()
{
    for (short i=0; i<startA; ++i)
        delete [] ptr[i];
    delete [] ptr;
}

bool Square::StopDown(Field *arg)
{
    char ***p=arg->GetP();
    short l=arg->GetL();
    for (short i=coords.y; i<coords.y+b; ++i)
        if (p[coords.x+a][i]==p[l-1][i]||p[coords.x+a][i]=="\356\202\252")
            return true;
    return false;
}

bool Square::StopLeft(Field *arg)
{
    char ***p=arg->GetP();
    for (short i=coords.x; i<coords.x+a; ++i)
    if (coords.y-1==0||p[i][coords.y-1]=="\356\202\252")
        return true;
    return false;
}

bool Square::StopRight(Field *arg)
{
    char ***p=arg->GetP();
    short m=arg->GetM();
    for (short i=coords.x; i<coords.x+a; ++i)
    if (coords.y+b==m-1||p[i][coords.y+b]=="\356\202\252")
        return true;
    return false;
}
