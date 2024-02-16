#include <stdio.h>
#include <stdlib.h>
int main() {
int* p = (int*)malloc(10* sizeof(int));
int i;
printf("P = 0x%p\n", p);
printf("****************\n");
for (i = 0; i < 10; i++){
printf("p%d = %d\n",i, *(p+i));
}
free(p);
printf("****************\n");
printf("P = 0x%p\n", p);
printf("\n%d", p[15]);
return 0;
}