#include "Display.h"
#include "Headpiece.h"
#include <curses.h>

void headpiece()
{
    initscr();

    mvprintw(2, 0, "  __________    _________    __________    ________    __    _________   ");
    mvprintw(3, 0, " |          |  |         |  |          |  |        |  |  |  |         |  ");
    mvprintw(4, 0, "  ===    ===   |   ======    ===    ===   |   __   |  |  |  |   ======   ");
    mvprintw(5, 0, "     |  |      |  |             |  |      |  |  |  |  |  |  |  |         ");
    mvprintw(6, 0, "     |  |      |   ===          |  |      |   ==   |  |  |  |   =====    ");
    mvprintw(7, 0, "     |  |      |      |         |  |      |     ====  |  |  |_____   |   ");
    mvprintw(8, 0, "     |  |      |   ===          |  |      |  |* *     |  |        |  |   ");
    mvprintw(9, 0, "     |  |      |  |             |  |      |  | * *    |  |        |  |   ");
    mvprintw(10, 0, "     |  |      |  =======       |  |      |  |  * *   |  |   _____|  |  ");
    mvprintw(11, 0, "     |  |      |         |      |  |      |  |   * *  |  |  |        |  ");
    mvprintw(12, 0, "      ==        =========        ==        ==     ==   ==    ========   ");

    getch();
}
