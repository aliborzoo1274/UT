#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_ARRAY 20
#define OUTPUT_FILE_ADDRESS "MyArray.txt"
char *array_producer()
{
    char *array = (char *)calloc(SIZE_OF_ARRAY, SIZE_OF_ARRAY * sizeof(char));
    for (int i = 0; i < 20; i++)
    {
        if (i % 2)
        {
            array[i] = (32);
        }
        else
        {
            array[i] = (65 + i / 2);
        }
    }
    return array;
}
int main()
{
    char *the_array = array_producer();
    FILE *output;
    output = fopen(OUTPUT_FILE_ADDRESS, "w");
    fwrite(the_array, 1, SIZE_OF_ARRAY, output);
    fclose(output);
    return 0;
}