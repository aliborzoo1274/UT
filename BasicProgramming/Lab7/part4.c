#include <stdio.h>
#include <stdlib.h>
void main() {
int i;
char* s;
int* p = (int*)malloc(10*sizeof(int));
for(i=0;i<10;i++)
p[i] = i+48;
s=(char*)p; /*1*/
printf("\ns[0]=%c\ns[1]=%c\ns[4]=%c\ns[5]=%c\ns[36]=%c\ns[39]=%c\n",s[0], s[1], s[4], s[5], s[36], s[39]); /*2*/
for(i=0; i<40; i++) /*3*/
printf("%c", s[i]); /*4*/
printf("\n");
printf("p[0] is %d\n",*p);
free(p); 
free(s); /*5*/
}