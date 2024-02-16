#include <stdio.h>
int main(){


int input;
scanf("%d",&input);
int sum=0;
int outer;
int inner;
for (outer=1; outer<=input; outer++){
    for (inner=0; inner < outer; inner++){
        sum += inner;
    }

}
    printf("%d", sum);

}