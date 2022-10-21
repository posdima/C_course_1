#include "Game.h"
#include "Palette.h"
#include <curses.h>

void PrintGameSubModules(Game* game)
{
    if (!game)
    {
        return;
    }

    switch (game->state)
    {
    case MENU:
        PrintMenu(game->menu);
        break;
    case BOARD:
        PrintBoard(game->board);
        MoveTetramino(game->tetramino);
        PrintTetramino(game->tetramino);
        break;
    case EXIT:
        return;
    }
}

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

    case BOARD:
    {
        switch(ch)
        {
        case 27:
            return RunBoard(game->board, Board::ESC);
//        case KEY_DOWN:
//            direction = Tetramino::DOWN;
//            break;
//        case KEY_LEFT:
//            direction = Tetramino::LEFT;
//            break;
//        case KEY_RIGHT:
//            direction = Tetramino::RIGHT;
//            break;
        case -1:
            break;
        default:
            return game->state;
        }
    }
    case EXIT:
        return game->state;
    }
        return game->state;
}


Game* CreateGame()
{
    initscr(); //Инициализация библиотеки
    keypad(stdscr, TRUE); // включить работу с непечатными символами (стрелками)
    curs_set(0); // Убрать мигающий курсор

    halfdelay(1);
    InitPalette();

    Game* game = new Game;
    game->state = MENU;
    game->gameSize = {55, 24};
    game->board = CreateBoard(game->gameSize);
    game->menu = CreateMenu(game->gameSize);
    game->tetramino = CreateTetramino(1);
    return game;
}

void DestroyGame(Game* game)
{
    if (!game)
    {
        return;
    }

    DestroyTetramino(game->tetramino);
    DestroyMenu(game->menu);
    DestroyBoard(game->board);
    delete game;
    endwin();
}

void RunGame(Game* game)
{
    while(game->state != EXIT)
    {
        PrintGameSubModules(game);
        game->state = RunGameSubModules(game);
    }
}
