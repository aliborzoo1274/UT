#include <stdio.h>

long fib(long n);
int main(){

long n;
scanf("%ld", &n);
printf("%ld", fib(n));
}
long fib(long n){
if (n <= 2)
return 1;
return fib(n - 1) + fib (n - 2);
}