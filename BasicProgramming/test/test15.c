#include <stdio.h>
int main(){
    char my_char = 'A';
    if (my_char < 95){
        my_char += 32;
    }
    printf("%c", my_char);
    return 0;
}