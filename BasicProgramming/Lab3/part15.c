#include<stdio.h>
#include<stdlib.h>
int main(){
int seed = 810102410;
int n;
srand(seed);
int random_number = rand() % 100;
while (1){
    printf("Guess the number from 1 ro 100:");
    scanf("%d", &n);
    if (n<random_number){
        printf("Your number is smaller than random number!\n");
    }
    else if (n>random_number){
        printf("Your number is greater than random number!\n");
    }
    else if (n==random_number){
        printf("Congratulations!");
        break;
    }
}}