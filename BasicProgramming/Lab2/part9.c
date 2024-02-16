#include <stdio.h>
#define PI 3.141593
int main(){

double r;
printf("Please enter the value of r:\n");
scanf("%lf", &r);
printf("The area is: %.4lf\n", (PI*r*r));  /*نمایش مساحت دایره*/
printf("The circumference is: %.4lf\n", (2*PI*r)); /*نمایش محیط دایره*/
return 0;




}