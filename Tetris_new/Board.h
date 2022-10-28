#ifndef BOARD_H
#define BOARD_H

#include "Control.h"
#include "GameState.h"
#include "Tetramino.h"

struct Board
{
    static const int XMAX = 20;
    static const int YMAX = 20;

    char bmatrix[YMAX][XMAX]; // matrix to show, brics and tetramino
    char lmatrix[YMAX][XMAX]; // matrix with brics only
    Tetramino* currentBlock;
};

Board* CreateBoard();
void DestroyBoard(Board* board);
void ResetBoard(Board* board);
GameState RunBoard(Board* board, ControlKey key);

#endif // BOARD_H
