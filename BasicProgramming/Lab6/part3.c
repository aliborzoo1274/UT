#include <stdio.h>
int main()
{
    float x, y;
    float *ptr;
    x = 12.34;
    ptr = &x;
    y = *ptr;
    printf("y= %f\n", y);
    return 0;
}