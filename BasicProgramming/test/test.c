#include <stdio.h>
int main(){

int month;
printf("Please enter the month:\n");
scanf("%d", &month);
if (month==1 || month==2 || month==3 || month==4 || month==5 || month==6)
    printf("The month has 31 days!");
else if (month==7 || month==8 || month==9 || month==10 || month==11)
    printf("The month has 30 days!");
else if (month==12)
    printf("The month has 29 days!");
else
    printf("This isn't a month!");
}