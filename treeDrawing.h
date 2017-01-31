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
 * @brief      A type defined over the tree structure
 */
typedef struct tree Tree;

/**
 * @brief      Represents a tree
 */
struct tree
{
    char** mainArray; /*!< The main array of arrays (the first array is the rows and the second, the columns) */
    int col_number;  /*!< The number of columns */
    int row_number;  /*!< The number of rows */
};

/*
 ***************************** Functions *************************
*/

/**
 * @brief	Generate a character tree
 * @param[in]	foliageHeight	The foliage desired Height
 * @param[in]	truncHeight		The trunc desired Height
 * @param[in]	truncWidth		The trunc desired width
 * @param[in]	ballsNumber		The desired number of christmas balls
 */
Tree generateTree(int foliageHeight, int truncHeight, int truncWidth, int ballsNumber);

/**
 * @brief	Free a tree
 * @param[in]	treeToFree		The tree to Free
 */
void freeTree(Tree* treeToFree);

/**
 * @brief	Draw a character tree
 * @param[in]	treeToDraw		The tree to draw
 */
void drawTree(Tree* treeToDraw);


#endif
