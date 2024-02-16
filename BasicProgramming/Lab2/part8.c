#include <stdio.h>
int main(){

double r;
printf("Please enter the value of r:\n");
scanf("%lf", &r);
printf("The area is: %.4lf\n", (3.141593*r*r));  /*نمایش مساحت دایره*/
printf("The circumference is: %.4lf\n", (2*3.141592*r)); /*نمایش محیط دایره*/
return 0;




}