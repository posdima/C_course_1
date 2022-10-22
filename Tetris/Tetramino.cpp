#include "Tetramino.h"
#include "Palette.h"
#include <curses.h>
#include <stdlib.h>
#include <memory.h>

/*Tetramino_Generator* CreateFigure(Tetramino )
{
    int randomFigure;
    randomFigure = rand() % 7 + 1;

    tetramino_generator->allFigures[(randomFigure)];

    return tetramino_generator;
};*/

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

Tetramino* CreateTetramino(int id)
{
    Tetramino* figure = new Tetramino;
    //    int randomFigure;
    //    randomFigure = rand() % 7 + 1;

    figure->position.x = 30;
    figure->position.y = 1;

    memcpy(figure->figure, figure_1, sizeof(figure_1));

    return figure;

    switch (id) {
    //    case 1: memcpy(figure->figure, figure_1, sizeof(figure_1));
    //        break;
    //    case 2: tetramino->figure_2;
    //        break;
    //    case 3: tetramino->figure_3;
    //        break;
    //    case 4: tetramino->figure_4;
    //        break;
    //    case 5: tetramino->figure_5;
    //        break;
    //    case 6: tetramino->figure_6;
    //        break;
    //    case 7: tetramino->figure_7;
    //        break;
    //    }
    }
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

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (tetramino->figure[i][j] > 0){
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

    ++(tetramino->position.y);

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


