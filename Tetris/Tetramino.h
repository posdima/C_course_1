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
    int figure[4][4];

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

struct Tetramino_Generator
{
    Tetramino allFigures[7];
    Tetramino randomFigure;
};

Tetramino* CreateTetramino(int id);
void DestroyTetramino(Tetramino* tetramino);
void PrintTetramino(Tetramino* tetramino);
void MoveTetramino(Tetramino* tetramino);





#endif // TETRAMINO_H



