/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 *
 * @file	mat_lib.c
 * @brief   Tools to manage matrices
 * @author  Nathanaël SPRIET
 * @date	31/01/2017
 */

#include "mat_lib.h"

void multiplication(Matrix* mat1, Matrix* mat2, Matrix* matRes)
{
	// If the dimensions match
	if(mat1->col_number == mat2->row_number)
	{
		int rowIncrement = 0;
		// Browse the rows of the result matrix
		for(rowIncrement = 0; rowIncrement < matRes->row_number; rowIncrement++)
		{
			int colIncrement = 0;
			// Browse the columns of the result matrix
			for(colIncrement = 0; colIncrement < matRes->col_number; colIncrement++)
			{
				int resCell = 0;
				int cellIncerement = 0;
				// Browse the current column of mat1 and the current row of mat2
				for(cellIncerement = 0; cellIncerement < mat1->col_number; cellIncerement++)
				{
					// Multiply mat1 and mat2 cells
					resCell += mat1->mainArray[rowIncrement][cellIncerement] * mat2->mainArray[cellIncerement][colIncrement];
				}
				// Put the result into the result matrix cell
				matRes->mainArray[rowIncrement][colIncrement] = resCell;
			}
		}
	}
	// If the dimensions does not match
	else
	{
		printf("Le nombre de colonnes de la matrice 1 n'est pas égal aux nombre de lignes de a matrice 2");
	}
}

int** generateMatrix(int row_number, int col_number, int value)
{
	// Initialise the randomisation
	srand(time(NULL));
	int rowIncrement = 0;
	int** array;
	// Memory allocation for the first level of pointer
	array = malloc(row_number*sizeof(int*));
	// Browse the rows of the array
	for(rowIncrement = 0; rowIncrement < row_number; rowIncrement++)
	{
		// Memory allocation for the second level of pointers
		array[rowIncrement] = malloc(col_number*sizeof(int));
		int colIncrement = 0;
		// Browse the columns of the array
		for(colIncrement = 0; colIncrement < col_number; colIncrement++)
		{
			// If the desired value is -1, randomise
			if(value == -1)
			{
				array[rowIncrement][colIncrement] = (rand()%(100-0))+0;
			}
			else
			{
				array[rowIncrement][colIncrement] = value;
			}
		}
	}
	return(array);
}

void printMatrix(Matrix* matrix)
{
	printf("\nMatrice : %d lignes %d colonnes :\n",matrix->row_number,matrix->col_number);
	int rowIncrement = 0;
	// Browse the rows of the matrix
	for(rowIncrement = 0; rowIncrement < matrix->row_number; rowIncrement++)
	{
		int colIncrement = 0;
		// Browse the columns of the matrix
		for(colIncrement = 0; colIncrement < matrix->col_number; colIncrement++)
		{
			printf(" %d ",matrix->mainArray[rowIncrement][colIncrement]);
		}
		printf("\n");
	}
}

void freeMatrix(Matrix* matrix)
{
	int rowIncrement = matrix->row_number;
	// Browse the rows of the  matrix
	for(rowIncrement = 0; rowIncrement < matrix->row_number; rowIncrement++)
	{
		// Free the second level of pointers
		free(matrix->mainArray[rowIncrement]);
	}
	// Free the first level of pointer
	free(matrix->mainArray);
}
