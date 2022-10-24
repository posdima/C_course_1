#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "GameState.h"
#include "Menu.h"
#include "Tetramino.h"

struct Game
{
    GameState state;
    GameSize gameSize;
    Board* board;
    Menu* menu;
    Tetramino* tetramino;
};

Game* CreateGame();
void DestroyGame(Game* game);
void RunGame(Game* game);

#endif // GAME_H
