//////////////Testing C//////
// This program is writen to test C basics
// input: 
// output: 
// effect: 
/////////////////////////////

#include <stdio.h>


int main()
{
	int x[10] = { 1 };				//array initialization x[0]=1, the rest zero
	char c[40] = "Hadi Moradi";		//string initialization
	c[13] = 'a';					//updating part of the string
	c[14] = 'b';					//note that a and b are after the NULL character of Hadi Moradi
	for (int i = 0; i < 16; i++)	//for the first 16 characters in the string
		if (c[i] > 95 )				//if the character is lower case
			c[i] = c[i] - 32;		//make it upper case
	printf("%s\n", c);
	printf("%s\n", &c[13]);			//print from the 14th character
	printf("%c\n", c[13]);			//print the 14th character

	for (int i = 0;i < 10; i++) {	//get an array of integers
		printf("\nx[%d] = ", i);
		scanf("%d", &x[i]);
	}
	for (int i = 9;i >= 0; i--) {	//print the array from the last to the first.
		printf("\nx[%d] = %d", i, x[i]);
		
	}

}

