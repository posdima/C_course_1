#ifndef MENU_H
#define MENU_H

#include "Control.h"
#include "GameState.h"

struct Menu
{
    enum MenuPoint
    {
        START_GAME,
        EXIT,
    };

    static const int XMAX = 20;
    static const int YMAX = 4;

    char mmatrix[YMAX][XMAX];

    int currentPoint;
    bool newGame;
};

Menu* CreateMenu();
void DestroyMenu(Menu* menu);
GameState RunMenu(Menu* menu, ControlKey key);

#endif // MENU_H
