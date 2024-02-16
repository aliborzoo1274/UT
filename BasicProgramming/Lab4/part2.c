#include <stdio.h>
int fact (int n){
int result=1;
for(int i=1;i<=n;i++){
    result*=i;
}
printf("%d\n", result);
return result;
}
int main(){
int n;
scanf("%d",&n);
int result = fact (n);
return 0;
}