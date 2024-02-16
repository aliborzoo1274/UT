#include "todolist_library.h"

int main()
{
    FILE *file;
    board *head_board = NULL;
    int choice;
    int exit = 0;
    while (!exit) /*A loop of signup and login options*/ /*first while*/
    {
        printf("\n1. signup <username> <password>\n");
        printf("2. login <username> <password>\n");
        printf("3. exit and save\n");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            file = signup_account();
            if (file != NULL)
            {
                head_board = main_menu(head_board);
            }
            break;
        case 2:
            file = login_account();
            if (file != NULL)
            {
                head_board = main_menu(head_board);
            }
            break;
        case 3:
            exit = 1;
            break;
        default:
            printf("\nInvalid input; Please try again.\n");
            break;
        }
    }
    fprint(file, head_board);
    return 0;
}