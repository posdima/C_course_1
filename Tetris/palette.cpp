#include "Palette.h"
#include <curses.h>

void InitPalette()
{
    start_color();
    init_pair(BOARD_PALETTE, COLOR_BLUE, COLOR_WHITE);
    init_pair(MENU_PALETTE, COLOR_GREEN, COLOR_BLACK);
    init_pair(TETRAMINO_PALETTE, COLOR_BLUE, COLOR_WHITE);
}
