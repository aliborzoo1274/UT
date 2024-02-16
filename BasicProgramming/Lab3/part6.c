#include <stdio.h>
int main(){
int num;
int result=0;
scanf("%d", &num);
do {
result=result+num;
scanf("%d", &num);
}
while(num!=0);
printf("%d\n", result);
return 0;
}