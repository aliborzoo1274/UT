#include<stdio.h>
int main() {
int x= 25;
int *ptr;
int **ptr2;
ptr = &x;
ptr2 = &ptr;
/* print the values of x , &x , *ptr , ptr , &ptr ,
**ptr2 , *ptr2 , ptr2 and compare them! */
printf("x=%d\n&x=%p\n*ptr=%d\nptr=%p\n&ptr=%p\n**ptr2=%d\n*ptr2=%p\nptr2=%p\n", x, &x, *ptr, ptr,
&ptr, **ptr2, *ptr2, ptr2);
*ptr = 2 * **ptr2;
/* Now check the values of x , *ptr , **ptr2 */
printf("\n\n*ptr=%d\n**ptr2=%d", *ptr, **ptr2);
return 0;
}