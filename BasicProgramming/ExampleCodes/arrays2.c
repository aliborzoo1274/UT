//////////////Testing C//////
// This program is writen to test C basics
// input: 
// output: 
// effect: 
/////////////////////////////

#include <stdio.h>
#define MAX_NUMS 10

float Average(int inputValues[MAX_NUMS]);

int main() {
	char name[20];
	int numbers[MAX_NUMS];
	char myName[] = "Hadi";
	float mean = Average(numbers);
	printf("Type First name and last name: ");
	scanf("%s %s", name, name + 5);//&name[5]);
	name[4] = ' ';
	printf("%s\n", myName);
	printf("%c %c %c %c\n", myName[0],myName[1],*(myName+2), *(myName+3));

	for(int i=0; i<5; i++)
		name[i] = myName[i];


}

float Average(int inputValues[MAX_NUMS]) 
{
	int index;
	int sum = 0;
	for (index = 0; index < MAX_NUMS; index++) 		
		sum = sum + inputValues[index];	
	return (((float)sum) / MAX_NUMS);
}

