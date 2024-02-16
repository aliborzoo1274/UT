#include <stdio.h>
int function (int n){
if(n%2 == 0){
return 1;
}
printf("ODD (FARD)!\n");
}
int main(){
int a;
scanf("%d",&a);
if (function(a)){
printf("EVEN (ZOJ)!\n");
}
return 0;
}