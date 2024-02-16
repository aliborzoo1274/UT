#include <stdio.h>
int main(){
    int i = 0;
    FILE *file = fopen("test.csv", "w");
    fprintf(file, "Hey nigga");
    scanf("%d", &i);
    return 0;
}