/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * @brief	Exercice 1 : Multiplication de matrices
 * @file	exercice1.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>
#include "mat_lib.h"

/*
	Main function
 */
int main()
{
	// First matrix initialisation
	int** matrixArray = NULL;
	Matrix mat1;
	mat1.row_number = 4;
	mat1.col_number = 3;
	matrixArray= generateMatrix(mat1.row_number,mat1.col_number,-1);
	mat1.mainArray = matrixArray;
	printMatrix(&mat1);

	// Second matrix initialisation
	Matrix mat2;
	mat2.row_number = 3;
	mat2.col_number = 4;
	matrixArray = generateMatrix(mat2.row_number,mat2.col_number,-1);
	mat2.mainArray = matrixArray;
	printMatrix(&mat2);

	// Result matrix initialisation
	Matrix matRes;
	matRes.col_number = mat1.row_number;
	matRes.row_number = mat2.col_number;
	matrixArray = generateMatrix(matRes.row_number,matRes.col_number,0);
	matRes.mainArray = matrixArray;
	printMatrix(&matRes);

	// Compute and print the multiplication
	multiplication(&mat1, &mat2, &matRes);
	printMatrix(&matRes);

	// Matrices freeing
	freeMatrix(&mat1);
	freeMatrix(&mat2);
	freeMatrix(&matRes);
	return 0;
}
