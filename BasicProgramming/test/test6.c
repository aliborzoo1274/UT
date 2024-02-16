#include <stdio.h>
int main(){

int bitNum;
int inputValue;
scanf("%d", &inputValue);
int numberOfOnes=0;
for (bitNum=0; bitNum<16; bitNum++){
    if (inputValue & (1<<bitNum))
        numberOfOnes++;

}
    printf("%d\n", numberOfOnes);

}