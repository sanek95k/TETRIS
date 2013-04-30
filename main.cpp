#include "square.h"
#include "source.h"
#include "linplatform.h"

using namespace std;

int main()
{
    Source f(20, 14);
    Source *field=&f;
    char choice='s';
    while(field->Game())
    {
        Square sqr(1,14/2-1);
        Block *figure=&sqr;
        while(true)
        {
            figure->Enter(field);
            clearScreen();
            field->Draw();
            if (figure->StopDown(field))
                break;
            figure->Clear(field);
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
        field->Line();
        choice='s';
    }
    return 0;
}
