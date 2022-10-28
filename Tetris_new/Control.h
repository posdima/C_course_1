#ifndef CONTROL_H
#define CONTROL_H

enum ControlKey
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    ESC,
    NONE
};

ControlKey getControl();

#endif // CONTROL_H
