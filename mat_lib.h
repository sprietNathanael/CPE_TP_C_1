/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 *
 * @file	mat_lib.h
 * @brief   Tools to manage matrices
 * @author  Nathanaël SPRIET
 * @date	31/01/2017
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef MAT_LIB_H
#define MAT_LIB_H

/*
 ***************************** Structures *************************
*/

/**
 * @brief      A type defined over the Matrix structure
 */
typedef struct matrix Matrix;

/**
 * @brief      Represents a matrix
 */
struct matrix
{
    int** mainArray; /*!< The main array of arrays (the first array is the rows and the second, the columns) */
    int col_number;  /*!< The number of columns */
    int row_number;  /*!< The number of rows */
};

/*
 ***************************** Functions *************************
*/

/**
 * @brief	Multiplies two matrices : matRes = mat1 * mat2
 * @param[in]		mat1   	The first matrix
 * @param[in]		mat2   	The second matrix
 * @param[in, out]	matRes	The result matrix
 */
void multiplication(Matrix* mat1, Matrix* mat2, Matrix* matRes);

/**
 * @brief	Generate a random matrix
 * @param[in]		row_number	The row number
 * @param[in]		col_number	The column number
 * @param[in, out]	array		The result array
 * @param[in]		value		The desired value, -1 for random values
 */
int** generateMatrix(int row_number, int col_number, int value);

/**
 * @brief	Print a matrix
 * @param[in]	matrix		The matrix to print
 */
void printMatrix(Matrix* matrix);

/**
 * @brief	Free a matrix
 * @param[in]	matrix		The matrix to Free
 */
void freeMatrix(Matrix* matrix);
#endif
