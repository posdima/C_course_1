#include "Display.h"
#include <curses.h>

Display* createDisplay()
{
    Display* disp = new Display;

    for(int i = 0; i < Display::XMAX; ++i){
        for(int j = 0; j < Display::YMAX; ++j){
            disp->dmatrix[i][j] = 'x';
        }
    }

    initscr(); //Инициализация библиотеки
    keypad(stdscr, TRUE); // включить работу с непечатными символами (стрелками)
    curs_set(0); // Убрать мигающий курсор

    halfdelay(1);
    start_color();

    return disp;
}

void DestroyDisplay(Display* disp)
{
    delete disp;
    endwin();
}

void clearDisplay(Display* disp)
{
    for(int i = 0; i < Display::XMAX; ++i){
        for(int j = 0; j < Display::YMAX; ++j){
            disp->dmatrix[i][j] = ' ';
        }
    }
}

void showDisplay(Display* disp)
{
    for(int i = 0; i < Display::XMAX; ++i){
        for(int j = 0; j < Display::YMAX; ++j){
            move(i, j);
            addch(disp->dmatrix[i][j]);
        }
    }
}

void putDisplay(Display* disp, int** matrix, int row, int column)
{
    for(int i = 0; i < column; ++i){
        for(int j = 0; j < row; ++j){
            disp->dmatrix[j][i] = '%';

//                    matrix[column][row];
        }
    }



}


