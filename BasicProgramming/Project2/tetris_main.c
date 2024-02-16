#include "tetris_library.h"

int main()
{
    int playground[LENGTH][WIDTH];
    int i, j, a, b, score = 0;
    int random_number;
    char input;
    int shape0_counter;
    int shape2_counter;
    int shape3_counter;
    int speed;
    int GameOverFlag = ONE;

    while (GameOverFlag) /*This while loop continues until the game ends.*/
    {
        a = 0;
        b = WIDTH - 24;
        /*"a" and "b" are parameters for setting the dimensions of the
        playground and displaying the shapes on the playground.
        "a" is for setting the horizontal component and "b" is for setting the vertical component.*/
        shape0_counter = 0;
        shape2_counter = 0;
        shape3_counter = 0;
        speed = 500;
        random_number = random();
        for (a; a <= LENGTH - 2; a++) /*This "for" loop continues until the bottom of each shape is reached.*/
        {
            for (i = 0; i < LENGTH; i++)
            {
                for (j = 0; j < WIDTH; j++)
                {
                    if (playground[i][j] != '[' && playground[i][j] != ']')
                    {
                        playground[i][j] = ' ';
                    }
                }
            }
            playground[0][WIDTH - 8] = 's'; /*Initialization for fixed*/
            playground[0][WIDTH - 7] = 'c'; /*elements of the playground*/
            playground[0][WIDTH - 6] = 'o'; /*other than "score".*/
            playground[0][WIDTH - 5] = 'r';
            playground[0][WIDTH - 4] = 'e';
            playground[0][WIDTH - 3] = ':';
            playground[0][WIDTH - 2] = score;

            for (i = 0; i < LENGTH - 1; i++)
            {
                playground[i][WIDTH - 35] = '|';
            }
            for (i = 0; i < LENGTH - 1; i++)
            {
                playground[i][WIDTH - 10] = '|';
            }
            for (j = WIDTH - 35; j <= WIDTH - 10; j++)
            {
                playground[LENGTH - 1][j] = '-';
            }
            while (kbhit())
            {
                input = getch();

                if (input == ' ')
                {
                    if (shape0(random_number))
                    {
                        if (shape0_counter % 4 == 0)
                        {
                            if ((a >= 2) && playground[a - 2][b] == ' ' && playground[a - 1][b + 2] == ' ' &&
                                playground[a - 2][b + 1] == ' ' && playground[a - 1][b + 3] == ' ')
                            {
                                shape0_counter++;       /*By increasing one unit of the counter,*/
                            }                           /*the shape rotates 90 degrees clockwise.*/
                        }
                        else if (shape0_counter % 4 == 1)
                        {
                            if ((a >= 1) && playground[a - 1][b - 2] == ' ' && playground[a - 1][b - 1] == ' ')
                            {
                                shape0_counter++;
                            }
                        }
                        else if (shape0_counter % 4 == 2)
                        {
                            if ((a >= 2) && playground[a - 2][b] == ' ' && playground[a - 2][b + 1] == ' ')
                            {
                                shape0_counter++;
                            }
                        }
                        else if (shape0_counter % 4 == 3)
                        {
                            if (playground[a][b - 2] == ' ' && playground[a][b + 2] == ' ' &&
                                playground[a][b - 1] == ' ' && playground[a][b + 3] == ' ')
                            {
                                shape0_counter++;
                            }
                        }
                    }
                    else if (shape2(random_number))
                    {
                        if (shape2_counter % 2 == 0)
                        {
                            if ((a >= 2) && playground[a - 1][b + 2] == ' ' && playground[a - 2][b + 2] == ' ' &&
                                playground[a - 1][b + 3] == ' ' && playground[a - 2][b + 3] == ' ')
                            {
                                shape2_counter++;
                            }
                        }
                        else if (shape2_counter % 2 == 1)
                        {
                            if ((a >= 1) && playground[a][b + 2] == ' ' && playground[a - 1][b - 2] == ' ' &&
                                playground[a][b + 3] == ' ' && playground[a - 1][b - 1] == ' ')
                            {
                                shape2_counter++;
                            }
                        }
                    }
                    else if (shape3(random_number))
                    {
                        if (shape3_counter % 2 == 0)
                        {
                            if ((a >= 3) && playground[a - 1][b] == ' ' && playground[a - 2][b] && playground[a - 3][b] == ' ' &&
                                playground[a - 1][b + 1] == ' ' && playground[a - 2][b + 1] == ' ' && playground[a - 3][b + 1] == ' ')
                            {
                                shape3_counter++;
                            }
                        }
                        else if (shape3_counter % 2 == 1)
                        {
                            if (playground[a][b - 2] == ' ' && playground[a][b + 2] == ' ' && playground[a][b + 4] == ' ' &&
                                playground[a][b - 1] == ' ' && playground[a][b + 3] == ' ' && playground[a][b + 5] == ' ')
                            {
                                shape3_counter++;
                            }
                        }
                    }
                }

                else if (input == 's' || input == 'S')
                {
                    if (speed > 50)
                    {
                        speed -= 50;
                    }
                }
                else if (input == 'a' || input == 'A')
                {
                    if (shape0(random_number))
                    {
                        if (shape0_counter % 4 == 0)
                        {
                            if (((b - 2) > WIDTH - 34) && playground[a][b - 3] == ' ' && playground[a - 1][b - 1] == ' ')
                            {
                                b -= 2;
                            }
                        }
                        else if (shape0_counter % 4 == 1)
                        {
                            if ((b > WIDTH - 34) && playground[a][b - 1] == ' ' &&
                                playground[a - 1][b - 1] == ' ' && playground[a - 2][b - 1] == ' ')
                            {
                                b -= 2;
                            }
                        }
                        else if (shape0_counter % 4 == 2)
                        {
                            if (((b - 2) > WIDTH - 34) && playground[a][b - 1] == ' ' && playground[a - 1][b - 3] == ' ')
                            {
                                b -= 2;
                            }
                        }
                        else if (shape0_counter % 4 == 3)
                        {
                            if (((b - 2) > WIDTH - 34) && playground[a][b - 1] == ' ' &&
                                playground[a - 1][b - 3] == ' ' && playground[a - 2][b - 1] == ' ')
                            {
                                b -= 2;
                            }
                        }
                    }
                    else if (shape1(random_number))
                    {
                        if ((b > WIDTH - 34) && playground[a][b - 1] == ' ' && playground[a - 1][b - 1] == ' ')
                        {
                            b -= 2;
                        }
                    }
                    else if (shape2(random_number))
                    {
                        if (shape2_counter % 2 == 0)
                        {
                            if (((b - 2) > WIDTH - 34) && playground[a][b - 1] == ' ' && playground[a - 1][b - 3] == ' ')
                            {
                                b -= 2;
                            }
                        }
                        else if (shape2_counter % 2 == 1)
                        {
                            if ((b > WIDTH - 34) && playground[a][b - 1] == ' ' && playground[a - 1][b - 1] == ' ' &&
                                playground[a - 2][b + 1] == ' ')
                            {
                                b -= 2;
                            }
                        }
                    }
                    else if (shape3(random_number))
                    {
                        if (shape3_counter % 2 == 0)
                        {
                            if (((b - 2) > WIDTH - 34) && playground[a][b - 3] == ' ')
                            {
                                b -= 2;
                            }
                        }
                        else if (shape3_counter % 2 == 1)
                        {
                            if ((b > WIDTH - 34) && playground[a][b - 1] == ' ' && playground[a - 1][b - 1] == ' ' &&
                                playground[a - 2][b - 1] == ' ' && playground[a - 3][b - 1] == ' ')
                            {
                                b -= 2;
                            }
                        }
                    }
                }
                else if (input == 'd' || input == 'D')
                {
                    if (shape0(random_number))
                    {
                        if (shape0_counter % 4 == 0)
                        {
                            if (((b + 3) < WIDTH - 11) && playground[a][b + 4] == ' ' && playground[a - 1][b + 2] == ' ')
                            {
                                b += 2;
                            }
                        }
                        else if (shape0_counter % 4 == 1)
                        {
                            if (((b + 3) < WIDTH - 11) && playground[a][b + 2] == ' ' &&
                                playground[a - 1][b + 4] == ' ' && playground[a - 2][b + 2] == ' ')
                            {
                                b += 2;
                            }
                        }
                        else if (shape0_counter % 4 == 2)
                        {
                            if (((b + 3) < WIDTH - 11) && playground[a][b + 2] == ' ' && playground[a - 1][b + 4] == ' ')
                            {
                                b += 2;
                            }
                        }
                        else if (shape0_counter % 4 == 3)
                        {
                            if (((b + 1) < WIDTH - 11) && playground[a][b + 2] == ' ' &&
                                playground[a - 1][b + 2] == ' ' && playground[a - 2][b + 2] == ' ')
                            {
                                b += 2;
                            }
                        }
                    }
                    else if (shape1(random_number))
                    {
                        if (((b + 3) < WIDTH - 11) && playground[a][b + 4] == ' ' && playground[a - 1][b + 4] == ' ')
                        {
                            b += 2;
                        }
                    }
                    else if (shape2(random_number))
                    {
                        if (shape2_counter % 2 == 0)
                        {
                            if (((b + 3) < WIDTH - 11) && playground[a][b + 4] == ' ' && playground[a - 1][b + 2] == ' ')
                            {
                                b += 2;
                            }
                        }
                        else if (shape2_counter % 2 == 1)
                        {
                            if (((b + 3) < WIDTH - 11) && playground[a][b + 2] == ' ' && playground[a - 1][b + 4] == ' ' &&
                                playground[a - 2][b + 4] == ' ')
                            {
                                b += 2;
                            }
                        }
                    }
                    else if (shape3(random_number))
                    {
                        if (shape3_counter % 2 == 0)
                        {
                            if (((b + 5) < WIDTH - 11) && playground[a][b + 6] == ' ')
                            {
                                b += 2;
                            }
                        }
                        else if (shape3_counter % 2 == 1)
                        {
                            if (((b + 1) < WIDTH - 11) && playground[a][b + 2] == ' ' && playground[a - 1][b + 2] == ' ' &&
                                playground[a - 2][b + 2] == ' ' && playground[a - 3][b + 2] == ' ')
                            {
                                b += 2;
                            }
                        }
                    }
                }
                fflush(stdin);
            }
            if (shape0(random_number))
            {
                if (shape0_counter % 4 == 0)
                {
                    if (playground[a][b] == ' ' && playground[a][b - 2] == ' ' && playground[a][b + 2] == ' ' &&
                        playground[a][b + 1] == ' ' && playground[a][b - 1] == ' ' && playground[a][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a][b - 2] = playground[a][b + 2] = playground[a - 1][b] = '[';
                        playground[a][b + 1] = playground[a][b - 1] = playground[a][b + 3] = playground[a - 1][b + 1] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
                else if (shape0_counter % 4 == 1)
                {
                    if (playground[a][b] == ' ' && playground[a - 1][b + 2] == ' ' &&
                        playground[a][b + 1] == ' ' && playground[a - 1][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b] = playground[a - 2][b] = '[';
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
                else if (shape0_counter % 4 == 2)
                {
                    if (playground[a][b] == ' ' && playground[a - 1][b + 2] == ' ' && playground[a - 1][b - 2] == ' ' &&
                        playground[a][b + 1] == ' ' && playground[a - 1][b + 3] == ' ' && playground[a - 1][b - 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b - 2] = playground[a - 1][b] = '[';
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b - 1] = playground[a - 1][b + 1] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
                else if (shape0_counter % 4 == 3)
                {
                    if (playground[a][b] == ' ' && playground[a - 1][b - 2] == ' ' &&
                        playground[a][b + 1] == ' ' && playground[a - 1][b - 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b - 2] = playground[a - 1][b] = playground[a - 2][b] = '[';
                        playground[a][b + 1] = playground[a - 1][b - 1] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (shape1(random_number))
            {
                if (playground[a][b] == ' ' && playground[a][b + 2] == ' ' && playground[a][b + 1] == ' ' &&
                    playground[a][b + 3] == ' ')
                {
                    playground[a][b] = playground[a][b + 2] = playground[a - 1][b] = playground[a - 1][b + 2] = '[';
                    playground[a][b + 1] = playground[a][b + 3] = playground[a - 1][b + 1] = playground[a - 1][b + 3] = ']';
                }
                else
                {
                    break;
                }
            }
            else if (shape2(random_number))
            {
                if (shape2_counter % 2 == 0)
                {
                    if (a == 0)
                    {
                        if (playground[a][b] == ' ' && playground[a][b + 2] == ' ' &&
                            playground[a][b + 1] == ' ' && playground[a][b + 3] == ' ')
                        {
                            playground[a][b] = playground[a][b + 2] = playground[a - 1][b] = playground[a - 1][b - 2] = '[';
                            playground[a][b + 1] = playground[a][b + 3] = playground[a - 1][b + 1] = playground[a - 1][b - 1] = ']';
                        }
                        else
                        {
                            break;
                        }
                    }

                    else
                    {
                        if (playground[a][b] == ' ' && playground[a][b + 2] == ' ' && playground[a - 1][b - 2] == ' ' &&
                            playground[a][b + 1] == ' ' && playground[a][b + 3] == ' ' && playground[a - 1][b - 1] == ' ')
                        {
                            playground[a][b] = playground[a][b + 2] = playground[a - 1][b] = playground[a - 1][b - 2] = '[';
                            playground[a][b + 1] = playground[a][b + 3] = playground[a - 1][b + 1] = playground[a - 1][b - 1] = ']';
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (shape2_counter % 2 == 1)
                {
                    if (playground[a][b] == ' ' && playground[a - 1][b + 2] == ' ' && playground[a][b + 1] == ' ' && playground[a - 1][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b] = playground[a - 2][b + 2] = '[';
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b + 1] = playground[a - 2][b + 3] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (shape3(random_number))
            {
                if (shape3_counter % 2 == 0)
                {
                    if (playground[a][b] == ' ' && playground[a][b - 2] == ' ' && playground[a][b + 2] == ' ' &&
                        playground[a][b + 4] == ' ' && playground[a][b - 1] == ' ' && playground[a][b + 1] == ' ' &&
                        playground[a][b + 3] == ' ' && playground[a][b + 5] == ' ')
                    {
                        playground[a][b] = playground[a][b - 2] = playground[a][b + 2] = playground[a][b + 4] = '[';
                        playground[a][b - 1] = playground[a][b + 1] = playground[a][b + 3] = playground[a][b + 5] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
                else if (shape3_counter % 2 == 1)
                {
                    if (playground[a][b] == ' ' && playground[a][b + 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b] = playground[a - 2][b] = playground[a - 3][b] = '[';
                        playground[a][b + 1] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = playground[a - 3][b + 1] = ']';
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for (j = 0; j < WIDTH - 2; j++)
            {
                printf("%c", playground[0][j]);
            }
            printf("%d", playground[0][WIDTH - 2]);
            printf("\n");
            for (i = 1; i < LENGTH; i++)
            {
                for (j = 0; j < WIDTH; j++)
                {
                    printf("%c", playground[i][j]);
                }
                printf("\n");
            }
            if (shape0(random_number))
            {
                if (shape0_counter % 4 == 0)
                {
                    if (playground[a + 1][b] == ' ' && playground[a + 1][b - 2] == ' ' && playground[a + 1][b + 2] == ' ' &&
                        playground[a + 1][b + 1] == ' ' && playground[a + 1][b - 1] == ' ' && playground[a + 1][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a][b - 2] = playground[a][b + 2] = playground[a - 1][b] = ZERO;
                        playground[a][b + 1] = playground[a][b - 1] = playground[a][b + 3] = playground[a - 1][b + 1] = ONE;
                    }
                }
                else if (shape0_counter % 4 == 1)
                {
                    if (playground[a + 1][b] == ' ' && playground[a][b + 2] == ' ' &&
                        playground[a + 1][b + 1] == ' ' && playground[a][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b] = playground[a - 2][b] = ZERO;
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = ONE;
                    }
                }
                else if (shape0_counter % 4 == 2)
                {
                    if (playground[a + 1][b] == ' ' && playground[a][b + 2] == ' ' && playground[a][b - 2] == ' ' &&
                        playground[a + 1][b + 1] == ' ' && playground[a][b + 3] == ' ' && playground[a][b - 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b - 2] = playground[a - 1][b] = ZERO;
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b - 1] = playground[a - 1][b + 1] = ONE;
                    }
                }
                else if (shape0_counter % 4 == 3)
                {
                    if (playground[a + 1][b] == ' ' && playground[a][b - 2] == ' ' &&
                        playground[a + 1][b + 1] == ' ' && playground[a][b - 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b - 2] = playground[a - 1][b] = playground[a - 2][b] = ZERO;
                        playground[a][b + 1] = playground[a - 1][b - 1] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = ONE;
                    }
                }
            }

            /*In this step, we convert the shapes that move downwards to 0 and 1,
            so that these moving shapes can be deleted from the terminal in the stage of erasing the page.*/

            else if (shape1(random_number))
            {
                if (playground[a + 1][b] == ' ' && playground[a + 1][b + 2] == ' ' && playground[a + 1][b + 1] == ' ' &&
                    playground[a + 1][b + 3] == ' ')
                {
                    playground[a][b] = playground[a][b + 2] = playground[a - 1][b] = playground[a - 1][b + 2] = ZERO;
                    playground[a][b + 1] = playground[a][b + 3] = playground[a - 1][b + 1] = playground[a - 1][b + 3] = ONE;
                }
            }
            else if (shape2(random_number))
            {
                if (shape2_counter % 2 == 0)
                {
                    if (playground[a + 1][b] == ' ' && playground[a + 1][b + 2] == ' ' && playground[a + 1][b + 1] == ' ' &&
                        playground[a + 1][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a][b + 2] = playground[a - 1][b] = playground[a - 1][b - 2] = ZERO;
                        playground[a][b + 1] = playground[a][b + 3] = playground[a - 1][b + 1] = playground[a - 1][b - 1] = ONE;
                    }
                }
                else if (shape2_counter % 2 == 1)
                {
                    if (playground[a + 1][b] == ' ' && playground[a][b + 2] == ' ' && playground[a + 1][b + 1] == ' ' && playground[a][b + 3] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b + 2] = playground[a - 1][b] = playground[a - 2][b + 2] = ZERO;
                        playground[a][b + 1] = playground[a - 1][b + 3] = playground[a - 1][b + 1] = playground[a - 2][b + 3] = ONE;
                    }
                }
            }
            else if (shape3(random_number))
            {
                if (shape3_counter % 2 == 0)
                {
                    if (playground[a + 1][b] == ' ' && playground[a + 1][b - 2] == ' ' && playground[a + 1][b + 2] == ' ' &&
                        playground[a + 1][b + 4] == ' ' && playground[a + 1][b - 1] == ' ' && playground[a + 1][b + 1] == ' ' &&
                        playground[a + 1][b + 3] == ' ' && playground[a + 1][b + 5] == ' ')
                    {
                        playground[a][b] = playground[a][b - 2] = playground[a][b + 2] = playground[a][b + 4] = ZERO;
                        playground[a][b - 1] = playground[a][b + 1] = playground[a][b + 3] = playground[a][b + 5] = ONE;
                    }
                }
                else if (shape3_counter % 2 == 1)
                {
                    if (playground[a + 1][b] == ' ' && playground[a + 1][b + 1] == ' ')
                    {
                        playground[a][b] = playground[a - 1][b] = playground[a - 2][b] = playground[a - 3][b] = ZERO;
                        playground[a][b + 1] = playground[a - 1][b + 1] = playground[a - 2][b + 1] = playground[a - 3][b + 1] = ONE;
                    }
                }
            }
            Sleep(speed);
            system("cls");
        }
        a -= 1; /*Here, "a", which was related to determining the horizontal component, is reduced by one unit,
                because it has increased by one unit in the last round of the loop.
                Now here, "a" points to the last row.*/

        while (playground[a][WIDTH - 34] == '[' && playground[a][WIDTH - 33] == ']' &&
               playground[a][WIDTH - 32] == '[' && playground[a][WIDTH - 31] == ']' &&
               playground[a][WIDTH - 30] == '[' && playground[a][WIDTH - 29] == ']' &&
               playground[a][WIDTH - 28] == '[' && playground[a][WIDTH - 27] == ']' &&
               playground[a][WIDTH - 26] == '[' && playground[a][WIDTH - 25] == ']' &&
               playground[a][WIDTH - 24] == '[' && playground[a][WIDTH - 23] == ']' &&
               playground[a][WIDTH - 22] == '[' && playground[a][WIDTH - 21] == ']' &&
               playground[a][WIDTH - 20] == '[' && playground[a][WIDTH - 19] == ']' &&
               playground[a][WIDTH - 18] == '[' && playground[a][WIDTH - 17] == ']' &&
               playground[a][WIDTH - 16] == '[' && playground[a][WIDTH - 15] == ']' &&
               playground[a][WIDTH - 14] == '[' && playground[a][WIDTH - 13] == ']' &&
               playground[a][WIDTH - 12] == '[' && playground[a][WIDTH - 11] == ']')
        {
            score += INCREASE_POINTS;
            for (j = WIDTH - 34; j < WIDTH - 10; j++)
            {
                playground[a][j] = ' ';
            }
            for (i = LENGTH - 2; i >= 0; i--)
            {
                for (j = WIDTH - 11; j >= WIDTH - 34; j--)
                {
                    if (playground[i][j] == '[' || playground[i][j] == ']')
                    {
                        playground[i + 1][j] = playground[i][j];
                        playground[i][j] = ' ';
                    }
                }
            }
        }
        for (j = WIDTH - 34; j < WIDTH - 10; j++)
        {
            if (playground[0][j] == '[' || playground[0][j] == ']')
            {
                GameOverFlag = ZERO;
                break;
            }
        }
    }
    for (j = WIDTH - 8; j <= WIDTH - 2; j++)
    {
        playground[0][j] = ' ';
    }
    for (i = 0; i < LENGTH; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%c", playground[i][j]);
        }
        printf("\n");
    }
    printf("\t     GAME OVER\n");
    printf("\t   Your score: %d\n\n\n", score);
    printf("Press any key to exit...");
    getch();
    return 0;
}