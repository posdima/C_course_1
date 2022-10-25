#ifndef GAME_H
#define GAME_H

#include "Display.h"
//#include "Board.h"
#include "GameState.h"
#include "Menu.h"

struct Game
{
    GameState state;
    GameSize gameSize;
//    Board* board;
    Menu* menu;
    Display* display;
};

Game* CreateGame();
void DestroyGame(Game* game);
void RunGame(Game* game);

#endif // GAME_H
