#include "Board.h"
#include "Game.h"
#include "GameState.h"
#include <curses.h>
#include <memory.h>
#include <string.h>

static int isMoveLeftPossible(Board* board, Tetramino *tetr)
{
    if (LeftBorderXabsTetramino(tetr) <= 0)
        return 0;

    if (BottomBorderXabsTetramino(tetr) >= Board::YMAX - 1)
        return 0;

    // check that we are stoped by bricks
    for(int x = 0; x < Tetramino::XYMAX; ++x) {
        for (int y = Tetramino::XYMAX - 1; y >= 0; --y) {
            if (tetr->figure[y][x] != 0) {
                int ly = tetr->ypos + y;
                int lx = tetr->xpos + x - 1; // look left for -1 by X
                if (board->lmatrix[ly][lx] != ' ')
                    return 0;
                break;
            }
        }
    }
    return 1;
}

static int isMoveRightPossible(Board* board, Tetramino *tetr)
{
    if (RightBorderXabsTetramino(tetr) >= Board::XMAX - 1)
        return 0;

    if (BottomBorderXabsTetramino(tetr) >= Board::YMAX - 1)
        return 0;

    // check that we are stoped by bricks
    for(int y = Tetramino::XYMAX - 1; y >= 0; --y) {
        for(int x = Tetramino::XYMAX - 1; x >= 0; --x) {
            if (tetr->figure[y][x] != 0) {
                int ly = tetr->ypos + y;
                int lx = tetr->xpos + x + 1; // look right by +1 by x
                if (board->lmatrix[ly][lx] != ' ')
                    return 0;
                break;
            }
        }
    }
    return 1;
}

static int isMoveDownPossible(Board* board, Tetramino *tetr)
{
    if (BottomBorderXabsTetramino(tetr) >= Board::YMAX - 1)
        return 0;

    // Check that we are hangs in bricks from bottom side
    for(int x = Tetramino::XYMAX - 1; x >=0; --x) {
        for(int y = Tetramino::XYMAX - 1; y >= 0; --y){
            if (tetr->figure[y][x] != 0) {
                int ly = tetr->ypos + y + 1; // look down for +1 by Y
                int lx = tetr->xpos + x;
                if (board->lmatrix[ly][lx] != ' ')
                    return 0;
                break;
            }
        }
    }
    return 1;
}

static int isRotatePossible(Board* board, Tetramino *tetr)
{
    Tetramino tempBlock;
    memcpy(&tempBlock, board->currentBlock, sizeof(Tetramino));
    RotateTetramino(&tempBlock);

    if (RightBorderXabsTetramino(&tempBlock) >= Board::XMAX)
        return 0;

    if (LeftBorderXabsTetramino(&tempBlock) < 0)
        return 0;

    if (BottomBorderXabsTetramino(&tempBlock) >= Board::YMAX - 1)
        return 0;

    for(int i = 0; i < Tetramino::XYMAX; ++i){ // put tetramino figure to outcome matrix
        for(int j = 0; j < Tetramino::XYMAX; ++j){
            if (tetr->figure[i][j] != 0)
            {
                if ((board->lmatrix[tetr->ypos + i + 1][tetr->xpos + j + 1] == '#') ||
                        (board->lmatrix[tetr->ypos + i - 1][tetr->xpos + j - 1] == '#'))
                    return 0;
            }
        }
    }
    return 1;
}

static void composeBoard(Board* board, Tetramino *tetr)
{
    memcpy(board->currentBlock, tetr, sizeof(Tetramino));
    memcpy(board->bmatrix, board->lmatrix, Board::XMAX * Board::YMAX); // put background bricks to outcome matrix

    for(int i = tetr->ypos; i < tetr->ypos + Tetramino::XYMAX; ++i){ // put tetramino figure to outcome matrix
        for(int j = tetr->xpos; j < tetr->xpos + Tetramino::XYMAX; ++j){
            if (j < 0) // tetr->xpos could be -1 due to figure doesnt have bricks in column [0]
                continue;
            if (tetr->figure[i-tetr->ypos][j - tetr->xpos] != 0)
            {
                board->bmatrix[i][j] = '#';
            }
        }
    }
}

static char score[Board::XSCR];
int realScore = 0;

static void foldBoard(Board *board)
{
    int array[Tetramino::XYMAX] = {};
    int yIndex = 0;

    for(int y = 0; y < Board::YMAX; ++y) {
        int rowSum = 0;
        for(int x = 0; x < Board::XMAX; ++x) {
            if (board->bmatrix[y][x] == ' ') {
                break;
            }
            else{
                ++rowSum;
            }
        }

        if (rowSum == Board::XMAX && yIndex < Tetramino::XYMAX){
            array[yIndex] = y;
            ++yIndex;
        }
    }

    for (int i = 0; i < Tetramino::XYMAX; ++i){
        if (array[i] != 0){
            memcpy(&(board->bmatrix[1][0]), &(board->bmatrix[0][0]), Board::XMAX * array[i]);
            sprintf(score, " Score: %u", realScore += 10);
            memcpy(&(board->smatrix[0][0]), score, strlen(score));
        }
    }
    memcpy(board->lmatrix, board->bmatrix, Board::XMAX * Board::YMAX);
}

static void resetTetramino(Tetramino *tetr)
{
    RandomizeTetramino(tetr);
    tetr->ypos = -(Tetramino::XYMAX / 2);
    tetr->xpos = Board::XMAX / 2;
}

/*Local functions*/
/*********************************************************************************************************************/
/*Public interface*/

Board* CreateBoard()
{
    Board *board = new Board;
    board->currentBlock = new Tetramino;

    ResetBoard(board);
    realScore = 0;
    memset(board->smatrix, ' ', 15);
    sprintf(score, " Score: %u", realScore);
    memcpy(&(board->smatrix[0][0]), score, strlen(score));

    return board;
}

void DestroyBoard(Board* board)
{
    delete board;
}

void ResetBoard(Board* board)
{
    for(int i = 0; i < Board::YMAX; ++i){
        for(int j = 0; j < Board::XMAX; ++j){
            board->bmatrix[i][j] = ' ';
            board->lmatrix[i][j] = ' ';
        }
    }

    resetTetramino(board->currentBlock);
}

GameState RunBoard(Board* board, ControlKey key)
{
    Tetramino tempBlock;
    memcpy(&tempBlock, board->currentBlock, sizeof(Tetramino));
    bool blockWasMoved = false;
    
    if (isMoveDownPossible(board, &tempBlock)) {
        tempBlock.ypos++;
        blockWasMoved = true;
    }

    switch (key)
    {
    case ControlKey::ESC:
        return GameState::MENU;

    case ControlKey::UP:
        if (isRotatePossible(board, &tempBlock)) {
            RotateTetramino(&tempBlock);
            blockWasMoved = true;
        }

    case ControlKey::DOWN:
        break;

    case ControlKey::LEFT:
        if (isMoveLeftPossible(board, &tempBlock)) {
            tempBlock.xpos--;
            blockWasMoved = true;
        }
        break;

    case ControlKey::RIGHT:
        if (isMoveRightPossible(board, &tempBlock)) {
            tempBlock.xpos++;
            blockWasMoved = true;
        }
        break;
    }

    if (blockWasMoved) {
        composeBoard(board, &tempBlock);
    }
    else {
        if (tempBlock.ypos < 0){
            return GameState::GameOver;
        }
        foldBoard(board);
        resetTetramino(board->currentBlock); // put tetramino on top and regenerate it
    }
    return GameState::BOARD;
}
