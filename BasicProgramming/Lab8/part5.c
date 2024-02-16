#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE_ADDRESS "Input.txt"
int main()
{
    FILE *input = fopen(INPUT_FILE_ADDRESS, "a");
    char *text = " we love coding!! ";
    fprintf(input, "\n%s", text);
    return 0;
}