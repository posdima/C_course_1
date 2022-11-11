#include "Board.h"
#include "Display.h"
#include "Menu.h"
//
int main()
{
    Display* display = createDisplay();
    printDisplay(display);
    Menu* menu = createMenu();
    printMenu(menu);
    Board* board = createBoard();
    printBoard(board);
    createRacket(board);
    GameState RunBoard(Board* board, Control key);
    destroyDisplay(display);
    destroyBoard(board);


    return 0;
}
