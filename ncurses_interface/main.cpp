#define _XOPEN_SOURCE_EXTENDED

#include "source.h"
#include "locale.h"
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>
#include <exception>

#include "field.h"

#include "square.h"
#include "line.h"
#include "stairleft.h"
#include "stairright.h"
#include "pedestal.h"
#include "cornerleft.h"
#include "cornerright.h"
#include "testfigure.h"

using namespace cell; // Объявлено в field.h

/// Обработка ошибок, связанных с цветами

class NonColors: public std::exception
{
    const char *what() const throw()
    {
        return "Цвета не поддерживаются";
    }
};

/// Класс для вывода поля в консоль

class ConField: public Field
{
public:

    ConField(short a,short b):
        Field(a,b)
    {
    }
    ~ConField()
    {
    }
    void Draw(WINDOW *);
};

void ConField::Draw(WINDOW *arg)
{
    for (short i=0; i<l; ++i)
    {
        wmove(arg, i, 0);
        for (short j=0; j<m; ++j)
        {
            switch(p[i][j])
            {

            case empty:
                wattron(arg,COLOR_PAIR(empty));
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(empty));
                break;

            case cell::border:
                wattron(arg,COLOR_PAIR(cell::border));

                if (i==0)
                    if (j==0)
                        wprintw(arg, "\342\224\217\342\224\201");
                    else if (j==m-1)
                        wprintw(arg, "\342\224\223 ");
                    else
                        wprintw(arg, "\342\224\201\342\224\201");

                else if (i==l-1)
                    if (j==0)
                        wprintw(arg, "\342\224\227\342\224\201");
                    else if (j==m-1)
                        wprintw(arg, "\342\224\233 ");
                    else
                        wprintw(arg, "\342\224\201\342\224\201");
                else
                    wprintw(arg, "\342\224\203 ");

                wattroff(arg,COLOR_PAIR(cell::border));
                break;

            case green:
                wattron(arg,COLOR_PAIR(green)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(green)|A_REVERSE);
                break;

            case yellow:
                wattron(arg,COLOR_PAIR(yellow)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(yellow)|A_REVERSE);
                break;

            case red:
                wattron(arg,COLOR_PAIR(red)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(red)|A_REVERSE);
                break;

            case blue:
                wattron(arg,COLOR_PAIR(blue)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(blue)|A_REVERSE);
                break;

            case white:
                wattron(arg,COLOR_PAIR(white)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(white)|A_REVERSE);
                break;

            case magenta:
                wattron(arg,COLOR_PAIR(magenta)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg,COLOR_PAIR(magenta)|A_REVERSE);
                break;

            case cyan:
                wattron(arg,COLOR_PAIR(cyan)|A_REVERSE);
                wprintw(arg, "  ");
                wattroff(arg, COLOR_PAIR(cyan)|A_REVERSE);
                break;
            }
        }
        wprintw(arg, "\n");
    }
}

// Некоторые функции интерфейса

void sig_winch(int)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
}

void fill(WINDOW *arg, short sc, short t)
{
    wmove(arg, 2, 0);
    wattron(arg, A_BOLD);
    wprintw(arg, "Счёт: ");
    wprintw(arg, "%i", sc);
    wattroff(arg, A_BOLD);
    wmove(arg, 4, 0);
    wclrtoeol(arg);
    switch (t)
    {

    case 1:
        wattron(arg, COLOR_PAIR(magenta)|A_BOLD);
        wprintw(arg, "Есть!");
        wattroff(arg, COLOR_PAIR(magenta)|A_BOLD);
        break;

    case 2:
        wattron(arg, COLOR_PAIR(cyan)|A_BOLD);
        wprintw(arg, "Две строки!");
        wattroff(arg, COLOR_PAIR(cyan)|A_BOLD);
        break;

    case 3:
        wattron(arg, COLOR_PAIR(green)|A_BOLD);
        wprintw(arg, "Очень хорошо!");
        wattroff(arg, COLOR_PAIR(green)|A_BOLD);
        break;

    case 4:
        wattron(arg, COLOR_PAIR(yellow)|A_BOLD);
        wprintw(arg, "Великолепно!");
        wattroff(arg, COLOR_PAIR(yellow)|A_BOLD);
        break;

    default:
        wattron(arg, COLOR_PAIR(blue)|A_BOLD);
        wprintw(arg, "Играем...");
        wattroff(arg, COLOR_PAIR(blue));
        break;

    }

}

bool oneMoreTime(WINDOW *arg)
{
    wmove(arg, 4, 0);
    wclrtoeol(arg);
    wattron(arg, COLOR_PAIR(red)|A_BOLD);
    wprintw(arg, "ИГРА ОКОНЧЕНА!");
    wattroff(arg, COLOR_PAIR(red)|A_BOLD);
    wmove(arg, 9, 0);
    wprintw(arg, "Ещё раз?");
    wmove(arg, 10, 0);
    wattron(arg, COLOR_PAIR(green));
    wprintw(arg, "'y'");
    wattroff(arg, COLOR_PAIR(green));
    wprintw(arg, " - да");
    wmove(arg, 11, 0);
    wattron(arg, COLOR_PAIR(red));
    wprintw(arg, "'n'");
    wattroff(arg, COLOR_PAIR(red));
    wprintw(arg, " - нет");
    wrefresh(arg);
    char choice=0;
    while (choice!='y'&&choice!='n')
        choice=myGetch();
    if (choice=='y')
        return true;
    return false;
}

void gameBreak(WINDOW *arg)
{
    wmove(arg, 4, 0);
    wclrtoeol(arg);
    wattron(arg, COLOR_PAIR(green)|A_BOLD);
    wprintw(arg, "ПАУЗА");
    wattroff(arg, COLOR_PAIR(green)|A_BOLD);
    wmove(arg, 5, 0);
    wprintw(arg, "Нажмите любую \nклавишу...");
    wrefresh(arg);
    myGetch();
    wmove(arg, 4, 0);
    wclrtobot(arg);
    wattron(arg, COLOR_PAIR(blue)|A_BOLD);
    wprintw(arg, "Играем...");
    wattroff(arg, COLOR_PAIR(blue));
    wrefresh(arg);
}




int main()
{
    setlocale(LC_ALL, "");

    WINDOW *infoscr;
    WINDOW *gamescr;
    WINDOW *statusscr;

    initscr();
    signal(SIGWINCH, sig_winch);

    cbreak();
    noecho();
    curs_set(0);

    if (!has_colors())
    {
        endwin();
        throw NonColors();
    }

    start_color();
    init_pair(empty, COLOR_BLACK, COLOR_BLACK);
    init_pair(cell::border, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(yellow, COLOR_YELLOW, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
    init_pair(blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(white, COLOR_WHITE, COLOR_BLACK);
    init_pair(magenta, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(cyan, COLOR_CYAN, COLOR_BLACK);

/// Переменная, отвечающая за кол-во фигур
/// (изменить при добавлении тестовой фигуры)

    short figures=7;

    short pause;
    short height=22, width=14;
    short centerX=1, centerY=width/2-1;

    infoscr = newwin (15, 20, 3, 2);
    gamescr = newwin (height, width*2, 1, 25);
    statusscr = newwin (15, 20, 3, 55);

    ConField *field=new ConField(height, width);

    Block *figure[figures];
    figure[0]=new Square(centerX, centerY);
    figure[1]=new Line(centerX, centerY);
    figure[2]=new StairLeft(centerX, centerY);
    figure[3]=new StairRight(centerX, centerY);
    figure[4]=new Pedestal (centerX, centerY);
    figure[5]=new CornerLeft (centerX, centerY);
    figure[6]=new CornerRight (centerX, centerY);
/// (при добавлении тестовой фигуры) figure[7]=new TestFigure (centerX, centerY);

// Главный цикл игры (1)

    do
    {
        field->ClearField();
        field->Draw(gamescr);
        wrefresh(gamescr);

        wclear(infoscr);
        wclear(statusscr);
        wrefresh(statusscr);

        short score=0;
        bool exit=false;
        char choice=1;

        wmove(infoscr, 0, 5);
        wattron(infoscr, COLOR_PAIR(yellow)|A_BOLD);
        wprintw(infoscr, "ТЕТРИС");
        wattroff(infoscr, COLOR_PAIR(yellow));

        wmove(infoscr, 2, 0);
        wprintw(infoscr, "Правила:");
        wattroff(infoscr, A_BOLD);

        wmove(infoscr, 3, 0);
        wprintw(infoscr, "'a' - влево");
        wmove(infoscr, 4, 0);
        wprintw(infoscr, "'d' - вправо");
        wmove(infoscr, 5, 0);
        wprintw(infoscr, "'s' - быстро вниз");
        wmove(infoscr, 6, 0);
        wprintw(infoscr, "'r' - повернуть");
        wmove(infoscr, 7, 0);
        wprintw(infoscr, "'x' - завершить игру");
        wmove(infoscr, 8, 0);
        wprintw(infoscr, "'p' - пауза");

        wmove(infoscr, 10, 0);
        wattron(infoscr, A_BOLD);
        wprintw(infoscr, "ВЫБЕРИТЕ УРОВЕНЬ\nСЛОЖНОСТИ (e, m, h):");
        wattroff(infoscr, A_BOLD);

        wmove(infoscr, 12, 0);
        wattron(infoscr, COLOR_PAIR(green));
        wprintw(infoscr, "'e' - лёгко");
        wattroff(infoscr, COLOR_PAIR(green));
        wmove(infoscr, 13, 0);
        wattron(infoscr, COLOR_PAIR(yellow));
        wprintw(infoscr, "'m' - нормально");
        wattroff(infoscr, COLOR_PAIR(yellow));
        wmove(infoscr, 14, 0);
        wattron(infoscr, COLOR_PAIR(red));
        wprintw(infoscr, "'h' - тяжёло");
        wattroff(infoscr, COLOR_PAIR(red));
        wrefresh(infoscr);

        while(choice!='e'&&choice!='m'&&choice!='h')
            choice=myGetch();
        wmove(infoscr, 10, 0);
        wclrtobot(infoscr);
        wattron(infoscr, A_BOLD);
        wprintw(infoscr, "Сложность:");
        wattroff(infoscr, A_BOLD);

        switch (choice)
        {

        case 'e':
            pause=450;
            wattron(infoscr, COLOR_PAIR(green)|A_BOLD);
            wprintw(infoscr, " легко");
            wattroff(infoscr, COLOR_PAIR(green)|A_BOLD);
            break;

        case 'm':
            pause=300;
            wattron(infoscr, COLOR_PAIR(yellow)|A_BOLD);
            wprintw(infoscr, " нормально");
            wattroff(infoscr, COLOR_PAIR(yellow)|A_BOLD);
            break;

        case 'h':
            pause=150;
            wattron(infoscr, COLOR_PAIR(red)|A_BOLD);
            wprintw(infoscr, " тяжело");
            wattroff(infoscr, COLOR_PAIR(red)|A_BOLD);
            break;
        }
        wrefresh(infoscr);

        choice=1;
        srand(time(0));

// Подцикл игры, отвечающий за падение фигур (2)

        while(!exit)
        {
            short temp=field->KillLine();
            score+=temp;
            fill(statusscr, score, temp);
            wrefresh(statusscr);

            short whatFig=rand()%figures;

// Подцикл игры, отвечающий за пошаговое движение фигур (3)

            while(!exit)
            {

                if(!figure[whatFig]->Enter(field))
                {
                    exit=true;
                    continue;
                }
                field->Draw(gamescr);
                wrefresh(gamescr);

                if (figure[whatFig]->StopDown(field))
                    break;
                figure[whatFig]->Clear(field);

                if(myKbhit())
                    choice=myGetch();
                switch (choice)
                {

                case 1:
                    figure[whatFig]->MoveDown();
                    nap(pause);
                    break;

                case 'd':
                    if (!figure[whatFig]->StopRight(field))
                        figure[whatFig]->MoveRight();
                    choice=1;
                    break;

                case 'a':
                    if (!figure[whatFig]->StopLeft(field))
                        figure[whatFig]->MoveLeft();
                    choice=1;
                    break;

                case 's':
                    nap(pause/50);
                    figure[whatFig]->MoveDown();
                    break;

                case 'r':
                    if (!figure[whatFig]->StopRotate(field))
                        figure[whatFig]->Rotate();
                    choice=1;
                    break;

                case 'p':
                    gameBreak(statusscr);
                    choice=1;
                    break;

                case 'x':
                    exit=true;
                    break;

                default:
                    choice=1;
                    break;
                }

// Конец цикла (3)

            }

            choice=1;
            figure[whatFig]->ToDefault(centerX, centerY);

// Конец цикла (2)

        }

// Конец цикла (1)

    }
    while (oneMoreTime(statusscr));

// Завершение программы

    delwin(infoscr);
    delwin(gamescr);
    delwin(statusscr);
    for (short i=0; i<figures; ++i)
    {
        delete  figure[i];
        figure[i]=0;
    }
    *figure=0;
    delete field;
    field=0;
    endwin();
    clearScreen();
    return 0;
}
