#include "square.h"
#include "source.h"
#include "linplatform.h"

using namespace std;

int main()
{
    char ***field=0;
    construct(field);
    char choice='s';
    while(game(field))
    {
        Square sqr(1,M/2-1);
        Block *figure=&sqr;
        while(true)
        {
            figure->Enter(field);
            clearScreen();
            draw(field);
            if (figure->StopDown(field))
                break;
            clear(field, figure);
            if(kbhit())
                choice=getch();
            switch (choice)
            {
            case 's':
                nap(500);
                figure->MoveDown();
                break;
            case 'd':
                if (!figure->StopRight(field))
                    figure->MoveRight();
                choice='s';
                break;
            case 'a':
                if (!figure->StopLeft(field))
                    figure->MoveLeft();
                choice='s';
                break;
            case 'q':
                nap(10);
                figure->MoveDown();
                break;
            case 'x':
                return 0;
            default:
                choice='s';
                break;
            }
        }
        line(field);
        choice='s';
    }
    destruct(field);
    return 0;
}
