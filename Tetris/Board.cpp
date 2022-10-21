#include "Board.h"
#include "Helper.h"
#include "Palette.h"
#include <curses.h>

Board* CreateBoard(GameSize gameSize)
{
    Board* board = new Board;
    board->gameSize = gameSize;
    return board;
}

void DestroyBoard(Board* board)
{
    delete board;
}

void PrintBoard(Board* board)
{
    if (!board)
    {
        return;
    }

    attron(COLOR_PAIR(MENU_PALETTE));

    for(int i = 25; i < board->gameSize.width; ++i) {
        for(int j = 0; j < board->gameSize.height; ++j) {
            move(j, i);
            addch(' ');
        }
    }

    PrintBorder(board->gameSize.width, board->gameSize.height);
}

GameState RunBoard(Board* board, Board::BoardKey key)
{
    (void) board;

    switch (key) {
    case Board::ESC:
        return MENU;
    }
    return BOARD;
}
