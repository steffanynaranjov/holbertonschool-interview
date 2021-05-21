#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid of integers
 * @grid: grid to print
 * Return: nothing
 */
static void print_grid(int grid[3][3])
{
	int i, j;  /**i: row index, j:column index*/

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 * Return: nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j; /**i: row index, j:column index*/

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		toppling_round(grid1);
	}
}

/**
 * is_unstable - checks if a 3x3 sandpile is unstable (contains a cell
 * holding more than three grains)
 * @grid: grid to check
 * Return: if the grid is unstable, a value different to zero is returned,
 * otherwise, the function will return zero
 */

int is_unstable(int grid[3][3])
{
	int i, j; /**i: row index, j:column index*/

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);

	return (0);
}


/**
 * toppling_round - topples a 3x3 unstable sandpile
 * @grid: grid to toppling
 * Return: nothing
 */

void toppling_round(int grid[3][3])
{
	int i, j; /**i: row index, j:column index*/
	int residue[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				grid[i][j] -= 4;
				if (j - 1 >= 0)
					residue[i][j - 1]++;
				if (j + 1 < 3)
					residue[i][j + 1]++;
				if (i - 1 >= 0)
					residue[i - 1][j]++;
				if (i + 1 < 3)
					residue[i + 1][j]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] += residue[i][j];
}