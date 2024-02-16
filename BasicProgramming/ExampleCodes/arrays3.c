#include <stdio.h>
void Swap(int, int);
void Swap1(int*, int*);
int f( int a[], int size)
{
	int y = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
}

int main() {
	
	int x = 10, y = 20;
	int a[10] = { 1,2,3 };
	
	
	f(a, 10);

	return 0;
}

