#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENTER '\n'
#define SPACE ' '
#define TRUE 1

typedef struct board
{
    char *name_board;
    int number_board;
    struct list *head_list; /*It refers to the first list of this board*/
    struct board *next_board;
} board;
typedef struct list
{
    char *name_list;
    int number_list;
    struct task *head_task; /*It refers to the first task of this list*/
    struct list *next_list;
} list;
typedef struct task
{
    char *name_task;
    int number_task;
    char priority[7];
    char deadline[11];
    struct task *next_task;
} task;

board *main_menu(board *head_board);
board *create_board(board *head_board);
board *delete_board(board *head_board);
list *add_list(board *board);
list *delete_list(board *board);
task *add_task(list *list);
task *edit_task(list *list);
task *delete_task(list *list);
board *move_task(board *board, list *list);
FILE *signup_account();
FILE *login_account();
void fprint(FILE *file, board *head_board);
int file_exists(char *filename);
char *dynamic_string_for_username();
char *dynamic_string_for_password();
char *dynamic_string_for_stored_username(FILE *file);
char *dynamic_string_for_stored_password(FILE *file);
char *dynamic_string_for_name();