/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 *
 * @file	mat_lib.c
 * @brief   Tools to manage matrix
 * @author  Nathanaël SPRIET
 * @date	31/01/2017
 */

#include "mat_lib.h"

void multiplication(Matrix* mat1, Matrix* mat2, Matrix* mat_res)
{
	/*
		If the dimensions match
	 */
	if(mat1->col_number == mat2->row_number)
	{
		int row_incerment = 0;
		/*
			Browse the lines of the result matrix
		 */
		for(row_incerment = 0; row_incerment < mat_res->row_number; row_incerment++)
		{
			int col_increment = 0;
			/*
				Browse the columns of the result matrix
			 */
			for(col_increment = 0; col_increment < mat_res->col_number; col_increment++)
			{
				int res_cell = 0;
				int cell_incerement = 0;
				/*
					Browse the current column of the mat1 and the current row of the mat2
				 */
				for(cell_incerement = 0; cell_incerement < mat1->col_number; cell_incerement++)
				{
					/*
						Multiply mat1 and mat2 cells
					 */
					res_cell += mat1->main_array[row_incerment][cell_incerement] * mat2->main_array[cell_incerement][col_increment];
				}
				/*
					Put the result into the result matrix cell
				 */
				mat_res->main_array[row_incerment][col_increment] = res_cell;
			}
		}
	}
	/*
		If the dimensions does not match
	 */
	else
	{
		printf("Le nombre de colonnes de la matrice 1 n'est pas égal aux nombre de lignes de a matrice 2");
	}
}


int** generateMatrix(int row_number, int col_number, int value)
{
	int row_incerment = 0;
	srand(time(NULL));
	int** array;
	array = malloc(row_number*sizeof(int*));
	/*
		Browse the lines of the result matrix
	 */
	for(row_incerment = 0; row_incerment < row_number; row_incerment++)
	{
		array[row_incerment] = malloc(col_number*sizeof(int));
		int col_increment = 0;
		/*
			Browse the columns of the result matrix
		 */
		for(col_increment = 0; col_increment < col_number; col_increment++)
		{
			if(value == -1)
			{
				array[row_incerment][col_increment] = (rand()%(100-0))+0;
			}
			else
			{
				array[row_incerment][col_increment] = value;
			}
		}
	}
	return(array);
}

void printMatrix(Matrix* matrix)
{
	printf("\nMatrice : %d lignes %d colonnes :\n",matrix->row_number,matrix->col_number);
	int row_incerment = 0;
	/*
		Browse the lines of the result matrix
	 */
	for(row_incerment = 0; row_incerment < matrix->row_number; row_incerment++)
	{
		int col_increment = 0;
		/*
			Browse the columns of the result matrix
		 */
		for(col_increment = 0; col_increment < matrix->col_number; col_increment++)
		{
			printf(" %d ",matrix->main_array[row_incerment][col_increment]);
		}
		printf("\n");
	}
}

void freeMatrix(Matrix* matrix)
{
	int row_incerment = matrix->row_number;
	/*
		Browse the lines of the result matrix
	 */
	for(row_incerment = 0; row_incerment < matrix->row_number; row_incerment++)
	{
		free(matrix->main_array[row_incerment]);
	}
	free(matrix->main_array);
}
