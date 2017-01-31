/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * Exercice 1 : Multiplication de matrices carrées
 * @file	exercice1.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */

#include <stdlib.h>
#include <stdio.h>
#include "mat_lib.h"


int main()
{
	int** matrixArray = NULL;
	Matrix mat1;
	mat1.row_number = 4;
	mat1.col_number = 3;
	matrixArray= generateMatrix(mat1.row_number,mat1.col_number,-1);
	mat1.main_array = matrixArray;
	printMatrix(&mat1);

	Matrix mat2;
	mat2.row_number = 3;
	mat2.col_number = 4;
	matrixArray = generateMatrix(mat2.row_number,mat2.col_number,-1);
	mat2.main_array = matrixArray;
	printMatrix(&mat2);

	Matrix mat_res;
	mat_res.col_number = mat1.row_number;
	mat_res.row_number = mat2.col_number;
	matrixArray = generateMatrix(mat_res.row_number,mat_res.col_number,0);
	mat_res.main_array = matrixArray;
	printMatrix(&mat_res);
	multiplication(&mat1, &mat2, &mat_res);
	printMatrix(&mat_res);

	freeMatrix(&mat1);
	freeMatrix(&mat2);
	freeMatrix(&mat_res);
	return 0;
}
