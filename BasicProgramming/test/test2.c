#include <stdio.h>
int main(){

int month;
printf("Please enter the month:\n");
scanf("%d", &month);
switch (month){

    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
printf("The month has 31 days!");
break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
printf("The month has 30 days!");
break;
    case 12:
printf("The month has 29 days!");
break;        
default:
printf("This isn't a month!");
break;
}
}