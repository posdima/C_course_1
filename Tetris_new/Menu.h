#ifndef MENU_H
#define MENU_H

#include "GameState.h"

struct Menu
{
    enum MenuKey
    {
        UP,
        DOWN,
        ENTER
    };

    enum MenuPoint
    {
        START_GAME,
        TABLE_RECORD,
        EXIT,

        COUNT,
        FIRST_POINT = START_GAME,
        LAST_POINT = EXIT
    };

    static const int XMAX = 20;
    static const int YMAX = 4;

    int mmatrix[YMAX][XMAX];

    int currentPoint;
};

Menu* CreateMenu();
void DestroyMenu(Menu* menu);
GameState RunMenu(Menu* menu, Menu::MenuKey key);

#endif // MENU_H
