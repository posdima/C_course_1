#ifndef GAMESTATE_H
#define GAMESTATE_H

enum GameState
{
    MENU,
    BOARD,
    EXIT,
    GameOver
};

struct GameSize
{
    int width;
    int height;
};

#endif // GAMESTATE_H
