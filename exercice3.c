/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * Exercice 3 : Irrégularité et période d'un quotient
 * @file	exercice3.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>

int findInArray(int valueToFind, int* array, int arraySize);

int main()
{
	int nominateur = 1;
	int denominateur = 7;
	int current_index = 0;
	int restes_array[denominateur];
	int quotients_array[denominateur];
	int inter_quotient = nominateur/denominateur;
	int inter_reste = nominateur%denominateur;
	int i = 0;
	int periodeTourvee = 0;
	int begin_periode_index = 0;
	int end_periode_index = 0;
	inter_reste*=10;
	/*
		Main loop
	 */
	while(!periodeTourvee && i<denominateur-1 && inter_reste != 0)
	{
		/*
			Do the divisions
		 */
		inter_quotient = inter_reste/denominateur;
		inter_reste = inter_reste%denominateur;
		/*
			Save in arrays
		 */
		restes_array[current_index] = inter_reste;
		quotients_array[current_index++] = inter_quotient;
		/*
			Search for the element in the array
		 */
		begin_periode_index = findInArray(inter_reste,restes_array,current_index-1);
		/*
			If the element has been found
		 */
		if(begin_periode_index != -1)
		{
			periodeTourvee = 1;
			end_periode_index = current_index-1;
		}
		inter_reste*=10;
		i++;
	}

	/*
		If there is a period
	 */
	if(periodeTourvee)
	{
		/*
			If there is an irregularity before the period
		 */
		if(begin_periode_index > 0)
		{
			printf("Irregularité : ");
			for(i = 0; i < begin_periode_index+1; i++)
			{
				printf("%d",quotients_array[i]);
			}
		}
		else
		{
			printf("Pas d'irrégularité");
		}
		printf(" ; Période ");
		for(i = begin_periode_index+1; i < end_periode_index+1;i++)
		{
			printf("%d", quotients_array[i]);
		}
		printf("\n");
	}
	/*
		If there is no irregularity
	 */
	else
	{
		printf("Irrégularité : ");
		for(i = 0; i < current_index;i++)
		{
			printf("%d",quotients_array[i]);
		}
		printf(" ; Pas de période\n");
	}

	return 0;
}


/**
 * @brief	Find a value in array
 * @param[in]	valueToFind		The value to find
 * @param[in]	array			The arrays
 * @param[in]	arraySize		The array size
 */
int findInArray(int valueToFind, int* array, int arraySize)
{
	int i = 0;
	for(i = 0;i < arraySize; i++)
	{
		if(array[i] == valueToFind)
		{
			return i;
		}
	}
	return -1;
}
