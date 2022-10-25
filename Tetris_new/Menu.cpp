#include "Menu.h"

Menu* CreateMenu()
{
    Menu* menu = new Menu;

    for(int i = 0; i < Menu::YMAX; ++i){
        for(int j = 0; j < Menu::XMAX; ++j){
            menu->mmatrix[i][j] = '@';
        }
    }
//    menu->gameSize = gameSize;
//    menu->menuStrings[Menu::START_GAME] = "Start game";
//    menu->menuStrings[Menu::TABLE_RECORD] = "Table records";
//    menu->menuStrings[Menu::EXIT] = "Exit";
//    menu->currentPoint = Menu::START_GAME;
    return menu;
}

void DestroyMenu(Menu* menu)
{
    delete menu;
}

GameState RunMenu(Menu* menu, Menu::MenuKey key)
{
    switch (key) {
    case Menu::UP:
        if (menu->currentPoint != Menu::FIRST_POINT)
            --menu->currentPoint;
        return MENU;
    case Menu::DOWN:
        if (menu->currentPoint != Menu::LAST_POINT)
            ++menu->currentPoint;
        return MENU;
    case Menu::ENTER:
    {
        switch (menu->currentPoint) {
        case Menu::START_GAME:
            return BOARD;
        case Menu::TABLE_RECORD:
            return MENU;
        case Menu::EXIT:
            return EXIT;
        default:
            break;
        }
    }
    }
    return MENU;
}
