#ifndef DISPLAY_H
#define DISPLAY_H

struct Display
{
    static const int XMAX = 22;
    static const int YMAX = 72;

    char dmatrix[XMAX][YMAX];
};

Display* createDisplay();
void DestroyDisplay(Display*);
void clearDisplay(Display*);
void showDisplay(Display*);
void putDisplay(Display*, char* matrix, int row, int column);
void putDisplayRight(Display*, char* matrix, int row, int column);

#endif // DISPLAY_H
