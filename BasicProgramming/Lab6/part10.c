#include <stdio.h>
#define SIZE 10
void function(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] = arr[i] % 2;
    }
}
int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    function(arr);
    for (int j = 0; j < SIZE; j++)
    {
        printf("%d ", arr[j]);
    } // printing the result
    return 0;
}