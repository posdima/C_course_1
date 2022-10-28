#include "Control.h"
#include <curses.h>

ControlKey getControl()
{
    int ch = getch();

    switch(ch)
    {
        case KEY_UP: return ControlKey::UP;
        case KEY_DOWN: return ControlKey::DOWN;
        case KEY_LEFT: return ControlKey::LEFT;
        case KEY_RIGHT: return ControlKey::RIGHT;
        case 10:
        case KEY_ENTER: return ControlKey::ENTER;
        case 27: return ControlKey::ESC;
        default: return ControlKey::NONE;
    }
}
