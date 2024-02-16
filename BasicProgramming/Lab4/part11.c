#include <stdio.h>
int main()
{
    int z = 4;
    if (z - 4)
    {
        int i = 1;
        z = z + i;
        printf("i=%d , z=%d\n", i, z);
    }
    else
    {
        int i = 0;
        z = i + 1;
        {
            int b = 1;
            z = b + 1;
            printf("b=%d , z=%d\n", b, z);
        }
        printf("i=%d , z=%d\n", i, z);
    }
    return 0;
}