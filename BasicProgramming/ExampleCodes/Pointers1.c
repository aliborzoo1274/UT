#include <stdio.h>

int main() {
	
	int a[10] = { 1,2,3,4,5 };
	int *ptr = a;
	int *ptr1 = ptr+5;
	int x;
	scanf("%d", &x);
	ptr = (int*) malloc(10 * sizeof(int));
	if (ptr == NULL)
		return;
	for (int i = 0; i < 10; i++)
		*(ptr + i) = a[i];
	//ptr -= 100000;
	//printf("%d", sizeof(ptr));
	//a = ptr;
	free(ptr);
	return 0;
}