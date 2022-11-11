#ifndef BOARD_H
#define BOARD_H
//
#include "Control.h"
#include "GameState.h"

struct Board
{
    static const int XMAX = 79;
    static const int YMAX = 23;

    char bmatrix[YMAX][XMAX];

    static const int racketWidth = 8;
    int racketXpos;
    int racketYpos;
    char racket[1][8];
};

Board* createBoard();
void printBoard(Board* board);
void destroyBoard(Board* board);
void createRacket(Board* board);
GameState RunBoard(Board* board, Control key);

#endif // BOARD_H
