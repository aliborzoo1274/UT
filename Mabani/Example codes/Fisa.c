#include <stdio.h>
int main(){

float a,b,c;
printf("Please enter a, b, c:\n");
scanf("%f %f %f", &a, &b, &c);
if (a<=0 || b<=0 || c<=0){
    printf("ERROR, not for negetive numbers!");
}
else{
if (a>b){
    if(a>c){
        if (a*a==b*b+c*c){
            printf("The numbers ARE Fisa!");
        }
        else{
        printf("The numbers are NOT Fisa!");}
    }
    else {
    if (c*c==b*b+a*a){
    printf("The numbers ARE Fisa!");}
    else {
        printf("The numbers are NOT Fisa!");
    }}
}
    else {
    if(b>c){
        if(b*b==a*a+c*c){
            printf("The numbers ARE Fisa!");
        }
        else {
            printf("The numbers are NOT Fisa!");
        }

    }
    else{
        if (c*c==b*b+a*a)
        {
            printf("The numbers ARE Fisa!");
        }
        else{
            printf("The numbers are NOT Fisa!");
        }
        
    }
    
}}printf("\nPlease press enter to exit ...");
scanf("%c");
scanf("%c");}