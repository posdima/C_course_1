#include "Tetramino.h"
#include "Palette.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

static int figure_1[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};

static int figure_2[4][4] = {
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};

static int figure_3[4][4] = {
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};

static int figure_4[4][4] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
};

static int figure_5[4][4] = {
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};

static int figure_6[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
};

static int figure_7[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};

Tetramino* CreateTetramino()
{
    Tetramino* figure = new Tetramino;
    int nextFigure;
    srand(time(NULL));
    nextFigure = rand() % 7 + 1;

    figure->position.x = 30;
    figure->position.y = 1;

    switch (nextFigure) {
        case 1: memcpy(figure->figure, figure_1, sizeof(figure_1));
            break;
        case 2: memcpy(figure->figure, figure_2, sizeof(figure_2));
            break;
        case 3: memcpy(figure->figure, figure_3, sizeof(figure_3));
            break;
        case 4: memcpy(figure->figure, figure_4, sizeof(figure_4));
            break;
        case 5: memcpy(figure->figure, figure_5, sizeof(figure_5));
            break;
        case 6: memcpy(figure->figure, figure_6, sizeof(figure_6));
            break;
        case 7: memcpy(figure->figure, figure_7, sizeof(figure_7));
            break;
        }

//    Point a[4];
//    int n = 4;

//    for (int i = 0; i < 4; i++)
//    {
//        a[i].x = figure->figures[n][i] % 2;
//        a[i].y = figure->figures[n][i] / 2;
//    }

    return figure;
}

void DestroyTetramino(Tetramino* tetramino)
{
    delete tetramino;
}

void PrintTetramino(Tetramino* tetramino)
{
    if (!tetramino) {
        return;
    }

//    Point a[4];
//    int n = 4;

//    for (int i = 0; i < 4; i++)
//    {
//        a[i].x = tetramino->figures[n][i] % 2;
//        a[i].y = tetramino->figures[n][i] / 2;
//        addch('#');
//    }

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (tetramino->figure[j][i] > 0){
                int x = tetramino->position.x + i;
                int y = tetramino->position.y + j;
                move(y, x);
                addch('#');
            }
        }
    }
}


/*for (int i = 0; i < tetramino->tetraminoSize; ++i)
    {
        move(tetramino->figure[i].y, tetramino->figure[i].x);
        addch('#');
    }*/
//}

/*GameState RunTetramino(Tetramino* tetramino, Tetramino::Direction direction)
{
    if (!tetramino)
    {
        return GameState::BOARD;
    }

    MoveTetramino(tetramino);

    tetramino->direction = direction;
    return GameState::BOARD;
}*/

void MoveTetramino(Tetramino* tetramino)
{
    //    int i = 30;

    //    for (int j = tetramino->position.y - 1; j >= 1; --j)
    //    {
    //        tetramino->figure[i][j] = tetramino->figure[i][j-1];
    //    }

    do
        ++(tetramino->position.y);
    while(tetramino->position.y > 20);


//    if ((tetramino->position.y >= 22) && ((tetramino->position.x >= 56) || (tetramino->position.x < 25)))
//    {
//            addch(' ');
//}

//        for(int i = 25; i < width; ++i)
//            {
//                for(int j = 0; j < height; ++j)
//                {
//                    move(j, i);

    int ch = getch();

    switch(ch)
    {
    case KEY_DOWN:
        ++(tetramino->position.y);
        break;
    case KEY_LEFT:
        --(tetramino->position.x);
        break;
    case KEY_RIGHT:
        ++(tetramino->position.x);
        break;
//    default:
//        return game->state;
    }




//    if (tetramino->position.y = 21)
//    {
//        break;
//    }


    //    ++(tetramino->position.y);


    //    switch(tetramino->direction)
    //    {
    //    case Tetramino::DOWN:
    //        ++(tetramino->position.y);
    //        break;
    //    case Tetramino::LEFT:
    //        --(tetramino->position.x);
    //        break;
    //    case Tetramino::RIGHT:
    //        ++(tetramino->position.x);
    //        break;
    //    }
}


