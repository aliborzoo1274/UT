//////////////Testing C//////
// This program is writen to test C basics
// input: 
// output: 
// effect: 
/////////////////////////////

#include <stdio.h>
int calculateNumOfChairsInClass(int);

main()
{
	int numOfFullChairs = 0;
	int numOfClasses = 0;

	//Get the number of classes to check their full seats
	printf("enter number of classes=");
	scanf("%d", &numOfClasses);

	for (int j = 0; j < numOfClasses; j++) {
		numOfFullChairs += calculateNumOfChairsInClass(j + 1);
	}
	printf("Number of full chairs in all classes is: %d", numOfFullChairs);

}

//Calculate the number of Chair in a class
//Input: None
//output: Number of full chairs in the class

int calculateNumOfChairsInClass(int classNumber) {
	int numOfRows = 0;
	int row = 0;
	int numOfChairsInRow = sizeof(int) * 8;
	int numOfFullChairs = 0;

	printf("enter number of rows=");
	scanf("%d", &numOfRows);

	//until all rows are checked
	while (numOfRows) {
		printf("\nenter the row number=");
		scanf("%d", &row);
		//check if each seat if full or empty
		for (int i = 0; i < numOfChairsInRow; i++)
			if ((1 << i) &  row)
				numOfFullChairs++;
		numOfRows--;    //One row is processed
	}
	printf("Number of full chairs in class # %d is:%d\n", classNumber, numOfFullChairs);
	return numOfFullChairs;
}
