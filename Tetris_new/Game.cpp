#include "Board.h"
#include "Control.h"
#include "Display.h"
#include "Game.h"

GameState RunGameSubModules(Game* game)
{
    GameState ret;

    if (!game)
    {
        return GameState::MENU;
    }

    ControlKey ch = getControl();
    
    switch (game->state)
    {
        case GameState::MENU:
        {
            ret = RunMenu(game->menu, ch);
            putDisplay(game->display, (char*)game->menu->mmatrix, Menu::YMAX, Menu::XMAX);
        } break;

        case GameState::BOARD:
        {
            if (game->menu->newGame == true)
            {
                game->menu->newGame = false;
                ResetBoard(game->board);
            }
            ret = RunBoard(game->board, ch);
            putDisplay(game->display, (char*)game->board->bmatrix, Board::YMAX, Board::XMAX);
        } break;

        case GameState::EXIT:
        default:
        {
            ret = game->state;
        }
    }

    showDisplay(game->display);
    return ret;
}

Game* CreateGame()
{
    Game *game = new Game;
    
    game->state = GameState::MENU;
    game->display = createDisplay();
    game->board = CreateBoard();
    game->menu = CreateMenu();

    return game;
}

void DestroyGame(Game* game)
{
    if (!game)
    {
        return;
    }

    DestroyMenu(game->menu);
    DestroyBoard(game->board);
    DestroyDisplay(game->display);
    delete game;
}

void RunGame(Game* game)
{
    while(game->state != EXIT)
    {
        game->state = RunGameSubModules(game);
    }
}
