#include "Board.h"
#include <curses.h>

Board* createBoard()
{
    Board* board = new Board;

    for (int i = 1; i < Board::YMAX; ++i){
        for (int j = 1; j < Board::XMAX; ++j){
            board->bmatrix[i][j] = ' ';
        }
    }
    return board;
}

void printBoard(Board* board)
{
    if (!board)
    {
        return;
    }

    for (int i = 1; i < Board::YMAX; ++i){
        for (int j = 1; j < Board::XMAX; ++j){
            move(i, j);
            addch(board->bmatrix[i][j]);
        }
    }
    getch();
}

void destroyBoard(Board* board)
{
    delete board;
}

void createRacket(Board* board)
{
    if (!board)
    {
        return;
    }

    board->racketXpos = (Board::XMAX)/2;
    board->racketYpos = (Board::YMAX) - 1;

    for (int i = board->racketXpos; i < board->racketXpos + board->racketWidth; ++i)
    {
        board->racket[board->racketYpos][i] = '$';
    }

    for (int i = board->racketXpos; i < board->racketXpos + board->racketWidth; ++i)
    {
        move(board->racketYpos, i);
        addch(board->racket[board->racketYpos][i]);
    }
    getch();
}

GameState RunBoard(Board* board, Control key)
{
    switch (key)
    {
        case Control::LEFT:
        --board->racketXpos;

        case Control::RIGHT:
        ++board->racketXpos;

        default:
            break;
    }
    return GameState::BOARD;
}




