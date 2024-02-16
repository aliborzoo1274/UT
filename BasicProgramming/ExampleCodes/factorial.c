//////////////Testing C//////
// This program is writen to test C basics
// input: 
// output: 
// effect: 
/////////////////////////////

#include <stdio.h>

int factorial(int);
int recursiveFactorial(int n);

main()
{
	int n = 5;
	int fact = 1;

	printf("factorial %d = %d", n, factorial(n));
	printf("factorial %d = %d", n, recursiveFactorial(n));

}

int factorial(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

int recursiveFactorial(int n)
{
	if (n == 1)
		return 1;
	return n*recursiveFactorial(n - 1);
}