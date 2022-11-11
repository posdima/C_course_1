#include "Control.h"
#include <curses.h>
//
Control getControl()
{
    int ch = getch();

    switch(ch)
    {
        case KEY_LEFT: return Control::LEFT;
        case KEY_RIGHT: return Control::RIGHT;
        default: return Control::NONE;
    }
}
