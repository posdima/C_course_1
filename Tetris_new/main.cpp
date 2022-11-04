#include "Game.h"
#include "Headpiece.h"

int main()
{
    headpiece();
    Game* game = CreateGame();
    RunGame(game);
    DestroyGame(game);
    return 0;
}
