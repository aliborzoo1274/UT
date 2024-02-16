#include <stdio.h>

int test(int arr[][3])
{

}

int main() 
{
	int arr[3][3];
	FILE *inFile;
	char name[20];
	char family[20];

	inFile = fopen("..\\test.txt", "w");
	fprintf(inFile, " Hadi Moradi");
	fclose(inFile);
	inFile = fopen("test.txt", "r");
	fscanf(inFile, "%s %s", name, family);
}