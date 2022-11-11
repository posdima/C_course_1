#ifndef MENU_H
#define MENU_H
//
struct Menu
{
    static const int XMAX = 21;
    static const int YMAX = 5;

    char mmatrix[YMAX][XMAX];

    enum MenuPoint
    {
        START_GAME,
        EXIT,
    };
};

Menu* createMenu();
void printMenu(Menu* menu);


#endif // MENU_H
