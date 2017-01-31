/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * @brief	Exercice 3 : Irrégularité et période d'un quotient
 * @file	exercice3.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief	Browses through an array to find a desired value
 * @param  valueToFind The desired value
 * @param  array       The array to browse
 * @param  arraySize   The size of the array
 * @return             The index of the found value, or -1 if not found
 */
int findInArray(int valueToFind, int* array, int arraySize);

/*
	The main function
 */
int main()
{
	// The initial nominator and denominator
	int nominator = 1;
	int denominator = 7;
	// The currentIndex
	int currentIndex = 0;
	// Arrays for the computed rests and quotients
	int restsArray[denominator];
	int quotientsArray[denominator];
	// Intermediate variables for the computations
	int interQuotient = nominator/denominator;
	int interRest = nominator%denominator;
	// Generic index
	int i = 0;
	// Boolean variable to stop the loop
	int foundedPeriod = 0;
	// Indexes of the founded period
	int beginPeriodIndex = 0;
	int endPeriodIndex = 0;

	// Main loop that goes on until a period is found, or the rest equals 0, or ultimately it loops the value of the denominator
	while(!foundedPeriod && i<denominator-1 && interRest != 0)
	{
		interRest*=10;
		// Do the divisions
		interQuotient = interRest/denominator;
		interRest = interRest%denominator;
		// Save it in arrays
		restsArray[currentIndex] = interRest;
		quotientsArray[currentIndex++] = interQuotient;
		// Search for the rest in the array
		beginPeriodIndex = findInArray(interRest,restsArray,currentIndex-1);
		// If the element has been found
		if(beginPeriodIndex != -1)
		{
			// Stop the loop
			foundedPeriod = 1;
			// Save the end of the period
			endPeriodIndex = currentIndex-1;
		}
		i++;
	}

	// If a period has been found
	if(foundedPeriod)
	{
		// If there is an irregularity before the period
		if(beginPeriodIndex > 0)
		{
			printf("Irregularité : ");
			// Browse the quotients array before the period
			for(i = 0; i < beginPeriodIndex+1; i++)
			{
				printf("%d",quotientsArray[i]);
			}
		}
		else
		{
			printf("Pas d'irrégularité");
		}
		printf(" ; Période ");
		// Browse the quotients array for the range of the period
		for(i = beginPeriodIndex+1; i < endPeriodIndex+1;i++)
		{
			printf("%d", quotientsArray[i]);
		}
		printf("\n");
	}
	// If there is no period
	else
	{
		printf("Irrégularité : ");
		// Browse the whole quotients array
		for(i = 0; i < currentIndex;i++)
		{
			printf("%d",quotientsArray[i]);
		}
		printf(" ; Pas de période\n");
	}

	return 0;
}

int findInArray(int valueToFind, int* array, int arraySize)
{
	int i = 0;
	// Browse the array
	for(i = 0;i < arraySize; i++)
	{
		// If the value is found, return the index
		if(array[i] == valueToFind)
		{
			return i;
		}
	}
	// Ultimately, return -1
	return -1;
}
