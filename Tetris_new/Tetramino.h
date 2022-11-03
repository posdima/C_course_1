#ifndef TETRAMINO_H
#define TETRAMINO_H

struct Tetramino
{
    static const int XYMAX = 4;

    int figure[XYMAX][XYMAX];
    int xpos;
    int ypos;
};

void RandomizeTetramino(Tetramino *tetr);
void RotateTetramino(Tetramino *tetr);
int LeftBorderXabsTetramino(Tetramino *tetr);
int RightBorderXabsTetramino(Tetramino *tetr);
int BottomBorderXabsTetramino(Tetramino *tetr);

#endif // TETRAMINO_H
