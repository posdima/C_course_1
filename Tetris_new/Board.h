#ifndef BOARD_H
#define BOARD_H

#include "Control.h"
#include "GameState.h"
#include "Tetramino.h"

struct Board
{
    static const int XMAX = 20;
    static const int YMAX = 20;

    char bmatrix[YMAX][XMAX]; // matrix to show, bricks and tetramino
    char lmatrix[YMAX][XMAX]; // matrix with bricks only

    static const int XSCR = 15;
    static const int YSCR = 1;

    char smatrix[YSCR][XSCR];

    static const int XGOVER = 6;
    static const int YGOVER = 3;

    char gmatrix[YGOVER][XGOVER] = {
        {' ', ' ', ' ', ' ', ' ', ' ',},
        {' ', ' ', 'G', 'A', 'M', 'E',},
        {' ', ' ', 'O', 'V', 'E', 'R',},
    };

    Tetramino* currentBlock;
};

Board* CreateBoard();
void DestroyBoard(Board* board);
void ResetBoard(Board* board);
GameState RunBoard(Board* board, ControlKey key);

#endif // BOARD_H
