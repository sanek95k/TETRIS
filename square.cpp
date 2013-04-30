#include "square.h"
#include "source.h"

Square::Square(short x, short y):
Block(2,2)
{
    ptr=new char** [a];
    for (short i=0; i<a; ++i)
    {
        ptr[i]=new char* [a];
        for (short j=0; j<b; ++j)
            ptr[i][j]="\356\202\252";
    }
    coords.x=x;
    coords.y=y;

}
Square::~Square()
{
    for (short i=0; i<a; ++i)
        delete [] ptr[i];
    delete [] ptr;
}

void Square::Rotate()
{
}

bool Square::StopDown(Source *arg)
{
    char ***p=arg->GetP();
    short l=arg->GetL();
    for (short i=coords.y; i<coords.y+b; ++i)
        if (p[coords.x+a][i]==p[l-1][i]||p[coords.x+a][i]=="\356\202\252")
            return true;
    return false;
}

bool Square::StopLeft(Source *arg)
{
    char ***p=arg->GetP();
    for (short i=coords.x; i<coords.x+a; ++i)
    if (coords.y-1==0||p[i][coords.y-1]=="\356\202\252")
        return true;
    return false;
}

bool Square::StopRight(Source *arg)
{
    char ***p=arg->GetP();
    short m=arg->GetM();
    for (short i=coords.x; i<coords.x+a; ++i)
    if (coords.y+a==m-1||p[i][coords.y+a]=="\356\202\252")
        return true;
    return false;
}
