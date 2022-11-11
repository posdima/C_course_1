#include "Display.h"
#include <curses.h>
//
Display* createDisplay()
{
    Display* display = new Display;

    for (int i = 0; i < Display::YMAX; ++i){
        for (int j = 0; j < Display::XMAX; ++j){
            display->dmatrix[i][j] = '@';
        }
    }

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);

    return display;
}

void printDisplay(Display* display)
{
    if (!display)
    {
        return;
    }

    for (int i = 0; i < Display::YMAX; ++i){
        for (int j = 0; j < Display::XMAX; ++j){
            move(i, j);
            addch(display->dmatrix[i][j]);
        }
    }
    getch();
}

void destroyDisplay(Display* display)
{
    delete display;
}
