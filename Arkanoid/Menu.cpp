#include "Display.h"
#include "Menu.h"
#include <curses.h>

Menu* createMenu()
{
    Menu* menu = new Menu;

    for (int i = 1; i < Menu::YMAX; ++i){
        for (int j = 1; j < Menu::XMAX; ++j){
            menu->mmatrix[i][j] = 'M';
        }
    }

    return menu;
}
//
void printMenu(Menu* menu)
{
    if (!menu)
    {
        return;
    }

    for (int i = 1; i < Menu::YMAX; ++i){
        for (int j = 1; j < Menu::XMAX; ++j){
            move(i, j);
            addch(menu->mmatrix[i][j]);
        }
    }
    getch();
}
