#ifndef DISPLAY_H
#define DISPLAY_H
//
struct Display
{
    static const int XMAX = 80;
    static const int YMAX = 24;

    char dmatrix[YMAX][XMAX];
};

Display* createDisplay();
void printDisplay(Display* display);
void destroyDisplay(Display* display);

#endif // DISPLAY_H
