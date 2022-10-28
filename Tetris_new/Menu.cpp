#include "Menu.h"
#include <memory.h>
#include <string.h>


static const char *strStartGameSelect =   " * Start game * ";
static const char *strStartGameEmpty  = "   Start game   ";
static const char *strExitSelect = " * Exit * ";
static const char *strExitEmpty  = "   Exit   ";

static void setCurrentPoint(Menu* menu, Menu::MenuPoint point)
{
    if (point == Menu::MenuPoint::START_GAME)
    {
        memcpy(&(menu->mmatrix[1][1]), strStartGameSelect, strlen(strStartGameSelect));
        memcpy(&(menu->mmatrix[2][1]), strExitEmpty, strlen(strExitEmpty));
    }
    else
    {
        memcpy(&(menu->mmatrix[1][1]), strStartGameEmpty, strlen(strStartGameEmpty));
        memcpy(&(menu->mmatrix[2][1]), strExitSelect, strlen(strExitSelect));
    }
    menu->currentPoint = point;
}

static void toggleCurrentPoint(Menu* menu)
{
    if (menu->currentPoint == Menu::MenuPoint::START_GAME)
    {
        setCurrentPoint(menu, Menu::MenuPoint::EXIT);
    } 
    else 
    {
        setCurrentPoint(menu, Menu::MenuPoint::START_GAME);
    }
}

Menu* CreateMenu()
{
    Menu* menu = new Menu;
    menu->newGame = true;

    for(int i = 0; i < Menu::YMAX; ++i){
        for(int j = 0; j < Menu::XMAX; ++j){
            menu->mmatrix[i][j] = 'M';
        }
    }

    setCurrentPoint(menu, Menu::START_GAME);
    return menu;
}

void DestroyMenu(Menu* menu)
{
    delete menu;
}

GameState RunMenu(Menu* menu, ControlKey key)
{
    switch (key)
    {
    case ControlKey::UP:
    case ControlKey::DOWN:
    {
        toggleCurrentPoint(menu);
        return GameState::MENU;
    }

    case ControlKey::ENTER:
    {
        switch (menu->currentPoint)
        {
        case Menu::START_GAME:
            menu->newGame = true;
            return GameState::BOARD;
        case Menu::EXIT:
            return GameState::EXIT;
        default:
            break;
        }
    }
    }
    return MENU;
}
