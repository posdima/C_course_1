#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Display.h"
#include "GameState.h"
#include "Menu.h"

struct Game
{
    GameState state;
    Display *display;
    Board *board;
    Menu *menu;
};

Game* CreateGame();
void DestroyGame(Game* game);
void RunGame(Game* game);

#endif // GAME_H
