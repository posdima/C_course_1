#ifndef BOARD_H
#define BOARD_H

#include "GameState.h"

struct Board
{
    enum BoardKey
    {
        ESC
    };

    GameSize gameSize;
};

Board* CreateBoard(GameSize gameSize);
void DestroyBoard(Board* board);
void PrintBoard(Board* board);

GameState RunBoard(Board* board, Board::BoardKey key);

#endif // BOARD_H
