#include <stdio.h>
int main(){
    int ans1 = 6+5*2&3-4|5;
    int ans2 = 9-2<<3^4+13;
    int ans3 = 12>>1*3^5|7+4;
    printf("%d, %d, %d", ans1, ans2, ans3);
}