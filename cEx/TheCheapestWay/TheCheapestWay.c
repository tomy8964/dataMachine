#include <stdio.h>
#include <stdlib.h>

// find min from 3way
int min3(int** arr,int i,int j,int row,int col)
{
	int x, y, z;
	if (i == 0)
	{
		x = arr[i + row - 1][j - 1];
		y = arr[i][j - 1];
		z = arr[i + 1][j - 1];
	}
	else if (i == (row-1))
	{
		x = arr[i - 1][j - 1];
		y = arr[i][j - 1];
		z = arr[i-row+1][j - 1];
	}
	else
	{
		x = arr[i - 1][j - 1];
		y = arr[i][j - 1];
		z = arr[i + 1][j - 1];
	}
	if (x < y)
	{
		if (x < z)
		{
			return 1;
		}
		else return 3;
	}
	else
	{
		if (y < z)
		{
			return 2;
		}
		else return 3;
	}
}

void main()
{
	//input row and col
	int row, col;
	printf("input row and column\n");
	scanf("%d %d", &row, &col);

	//make arr
	int **arr = malloc(sizeof(int *) * row);

	for (int i = 0; i < row; i++)
	{
		arr[i] = malloc(sizeof(int*) * col);
	}

	//input data
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	// make cost arr
	int** cost = malloc(sizeof(int*) * row);
	
	for (int i = 0; i < row; i++)
	{
		cost[i] = malloc(sizeof(int*) * col);
	}
	
	//input cost arr by min3
	for (int j = 0;j < col;j++)
	{
		for (int i = 0; i < row; i++)
		{
			//  first col
			if (j == 0)
			{
				cost[i][j] = arr[i][j];
			}
			// first col-1 is min
			else  if(1==min3(cost,i,j,row,col))
			{
				// present row is first row
				if (i == 0)
				{
					cost[i][j] = arr[i][j] + cost[i+row-1][j - 1];
				}
				else
				{
					cost[i][j] = arr[i][j] + cost[i - 1][j - 1];
				}
			}
			// second col-1 is min
			else  if (2 == min3(cost, i, j, row, col))
			{
					cost[i][j] = arr[i][j] + cost[i][j - 1];
			}
			// third col-1 is min
			else  if (3 == min3(cost, i, j, row, col))
			{
				// present row is last row
				if (i ==row-1)
				{
					cost[i][j] = arr[i][j] + cost[i-row+1][j - 1];
				}
				else
				{
					cost[i][j] = arr[i][j] + cost[i + 1][j - 1];
				}
			}
		}
	}

	// find low cost path's finish position
	int min = 1000;
	int idx = 0;
	for (int i = 0;i < row;i++)
	{
		if (min > cost[i][col-1])
		{
			min = cost[i][col-1];
			idx = i;
		}
	}

	// print low cost
	printf("%d\n",cost[idx][col-1]);
	
	// make path array
	int j = col;
	int k = 0;
	int* path = malloc(sizeof(int) * col);
	
	//input low cost path into path array
	for (int p = col; p >= 0; p--)
	{
		if (j == col)
		{
			path[k] = arr[idx][j-1];
			j--;
		}
		else if (1 == min3(cost, idx, j, row, col))
		{
			if (idx == 0)
			{
				path[k] = arr[idx +row- 1][j - 1];
				j--;
				idx = idx + row - 1;
			}
			else
			{
				path[k] = arr[idx - 1][j - 1];
				j--;
				idx = idx - 1;
			}
		}
		else if (2 == min3(cost, idx, j, row, col))
		{
			path[k] = arr[idx][j - 1];
			j--;
		}
		else if (3 == min3(cost, idx, j, row, col))
		{
			if (idx==row-1)
			{
				path[k] = arr[idx - row + 1][j - 1];
				idx = idx - row + 1;
				j--;
			}
			else
			{
				path[k] = arr[idx + 1][j - 1];
				idx = idx + 1;
				j--;
			}
		}
		k++;
	}

	// print low cost path
	for (int i = col-1;i >=0;i--)
	{
		printf("%d ", path[i]);
	}

	// free array
	for (int i = 0; i < row; i++)

	{
		free(arr[i]);
	}
	
	for (int i = 0; i < row; i++)

	{
		free(cost[i]);
	}
	
	free(path);
}