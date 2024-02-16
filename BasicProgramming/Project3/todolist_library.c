#include "todolist_library.h"

board *main_menu(board *head_board)
{
    int exit = 0;
    int choice;
    int counter;
    int first_flag;
    int second_flag;
    int third_flag;
    board *current_board;
    board *previous_board = NULL;
    list *current_list;
    list *previous_list = NULL;
    task *current_task;
    while (!exit) /*A loop of boards options*/ /*second while*/
    {
        printf("\n1. View Boards\n");
        printf("2. Create New Board\n");
        printf("3. Delete Board\n");
        printf("4. Back\n");
        scanf("%d", &choice);
        system("cls");
        counter = 0;                                   /*To show invalid input message*/
        first_flag = 0;                                /*To have Back when we are viewing boards and lists*/
        second_flag = 1;                               /*To have Back when we are in a board*/
        third_flag = 1;                                /*To have Back when we are in a list*/
        switch (choice) /*A switch of boards options*/ /*first switch*/
        {
        case 1:
            while (TRUE) /*A loop of view boards*/ /*third while*/
            {
                counter = 0;
                first_flag = 0;
                second_flag = 1;
                third_flag = 1;
                printf("\nAvailable Boards:\n");
                if (head_board == NULL)
                {
                    printf("\nThere is no board to show.\n");
                    break;
                }
                else
                {
                    current_board = head_board;
                    while (current_board != NULL)
                    {
                        printf("%d. %s\n", current_board->number_board, current_board->name_board);
                        previous_board = current_board; /*To have Back*/
                        current_board = current_board->next_board;
                    }
                    printf("%d. Back\n", previous_board->number_board + 1);
                    while (current_board == NULL) /*Will continiue until user enters invalid inputs*/
                    {
                        if (counter > 0)
                        {
                            printf("\nInvalid input; Please try again.\n");
                            printf("\nAvailable Boards:\n");
                            current_board = head_board;
                            while (current_board != NULL)
                            {
                                printf("%d. %s\n", current_board->number_board, current_board->name_board);
                                previous_board = current_board; /*To have Back*/
                                current_board = current_board->next_board;
                            }
                            printf("%d. Back\n", previous_board->number_board + 1);
                        }
                        counter++;
                        int number;
                        scanf("%d", &number);
                        system("cls");
                        if (number == previous_board->number_board + 1)
                        {
                            first_flag = 1;
                            break;
                        }
                        else
                        {
                            current_board = head_board;
                            while (current_board != NULL && current_board->number_board != number)
                            {
                                current_board = current_board->next_board;
                            } /*current_board will be the board which we want enter*/
                        }
                    }
                    if (first_flag)
                    {
                        break; /*To go back to second while*/
                    }
                    while (second_flag) /*A loop of lists options*/ /*fourth while*/
                    {
                        printf("\nBoard: %s\n", current_board->name_board);
                        printf("1. View Lists\n");
                        printf("2. Create New List\n");
                        printf("3. Delete List\n");
                        printf("4. Back\n");
                        scanf("%d", &choice);
                        system("cls");
                        counter = 0;
                        first_flag = 0;
                        switch (choice) /*A switch of lists options*/ /*second switch*/
                        {
                        case 1:
                            while (TRUE) /*A loop of view lists*/ /*fifth while*/
                            {
                                counter = 0;
                                first_flag = 0;
                                second_flag = 1;
                                third_flag = 1;
                                printf("\nLists in '%s' Board:\n", current_board->name_board);
                                if (current_board->head_list == NULL)
                                {
                                    printf("\nThere is no list to show.\n");
                                    break;
                                }
                                else
                                {
                                    current_list = current_board->head_list;
                                    while (current_list != NULL)
                                    {
                                        printf("%d. %s\n", current_list->number_list, current_list->name_list);
                                        previous_list = current_list; /*To have Back*/
                                        current_list = current_list->next_list;
                                    }
                                    printf("%d. Back\n", previous_list->number_list + 1);
                                    while (current_list == NULL) /*Will continiue until user enters invalid inputs*/
                                    {
                                        if (counter > 0)
                                        {
                                            printf("\nInvalid input; Please try again.\n");
                                            printf("\nLists in '%s' Board:\n", current_board->name_board);
                                            current_list = current_board->head_list;
                                            while (current_list != NULL)
                                            {
                                                printf("%d. %s\n", current_list->number_list, current_list->name_list);
                                                previous_list = current_list; /*To have Back*/
                                                current_list = current_list->next_list;
                                            }
                                            printf("%d. Back\n", previous_list->number_list + 1);
                                        }
                                        counter++;
                                        int number;
                                        scanf("%d", &number);
                                        system("cls");
                                        if (number == previous_list->number_list + 1)
                                        {
                                            first_flag = 1;
                                            break;
                                        }
                                        else
                                        {
                                            current_list = current_board->head_list;
                                            while (current_list != NULL && current_list->number_list != number)
                                            {
                                                current_list = current_list->next_list;
                                            } /*current_list will be the list which we want enter*/
                                        }
                                    }
                                    if (first_flag)
                                    {
                                        break;
                                    }
                                    while (third_flag) /*A loop of tasks options*/ /*sixth while*/
                                    {
                                        printf("\nList: %s\n\n", current_list->name_list);
                                        printf("Tasks:\n");
                                        if (current_list->head_task == NULL)
                                        {
                                            printf("\nThere is no task to show.\n");
                                        }
                                        else
                                        {
                                            current_task = current_list->head_task;
                                            while (current_task != NULL)
                                            {
                                                printf("%d. %s, Priority: %s, Deadline: %s\n", current_task->number_task,
                                                       current_task->name_task, current_task->priority, current_task->deadline);
                                                current_task = current_task->next_task;
                                            }
                                        }
                                        printf("\nOptions:\n");
                                        printf("1. Add Task\n");
                                        printf("2. Edit Task\n");
                                        printf("3. Delete Task\n");
                                        printf("4. Move Task to Another List\n");
                                        printf("5. Back\n");
                                        scanf("%d", &choice);
                                        system("cls");
                                        switch (choice) /*A switch of tasks options*/ /*third switch*/
                                        {
                                        case 1:
                                            current_list->head_task = add_task(current_list);
                                            break;
                                        case 2:
                                            current_list->head_task = edit_task(current_list);
                                            break;
                                        case 3:
                                            current_list->head_task = delete_task(current_list);
                                            break;
                                        case 4:
                                            current_board = move_task(current_board, current_list);
                                            break;
                                        case 5:
                                            third_flag = 0;
                                            break;
                                        default:
                                            printf("\nInvalid input; Please try again.\n");
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            current_board->head_list = add_list(current_board);
                            break;
                        case 3:
                            current_board->head_list = delete_list(current_board);
                            break;
                        case 4:
                            second_flag = 0;
                            break;
                        default:
                            printf("\nInvalid input; Please try again.\n");
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            head_board = create_board(head_board);
            break;
        case 3:
            head_board = delete_board(head_board);
            break;
        case 4:
            exit = 1;
            break;
        default:
            printf("\nInvalid input; Please try again.\n");
            break;
        }
    }
    return head_board;
}
board *create_board(board *head_board)
{
    board *new_board = (board *)malloc(sizeof(board));
    printf("\nCreate New Board:\n");
    printf("Enter Board Name:\n");
    char *name_board = dynamic_string_for_name();
    new_board->name_board = (char *)malloc((strlen(name_board) + 1) * sizeof(char));
    strcpy(new_board->name_board, name_board); /*Allocating 'name_board' to 'new_board->name_board'*/
    new_board->next_board = NULL;
    new_board->head_list = NULL;
    if (head_board == NULL)
    {
        head_board = new_board;
        head_board->number_board = 1;
    }
    else
    {
        board *current_board = head_board;
        while (current_board->next_board != NULL)
        {
            current_board = current_board->next_board;
        }
        new_board->number_board = current_board->number_board + 1;
        current_board->next_board = new_board;
    }
    printf("\nSuccessfully Created!\n");
    return head_board;
}
board *delete_board(board *head_board)
{
    int number;
    board *current_board;
    if (head_board == NULL)
    {
        printf("\nThere is no board to delete.\n");
        return head_board;
    }
    printf("\nDelete Board:\n");
    printf("Which board do you want to delete?\n");
    current_board = head_board;
    while (current_board != NULL)
    {
        printf("%d. %s\n", current_board->number_board, current_board->name_board);
        current_board = current_board->next_board; /*Printing boards*/
    }
    scanf("%d", &number);
    system("cls");
    if (number == 1)
    {
        current_board = head_board;
        head_board = head_board->next_board;
        free(current_board);
        current_board = head_board;
        while (current_board != NULL)
        {
            current_board->number_board--;
            current_board = current_board->next_board;
        }
        printf("\nSuccessfully Deleted!\n");
        return head_board;
    }
    else
    {
        current_board = head_board;
        board *previous_board = NULL;
        while (current_board != NULL && current_board->number_board != number)
        {
            previous_board = current_board;
            current_board = current_board->next_board;
        }
        if (current_board == NULL)
        {
            printf("\nThere is no board with this number.\n");
            return head_board;
        }
        else
        {
            previous_board->next_board = current_board->next_board;
            while (current_board != NULL)
            {
                current_board->number_board--;
                current_board = current_board->next_board;
            }
            printf("\nSuccessfully Deleted!\n");
            return head_board;
        }
    }
}
list *add_list(board *board)
{
    list *new_list = (list *)malloc(sizeof(list));
    printf("\nAdd new list to '%s':\n", board->name_board);
    printf("What's the name of the new list?\n");
    char *name_list = dynamic_string_for_name();
    new_list->name_list = (char *)malloc((strlen(name_list) + 1) * sizeof(char));
    strcpy(new_list->name_list, name_list); /*Allocating 'name_list' to 'new_list->name_list'*/
    new_list->next_list = NULL;
    new_list->head_task = NULL;
    if (board->head_list == NULL)
    {
        board->head_list = new_list;
        board->head_list->number_list = 1;
    }
    else
    {
        list *current_list = board->head_list;
        while (current_list->next_list != NULL)
        {
            current_list = current_list->next_list;
        }
        new_list->number_list = current_list->number_list + 1;
        current_list->next_list = new_list;
    }
    printf("\nSuccessfully Added!\n");
    return board->head_list;
}
list *delete_list(board *board)
{
    int number;
    list *current_list;
    if (board->head_list == NULL)
    {
        printf("\nThere is no list to delete.\n");
        return board->head_list;
    }
    printf("\nDelete list from '%s':\n", board->name_board);
    printf("Which list do you want to delete?\n");
    current_list = board->head_list;
    while (current_list != NULL)
    {
        printf("%d. %s\n", current_list->number_list, current_list->name_list);
        current_list = current_list->next_list; /*Printing lists*/
    }
    scanf("%d", &number);
    system("cls");
    if (number == 1)
    {
        current_list = board->head_list;
        board->head_list = board->head_list->next_list;
        free(current_list);
        current_list = board->head_list;
        while (current_list != NULL)
        {
            current_list->number_list--;
            current_list = current_list->next_list;
        }
        printf("\nSuccessfully Deleted!\n");
        return board->head_list;
    }
    else
    {
        current_list = board->head_list;
        list *previous_list = NULL;
        while (current_list != NULL && current_list->number_list != number)
        {
            previous_list = current_list;
            current_list = current_list->next_list;
        }
        if (current_list == NULL)
        {
            printf("\nThere is no list with this number.\n");
            return board->head_list;
        }
        else
        {
            previous_list->next_list = current_list->next_list;
            while (current_list != NULL)
            {
                current_list->number_list--;
                current_list = current_list->next_list;
            }
            printf("\nSuccessfully Deleted!\n");
            return board->head_list;
        }
    }
}
task *add_task(list *list)
{
    task *new_task = (task *)malloc(sizeof(task));
    printf("\nAdd New Task:\n");
    printf("\nEnter Task Name:\n");
    char *name_task = dynamic_string_for_name();
    new_task->name_task = (char *)malloc((strlen(name_task) + 1) * sizeof(char));
    strcpy(new_task->name_task, name_task); /*Allocating 'name_task' to 'new_task->name_task'*/
    printf("\nEnter Priority (Low/Medium/High):\n");
    scanf("%s", new_task->priority);
    system("cls");
    printf("\nEnter Deadline (YYYY-MM-DD):\n");
    scanf("%s", new_task->deadline);
    system("cls");
    new_task->next_task = NULL;
    if (list->head_task == NULL)
    {
        list->head_task = new_task;
        list->head_task->number_task = 1;
    }
    else
    {
        task *current_task = list->head_task;
        while (current_task->next_task != NULL)
        {
            current_task = current_task->next_task;
        }
        new_task->number_task = current_task->number_task + 1;
        current_task->next_task = new_task;
    }
    printf("\nSuccessfully Added!\n");
    return list->head_task;
}
task *edit_task(list *list)
{
    int number;
    if (list->head_task == NULL)
    {
        printf("\nThere is no task to edit.\n");
        return list->head_task;
    }
    printf("\nEdit Task:\n");
    printf("\nWhich task do you want to edit?\n");
    scanf("%d", &number);
    system("cls");
    task *current_task = list->head_task;
    while (current_task != NULL && current_task->number_task != number)
    {
        current_task = current_task->next_task;
    }
    if (current_task == NULL)
    {
        printf("\nThere is no task with this number.\n");
        return list->head_task;
    }
    else
    {
        printf("\nEdit Task Name:\n");
        char *name_task = dynamic_string_for_name();
        current_task->name_task = (char *)malloc((strlen(name_task) + 1) * sizeof(char));
        strcpy(current_task->name_task, name_task); /*Allocating 'name_task' to 'currenr_task->name_task'*/
        printf("\nEdit Priority (Low/Medium/High):\n");
        scanf("%s", current_task->priority);
        system("cls");
        printf("\nEdit Deadline (YYYY-MM-DD):\n");
        scanf("%s", current_task->deadline);
        system("cls");
        printf("\nSuccessfully Edited!\n");
        return list->head_task;
    }
}
task *delete_task(list *list)
{
    int number;
    task *current_task;
    task *previous_task;
    if (list->head_task == NULL)
    {
        printf("\nThere is no task to delete.\n");
        return list->head_task;
    }
    printf("\nDelete Task:\n");
    printf("\nWhich task do you want to delete?\n");
    current_task = list->head_task;
    while (current_task != NULL)
    {
        printf("%d. %s\n", current_task->number_task, current_task->name_task);
        current_task = current_task->next_task; /*Printing tasks*/
    }
    scanf("%d", &number);
    system("cls");
    if (number == 1)
    {
        current_task = list->head_task;
        list->head_task = list->head_task->next_task;
        free(current_task);
        current_task = list->head_task;
        while (current_task != NULL)
        {
            current_task->number_task--;
            current_task = current_task->next_task;
        }
        printf("\nSuccessfully Deleted!\n");
        return list->head_task;
    }
    else
    {
        current_task = list->head_task;
        previous_task = NULL;
        while (current_task != NULL && current_task->number_task != number)
        {
            previous_task = current_task;
            current_task = current_task->next_task;
        }
        if (current_task == NULL)
        {
            printf("\nThere is no task with this number.\n");
            return list->head_task;
        }
        else
        {
            previous_task->next_task = current_task->next_task;
            while (current_task != NULL)
            {
                current_task->number_task--;
                current_task = current_task->next_task;
            }
            printf("\nSuccessfully Deleted!\n");
            return list->head_task;
        }
    }
}
board *move_task(board *board, list *list)
{
    int number_list;
    int number_task;
    struct list *target_list;
    struct list *current_list;
    task *current_task;
    task *previous_task;
    task *target_task;
    if (list->head_task == NULL)
    {
        printf("\nThere is no task to move.\n");
        return board;
    }
    printf("\nMove task to another list:\n");
    printf("\nWhich task do you want to move?\n");
    current_task = list->head_task;
    while (current_task != NULL)
    {
        printf("%d. %s\n", current_task->number_task, current_task->name_task);
        current_task = current_task->next_task; /*Printing tasks*/
    }
    scanf("%d", &number_task);
    system("cls");
    current_task = list->head_task; /*Checking invalid input*/
    while (current_task != NULL && current_task->number_task != number_task)
    {
        current_task = current_task->next_task;
    }
    if (current_task == NULL)
    {
        printf("\nThere is no task with this number.\n");
        return board;
    }
    printf("\nWhich list would you like to move the task to?\n");
    current_list = board->head_list;
    while (current_list != NULL)
    {
        printf("%d. %s\n", current_list->number_list, current_list->name_list);
        current_list = current_list->next_list; /*Printing lists*/
    }
    scanf("%d", &number_list);
    system("cls");
    target_list = board->head_list; /*Checking invalid input*/
    while (target_list != NULL && target_list->number_list != number_list)
    {
        target_list = target_list->next_list;
    }
    if (target_list == NULL)
    {
        printf("\nThere is no list with this number.\n");
        return board;
    }
    if (number_task == 1)
    {
        target_task = (task *)malloc(sizeof(task));
        target_task->name_task = (char *)malloc((strlen(list->head_task->name_task) + 1) * sizeof(char));
        strcpy(target_task->name_task, list->head_task->name_task); /*Creating target_task*/
        strcpy(target_task->priority, list->head_task->priority);
        strcpy(target_task->deadline, list->head_task->deadline);
        target_task->next_task = NULL;
        current_task = list->head_task; /*Removing the task from list*/
        list->head_task = list->head_task->next_task;
        free(current_task);
        current_task = list->head_task;
        while (current_task != NULL)
        {
            current_task->number_task--;
            current_task = current_task->next_task;
        }
    }
    else
    {
        target_task = (task *)malloc(sizeof(task));
        target_task->name_task = (char *)malloc((strlen(current_task->name_task) + 1) * sizeof(char));
        strcpy(target_task->name_task, current_task->name_task); /*Creating target_task*/
        strcpy(target_task->priority, current_task->priority);
        strcpy(target_task->deadline, current_task->deadline);
        target_task->next_task = NULL;
        previous_task->next_task = current_task->next_task; /*Removing the task from list*/
        while (current_task != NULL)
        {
            current_task->number_task--;
            current_task = current_task->next_task;
        }
    }
    if (target_list->head_task == NULL)
    {
        target_list->head_task = target_task;
        target_list->head_task->number_task = 1;
    }
    else
    {
        current_task = target_list->head_task;
        while (current_task->next_task != NULL)
        {
            current_task = current_task->next_task;
        }
        target_task->number_task = current_task->number_task + 1;
        current_task->next_task = target_task;
    }
    printf("\nSuccessfully Moved!\n");
    return board;
}
FILE *signup_account() /*A function to create new account*/
{
    FILE *file;
    char *username = dynamic_string_for_username();
    char *password = dynamic_string_for_password();
    char *filename = (char *)malloc((strlen(username) + 4) * sizeof(char));
    sprintf(filename, "%s.csv", username); /*Creating a .csv file*/
    if (file_exists(filename))
    {
        printf("\nThis username has been already used. Please choose another username.\n\n");
        free(username);
        free(password);
        free(filename);
        return NULL;
    }
    else
    {
        file = fopen(filename, "w");                                     /*Create a new file*/
        fprintf(file, "username:%s\npassword:%s\n", username, password); /*Writing username and password in the file*/
        free(username);
        free(password);
        free(filename);
        printf("\nYour account has been successfully created!\n");
        return file;
    }
}
FILE *login_account()
{
    FILE *file;
    char *username = dynamic_string_for_username();
    char *password = dynamic_string_for_password();
    char *filename = (char *)malloc((strlen(username) + 4) * sizeof(char));
    sprintf(filename, "%s.csv", username); /*Creating a .csv file*/
    if (file_exists(filename))
    {
        file = fopen(filename, "r"); /*Opening the available file*/
        char *stored_username = dynamic_string_for_stored_username(file);
        char *stored_password = dynamic_string_for_stored_password(file);
        /*Reading username and password from the file*/
        fclose(file);
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0)
        {
            file = fopen(filename, "w");
            fprintf(file, "username:%s\npassword:%s\n", username, password); /*Writing username and password in the file*/
            free(username);
            free(password);
            free(stored_username);
            free(stored_password);
            free(filename);
            printf("\nYou have successfully logged in!\n");
            return file;
        }
        else
        {
            printf("\nYour username or password is wrong!\n\n");
            free(username);
            free(password);
            free(stored_username);
            free(stored_password);
            free(filename);
            return NULL;
        }
    }
    else
    {
        printf("\nThis username doesn't exist. Please create a new account.\n\n");
        free(username);
        free(password);
        free(filename);
        return NULL;
    }
    free(username);
    free(password);
    free(filename);
    free(file);
}
void fprint(FILE *file, board *head_board)
{
    board *current_board;
    list *current_list;
    task *current_task;
    fprintf(file, "\nInformation:\n");
    current_board = head_board;
    while (current_board != NULL)
    {
        fprintf(file, "Board: %d. %s\n", current_board->number_board, current_board->name_board);
        current_list = current_board->head_list;
        while (current_list != NULL)
        {
            fprintf(file, "List: %d. %s\n", current_list->number_list, current_list->name_list);
            current_task = current_list->head_task;
            while (current_task != NULL)
            {
                fprintf(file, "Task: %d. %s, Priority: %s, Deadline: %s\n", current_task->number_task,
                        current_task->name_task, current_task->priority, current_task->deadline);
                current_task = current_task->next_task;
            }
            current_list = current_list->next_list;
        }
        current_board = current_board->next_board;
    }
    fclose(file);
}
int file_exists(char *filename) /*A function to check file existence*/
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return 0; /*File doesn't exist*/
    }
    else
    {
        fclose(file);
        return 1; /*File exists*/
    }
}
char *dynamic_string_for_username()
{
    fflush(stdin);
    char buffer_input;
    int i = 0;
    char *username = (char *)malloc(sizeof(char));
    while (EOF != (buffer_input = fgetc(stdin)) && buffer_input != SPACE)
    {
        *(username + i) = buffer_input;
        i++;
        username = (char *)realloc(username, ((i + 1) * sizeof(char)));
    }
    *(username + i) = '\0'; /*A dynamic string to get username*/
    return username;
}
char *dynamic_string_for_password()
{
    char buffer_input;
    int i = 0;
    char *password = (char *)malloc(sizeof(char));
    while (EOF != (buffer_input = fgetc(stdin)) && buffer_input != ENTER)
    {
        *(password + i) = buffer_input;
        i++;
        password = (char *)realloc(password, ((i + 1) * sizeof(char)));
    }
    *(password + i) = '\0'; /*A dynamic string to get password*/
    system("cls");
    return password;
}
char *dynamic_string_for_stored_username(FILE *file)
{
    fflush(stdin);
    fseek(file, 9, SEEK_SET);
    char buffer_input;
    int i = 0;
    char *stored_username = (char *)malloc(sizeof(char));
    while (EOF != (buffer_input = fgetc(file)) && buffer_input != ENTER)
    {
        *(stored_username + i) = buffer_input;
        i++;
        stored_username = (char *)realloc(stored_username, ((i + 1) * sizeof(char)));
    }
    *(stored_username + i) = '\0'; /*A dynamic string to get stored_username*/
    return stored_username;
}
char *dynamic_string_for_stored_password(FILE *file)
{
    fseek(file, 9, SEEK_CUR);
    char buffer_input;
    int i = 0;
    char *stored_password = (char *)malloc(sizeof(char));
    while (EOF != (buffer_input = fgetc(file)) && buffer_input != ENTER)
    {
        *(stored_password + i) = buffer_input;
        i++;
        stored_password = (char *)realloc(stored_password, ((i + 1) * sizeof(char)));
    }
    *(stored_password + i) = '\0'; /*A dynamic string to get stored_password*/
    return stored_password;
}
char *dynamic_string_for_name()
{
    fflush(stdin);
    char buffer_input;
    int i = 0;
    char *name = (char *)malloc(sizeof(char));
    while (EOF != (buffer_input = fgetc(stdin)) && buffer_input != ENTER)
    {
        *(name + i) = buffer_input;
        i++;
        name = (char *)realloc(name, ((i + 1) * sizeof(char)));
    }
    *(name + i) = '\0'; /*A dynamic string to get name*/
    system("cls");
    return name;
}