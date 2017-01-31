/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 *
 * @file	treeDrawing.h
 * @brief   Tools to draw trees
 * @author  Nathanaël SPRIET
 * @date	31/01/2017
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef TREE_DRAWING_H
#define TREE_DRAWING_H

/*
 ***************************** Structures *************************
*/

/**
 * @brief      A type defined over the matrix structure
 */
typedef struct tree Tree;

/**
 * @brief      Represents a matrix
 */
struct tree
{
    char** main_array; /*!< The main array of arrays (the first array is the rows and the second, the columns) */
    int col_number;  /*!< The number of columns */
    int row_number;  /*!< The number of rows */
};

/*
 ***************************** Functions *************************
*/

Tree generateTree(int foliage_heigth, int trunc_heigth, int trunc_width, int balls_number);

void freeTree(Tree* treeToFree);

void drawTree(Tree* treeToDraw);


#endif
