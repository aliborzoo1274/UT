#include <stdio.h>

int* f( )
{
	//int a[10] = { 1,2,3 };
	int*a;
	a = (int *)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
		*(a + i) = i;

	return a;
}
int factorial(int n)
{
	if (n == 1) return 1;
	return n*factorial(n - 1);
}

int main() {

	int x = 10, y = 20;
	//int a[10] = { 1,2,3 };

	int *a=NULL;
	a = f();
	for (int i = 0; i < 10; i++)
		*(a + i) = i*10;

	x= factorial(3);

	free(a);
	a[0] = 30;
}