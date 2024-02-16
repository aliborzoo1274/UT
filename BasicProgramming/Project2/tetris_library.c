#include "tetris_library.h"

int random()
{
    /*
        This function generates a random number between 0 and 3.
        It can be used to determine which shape should fall.
    */
    srand(clock() + time(NULL) + M_PI);
    return rand() % 4;
}
int shape0(int random_number)
{
    if (random_number == 0)
    {
        return 1;        /*                           []          */
    }                    /*                 shape0: [][][]        */
    else
    {
        return 0;
    }
}
int shape1(int random_number)
{
    if (random_number == 1)
    {
        return 1;        /*                           [][]          */
    }                    /*                 shape1:   [][]        */
    else
    {
        return 0;
    }
}
int shape2(int random_number)
{
    if (random_number == 2)
    {
        return 1;        /*                           [][]          */
    }                    /*                 shape2:     [][]        */
    else
    {
        return 0;
    }
}
int shape3(int random_number)
{
    if (random_number == 3)
    {
        return 1;
    }                    /*                 shape3: [][][][]        */
    else
    {
        return 0;
    }
}