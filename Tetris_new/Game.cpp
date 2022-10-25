#include "Display.h"
#include "Game.h"
#include <curses.h>

GameState RunGameSubModules(Game* game)
{
    if (!game)
    {
        return MENU;
    }

    int ch = getch();

    switch (game->state)
    {
    case MENU:
        Menu::MenuKey menuKey;
        putDisplay(game->display, (int**)game->menu->mmatrix, Menu::YMAX, Menu::XMAX);
        showDisplay(game->display);
        switch(ch)
        {
        case KEY_UP:
            menuKey = Menu::UP;
            break;
        case KEY_DOWN:
            menuKey = Menu::DOWN;
            break;
        case 10:
            menuKey = Menu::ENTER;
            break;
        default:
            return game->state;
        }
        return RunMenu(game->menu, menuKey);

//    case BOARD:
//    {
//        switch(ch)
//        {
//        case 27:
//            return RunBoard(game->board, Board::ESC);
//        case KEY_DOWN:
//            direction = Tetramino::DOWN;
//            break;
//        case KEY_LEFT:
//            direction = Tetramino::LEFT;
//            break;
//        case KEY_RIGHT:
//            direction = Tetramino::RIGHT;
//            break;
//        case -1:
//            break;
//        default:
//            return game->state;
//        }
//    }
    case EXIT:
        return game->state;
    }
        return game->state;
}

Game* CreateGame()
{
    Game* game = new Game;
    game->state = MENU;
//    game->board = CreateBoard(game->gameSize);
    game->menu = CreateMenu();
    game->display = createDisplay();

    return game;
}

void DestroyGame(Game* game)
{
    if (!game)
    {
        return;
    }

    DestroyMenu(game->menu);
    DestroyDisplay(game->display);
//    DestroyBoard(game->board);
    delete game;
}

void RunGame(Game* game)
{
    while(game->state != EXIT)
    {
        game->state = RunGameSubModules(game);
    }
}
