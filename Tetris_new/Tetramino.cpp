#include "Board.h"
#include "Tetramino.h"
#include <memory.h>
#include <stdlib.h>
#include <time.h>

static int figure_1[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
};

static int figure_2[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
};

static int figure_3[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
};

static int figure_4[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
};

static int figure_5[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
};

static int figure_6[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
};

static int figure_7[Tetramino::XYMAX][Tetramino::XYMAX] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};

void RandomizeTetramino(Tetramino *tetr)
{
    srand(time(NULL));
    int index = rand() % 7 + 1;

    switch (index) {
    case 1: memcpy(tetr->figure, figure_1, sizeof(figure_1));
        break;
    case 2: memcpy(tetr->figure, figure_2, sizeof(figure_2));
        break;
    case 3: memcpy(tetr->figure, figure_3, sizeof(figure_3));
        break;
    case 4: memcpy(tetr->figure, figure_4, sizeof(figure_4));
        break;
    case 5: memcpy(tetr->figure, figure_5, sizeof(figure_5));
        break;
    case 6: memcpy(tetr->figure, figure_6, sizeof(figure_6));
        break;
    case 7: memcpy(tetr->figure, figure_7, sizeof(figure_7));
        break;
    }
}

void RotateTetramino(Tetramino *tetr)
{
    Tetramino temp;
    for(int y = 0; y < Tetramino::XYMAX; ++y) {
        for(int x = 0; x < Tetramino::XYMAX; ++x)
            temp.figure[x][y] = tetr->figure[Tetramino::XYMAX - 1 - y][x];
    }
    memcpy(tetr->figure, temp.figure, Tetramino::XYMAX * Tetramino::XYMAX * sizeof(temp.figure[0][0]));
}

int LeftBorderXabsTetramino(Tetramino *tetr)
{
    for (int x = 0; x < Tetramino::XYMAX; ++x) {
        for (int y = 0; y < Tetramino::XYMAX; ++y) {
            if (tetr->figure[y][x] != 0)
                return tetr->xpos + x;
        }
    }
    return tetr->xpos;
}

int RightBorderXabsTetramino(Tetramino *tetr)
{
    for (int x = Tetramino::XYMAX - 1; x >= 0 ; --x) {
        for (int y = 0; y < Tetramino::XYMAX; ++y) {
            if (tetr->figure[y][x] != 0)
                return tetr->xpos + x;
        }
    }
    return tetr->xpos;
}

int BottomBorderXabsTetramino(Tetramino *tetr)
{
    for (int y = Tetramino::XYMAX - 1; y >= 0; --y) {
        for (int x = Tetramino::XYMAX - 1; x >= 0; --x) {
            if (tetr->figure[y][x] != 0)
                return tetr->ypos + y;
        }
    }
    return tetr->ypos;
}
