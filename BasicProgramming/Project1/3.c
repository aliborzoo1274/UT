#include <stdio.h>
int main(){

char K;     /*کاراکتر مربوط به کلوین*/
char F;     /*کاراکتر مربوط به فارنهایت*/
char firstunit;     /*واحد اولیه وارد شونده توسط کاربر*/
float temp;         /*مقدار دما*/
scanf("%c", &firstunit);
scanf("%f", &temp);
if (firstunit=='K'){
    temp-=273.15;
    printf("%.2f", temp);
}
else if (firstunit=='F'){
    temp=(temp-32)/1.8;
    printf("%.2f", temp);
}
return 0;
}