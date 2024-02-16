#include <stdio.h>
int main(){

double Pi=0.0;
int terms;
scanf("%d", &terms);
int count;
for (count=0; count<terms; count++){
    if(count%2==0)
    Pi=Pi+4.0/(2*count+1);
    else
    Pi=Pi-4.0/(2*count+1);}

printf("%.30lf",Pi);

}