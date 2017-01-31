/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * @brief	Exercice 2 : Enigme
 * @file	exercice2.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 255

/*
	Main funcion
 */
int main()
{
	// Main row
	int mainRow[255] = {3,4};
	// Intermediate row for computation
	int interRow[255];
	// Desired number of rows
	int desiredRowNumber = 10;
	// Initial element quantity in the main row
	int rowQuantity = 2;
	// Intermediate row current index
	int interRowCurrentIndex = 0;
	// Main row increment
	int mainRowIncrement = 0;
	// The value
	int value = 0;
	// The multiplicator
	int multiplicator = 0;
	// The element increment
	int elementIncrement = 0;

	//	Create the desired number of rows
	for(mainRowIncrement = 0;mainRowIncrement < desiredRowNumber;mainRowIncrement++)
	{
		// Initialise the multiplicator at 1
		multiplicator = 1;
		value = 0;
		interRowCurrentIndex = 0;
		// Browse the current row
		for(elementIncrement = 0;elementIncrement < rowQuantity;elementIncrement++)
		{
			// Print current element of the row
			printf("%d ", mainRow[elementIncrement]);
			// Save the value
			value = mainRow[elementIncrement];
			// If the next element has the same value, just increment the multiplicator
			if(value==mainRow[elementIncrement+1])
			{
				multiplicator++;
			}
			// Else, save the value and the multiplicator to the intermediate row and re-initialise the multiplicator at 1
			else
			{
				interRow[interRowCurrentIndex++]=multiplicator;
				interRow[interRowCurrentIndex++]=value;
				multiplicator=1;
			}
		}
		printf("\n");
		rowQuantity = interRowCurrentIndex;
		// Save the intermediate row into the main row
		for(elementIncrement = 0; elementIncrement < interRowCurrentIndex;elementIncrement++)
		{
			mainRow[elementIncrement] = interRow[elementIncrement];
		}
	}
	return 0;
}
