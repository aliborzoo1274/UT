#include <stdio.h>
int main () {

int x;
scanf("%d", &x);
while (x!=0){
    if (x%10==7){
        printf("1");
        break;
    }
    else{
    x=x/10;
    if (x==0){
        printf("0");
        break;
    }
    else if (x%10==7){
        printf("1");
        break;
    }}
    
}
}






