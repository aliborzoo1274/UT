#include <stdio.h>
int main(){
int n;
int value =1;
while (value){
scanf("%d",&n);
    if (n==0){
        value=0;
    }
    else{
        printf("%d\n",n);
    }
}
}