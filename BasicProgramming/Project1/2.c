#include <stdio.h>
int main (){

int decimal;    /*عدد به صورت دسیمال*/
int binary=0;   /*عدد به صورت باینری*/
int power=1;    /*این عدد به صورت مضارب ده خواهد بود و در نشان دادن به صورت باینری کمک خواهد کرد*/
scanf("%d", &decimal);
while (decimal>0){
    if (decimal%2==1){
        decimal/=2;
        binary+=power;  /*پاور با اضافه شدن به باینری آن را تشکیل خواهد داد*/
        power*=10;
    }
    else if (decimal%2==0){
        decimal/=2;
        power*=10;  /*پاور را گسترش میدهیم اما به باینری اضافه نمیکنیم زیرا عدد زوج بوده است*/
    }
}
printf ("%d", binary);
return 0;
}