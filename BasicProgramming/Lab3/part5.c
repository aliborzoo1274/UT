#include <stdio.h>
int main(){
int num;
int result=0;
scanf("%d", &num);
while(num!=0){
result=result+num;
scanf("%d", &num);
}
printf("%d\n", result);
return 0;
}