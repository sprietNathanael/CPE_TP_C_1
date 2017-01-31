/**
 * CPE-TP1 : Manipulation de Tableaux 1D et 2D
 * @brief	Exercice 4 : Algorithmique, dessin d'un sapin
 * @file	exercice4.c
 * @author	Nathanaël SPRIET
 * @date	31/01/2017
 */
#include <stdlib.h>
#include <stdio.h>
#include "treeDrawing.h"

/*
	The main function
 */
int main()
{
	Tree myTree = generateTree(6,2,3,85);
	drawTree(&myTree);
	freeTree(&myTree);

	return 0;
}
