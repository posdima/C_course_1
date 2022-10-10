#include "Palette.h"
#include <curses.h>

void InitPalette()
{
    start_color();
    init_pair(BOARD_PALETTE, COLOR_BLUE, COLOR_WHITE);
    init_pair(MENU_POL, COLOR_GREEN, COLOR_BLACK);
}
