#include<stdio.h>
int main(){
int x=1 , y=0 , z=4;
int a =--x && y || (z>>=2);
printf("x= %d\ny= %d\nz= %d\na= %d\n",x,y,z,a);
return 0;
}