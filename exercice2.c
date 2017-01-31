/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * Exercice 2 : Enigme
 * @file	exercice1.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 255

int main()
{
	int line[255] = {3,4};
	int inter_line[255];
	int desiredLineNumber = 10;
	int line_quantity = 2;
	int inter_line_currentIndex = 0;
	int line_increment = 0;
	int value = 0;
	int multiplicator = 0;
	int number_increment = 0;
	/*
		Create the desired lines
	 */
	for(line_increment = 0;line_increment < desiredLineNumber;line_increment++)
	{
		multiplicator = 1;
		value = 0;
		inter_line_currentIndex = 0;
		/*
			Browse the current line
		 */
		for(number_increment = 0;number_increment < line_quantity;number_increment++)
		{
			/*
				Print current elements of the line
			 */
			printf("%d ", line[number_increment]);
			value = line[number_increment];
			/*
				If the next element has the same value, just increment the multiplicator
			 */
			if(value==line[number_increment+1])
			{
				multiplicator++;
			}
			/*
				Else, save the value and the multiplicator to the inter line
			 */
			else
			{
				inter_line[inter_line_currentIndex++]=multiplicator;
				inter_line[inter_line_currentIndex++]=value;
				multiplicator=1;
			}
		}
		printf("\n");
		line_quantity = inter_line_currentIndex;
		/*
			Save the inter line into the main line
		 */
		for(number_increment = 0; number_increment < inter_line_currentIndex;number_increment++)
		{
			line[number_increment] = inter_line[number_increment];
		}
	}
	return 0;
}
