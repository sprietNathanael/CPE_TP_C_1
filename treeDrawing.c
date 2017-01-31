/**
* CPE-TP1 : Manipulation de Tableaux 1D et 2D
*
* @file	treeDrawing.c
* @brief   Tools to draw trees
* @author  Nathanaël SPRIET
* @date	31/01/2017
*/

#include "treeDrawing.h"
Tree generateTree(int foliage_heigth, int trunc_heigth, int trunc_width, int balls_number)
{
	srand(time(NULL));
	int global_height = foliage_heigth+trunc_heigth;
	int global_width = 1+((foliage_heigth-1)*2);
	int starsNumberToDraw = global_width * global_height;
	int ballsNumberToDraw = balls_number;
	if(ballsNumberToDraw > starsNumberToDraw)
	{
		ballsNumberToDraw = starsNumberToDraw;
	}
	if(global_width < trunc_width)
	{
		global_width = trunc_width;
	}
	Tree tree;
	tree.col_number = global_width;
	tree.row_number = global_height;
	tree.main_array = malloc(global_height*sizeof(char*));
	int row_increment= 0;
	int col_increment = 0;
	for(row_increment= 0; row_increment< global_height; row_increment++)
	{
		tree.main_array[row_increment] = malloc(global_width*sizeof(char));
		if(row_increment < foliage_heigth)
		{
			int starsToDraw = 1+(row_increment*2);
			int leftSpacesToDraw = (global_width - starsToDraw) / 2;
			for(col_increment = 0; col_increment < leftSpacesToDraw; col_increment++)
			{
				tree.main_array[row_increment][col_increment] = ' ';
			}
			for(; col_increment < leftSpacesToDraw+starsToDraw; col_increment++)
			{
				if(ballsNumberToDraw > 0)
				{
					if(ballsNumberToDraw == starsNumberToDraw)
					{
						tree.main_array[row_increment][col_increment] = 'O';
						ballsNumberToDraw--;
					}
					else
					{
						if((rand() % 2))
						{
							tree.main_array[row_increment][col_increment] = 'O';
							ballsNumberToDraw--;
						}
						else
						{
							tree.main_array[row_increment][col_increment] = '*';
						}
					}
				}
				else
				{
					tree.main_array[row_increment][col_increment] = '*';
				}
				starsNumberToDraw--;

			}
		}
		else
		{
			int pipeToDraw = trunc_width;
			int leftSpacesToDraw = (global_width - trunc_width) / 2;
			for(col_increment = 0; col_increment < leftSpacesToDraw; col_increment++)
			{
				tree.main_array[row_increment][col_increment] = ' ';
			}
			for(; col_increment < leftSpacesToDraw+pipeToDraw; col_increment++)
			{
				tree.main_array[row_increment][col_increment] = '|';
			}
		}
	}
	return tree;
}

void freeTree(Tree* treeToFree)
{
	int row_increment = treeToFree->row_number;
	/*
		Browse the lines of the treeToFree
	 */
	for(row_increment = 0; row_increment < treeToFree->row_number; row_increment++)
	{
		free(treeToFree->main_array[row_increment]);
	}
	free(treeToFree->main_array);
}

void drawTree(Tree* treeToDraw)
{
	int row_increment = 0;
	/*
		Browse the lines of the tree
	 */
	for(row_increment = 0; row_increment < treeToDraw->row_number; row_increment++)
	{
		int col_increment = 0;
		/*
			Browse the columns of the result tree
		 */
		for(col_increment = 0; col_increment < treeToDraw->col_number; col_increment++)
		{
			printf("%c",treeToDraw->main_array[row_increment][col_increment]);
		}
		printf("\n");
	}
}
