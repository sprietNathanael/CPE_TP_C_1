/**
* CPE-TP1 : Manipulation de Tableaux 1D et 2D
*
* @file	treeDrawing.c
* @brief   Tools to draw trees
* @author  Nathanaël SPRIET
* @date	31/01/2017
*/

#include "treeDrawing.h"

Tree generateTree(int foliageHeight, int truncHeight, int truncWidth, int ballsNumber)
{
	// Initialise the randomisation
	srand(time(NULL));
	// Compute the global height and width of the tree
	int globalHeight = foliageHeight+truncHeight;
	int globalWidth = 1+((foliageHeight-1)*2);
	// Compute the number of stars to draw
	int starsNumberToDraw = globalWidth * globalHeight;
	int ballsNumberToDraw = ballsNumber;
	// If there are more balls to draw than stars, just draw as much balls as there are stars
	if(ballsNumberToDraw > starsNumberToDraw)
	{
		ballsNumberToDraw = starsNumberToDraw;
	}
	// If the global width is lesser than the truncWidth, draw a trunc as large as the global width
	if(globalWidth < truncWidth)
	{
		truncWidth = globalWidth;
	}
	// Initialise the Tree structure
	Tree tree;
	tree.col_number = globalWidth;
	tree.row_number = globalHeight;
	// Memory allocation fot the first level of pointer
	tree.mainArray = malloc(globalHeight*sizeof(char*));
	// Main two increments variable
	int rowIncrement= 0;
	int colIncrement = 0;
	// Browse the rows of the array
	for(rowIncrement= 0; rowIncrement< globalHeight; rowIncrement++)
	{
		// Memory allocation for the second level of pointers
		tree.mainArray[rowIncrement] = malloc(globalWidth*sizeof(char));
		// Depending on the current row, if this is the foliage part
		if(rowIncrement < foliageHeight)
		{
			// Compute the number of stars and spaces to draw for this row
			int starsToDraw = 1+(rowIncrement*2);
			int leftSpacesToDraw = (globalWidth - starsToDraw) / 2;
			// Loop to create the left spaces
			for(colIncrement = 0; colIncrement < leftSpacesToDraw; colIncrement++)
			{
				tree.mainArray[rowIncrement][colIncrement] = ' ';
			}
			// Loop to create the stars
			for(; colIncrement < leftSpacesToDraw+starsToDraw; colIncrement++)
			{
				// If there are some balls to draw
				if(ballsNumberToDraw > 0)
				{
					// If there are as much balls to draw as stars left to be drawn just draw all stars as balls
					if(ballsNumberToDraw == starsNumberToDraw)
					{
						tree.mainArray[rowIncrement][colIncrement] = 'O';
						ballsNumberToDraw--;
					}
					else
					{
						// Choose if a star will be created or a ball by randomisation
						if((rand() % 2))
						{
							tree.mainArray[rowIncrement][colIncrement] = 'O';
							ballsNumberToDraw--;
						}
						else
						{
							tree.mainArray[rowIncrement][colIncrement] = '*';
						}
					}
				}
				// If there are no more balls to draw
				else
				{
					tree.mainArray[rowIncrement][colIncrement] = '*';
				}
				starsNumberToDraw--;
			}
		}
		// depending on the current row, if this is the trunk part
		else
		{
			// Compute the number of pipe and space to draw
			int pipeToDraw = truncWidth;
			int leftSpacesToDraw = (globalWidth - truncWidth) / 2;
			// Loop to create the spaces
			for(colIncrement = 0; colIncrement < leftSpacesToDraw; colIncrement++)
			{
				tree.mainArray[rowIncrement][colIncrement] = ' ';
			}
			// Loop to create the pipes
			for(; colIncrement < leftSpacesToDraw+pipeToDraw; colIncrement++)
			{
				tree.mainArray[rowIncrement][colIncrement] = '|';
			}
		}
	}
	return tree;
}

void freeTree(Tree* treeToFree)
{
	int rowIncrement = treeToFree->row_number;
	// Browse the rows of the treeToFree
	for(rowIncrement = 0; rowIncrement < treeToFree->row_number; rowIncrement++)
	{
		// Free the second level of pointers
		free(treeToFree->mainArray[rowIncrement]);
	}
	// Free the first level of pointer
	free(treeToFree->mainArray);
}

void drawTree(Tree* treeToDraw)
{
	int rowIncrement = 0;
	// Browse the rows of the tree
	for(rowIncrement = 0; rowIncrement < treeToDraw->row_number; rowIncrement++)
	{
		int colIncrement = 0;
		// Browse the columns of the tree
		for(colIncrement = 0; colIncrement < treeToDraw->col_number; colIncrement++)
		{
			printf("%c",treeToDraw->mainArray[rowIncrement][colIncrement]);
		}
		printf("\n");
	}
}
