#ifndef TETRAMINO_H
#define TETRAMINO_H

#include "GameState.h"

struct Point
{
    int x;
    int y;
};

struct Tetramino
{
    enum TetraminoKey
    {
        UP,
        DOWN,
        ENTER
    };

    int figure[4][4];

//    int figures[7][4] = {
//        {1,3,5,7},
//        {2,4,5,7},
//        {3,5,4,6},
//        {3,5,4,7},
//        {2,3,5,7},
//        {3,5,7,6},
//        {2,3,4,5},
//    };


    Point position;

    int getFigureBorderX()
    {
        return 2;
    }

    int getFigureBorderY()
    {
        return 2;
    }
};



Tetramino* CreateTetramino();
void DestroyTetramino(Tetramino* tetramino);
void PrintTetramino(Tetramino* tetramino);
void MoveTetramino(Tetramino* tetramino);





#endif // TETRAMINO_H



