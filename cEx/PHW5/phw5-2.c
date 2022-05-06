#include <stdio.h>
#include<stdlib.h>
#define RMAX 100
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

//table definition
struct table
{
	int num[3];
}table1[15],table2[10],table3[15],table4[10];

//create table
void create_table()
{
	// ramdom value by time
	srand(time(NULL));
	for (int i = 0;i < 15;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			int random_no = 1 + (int)rand() % RMAX;
			table1[i].num[j] = random_no;
			table3[i].num[j] = table1[i].num[j];
		}
	}
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			int random_no = 1 + (int)rand() % RMAX;
			table2[i].num[j] = random_no;
			table4[i].num[j] = table2[i].num[j];
		}
	}

}

//print table
void print_table(struct table table1[], struct table table2[])
{
	printf("table1\n");
	for (int i = 0;i < 15;i++)
	{
		printf("%2d | ", i + 1);
		for (int j = 0;j < 3;j++)
		{
			printf("%3d  ", table1[i].num[j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
	printf("table2\n");
	for (int i = 0;i < 10;i++)
	{
		printf("%2d | ", i + 1);
		for (int j = 0;j < 3;j++)
		{
			printf("%3d  ", table2[i].num[j]);
		}

		printf("\n");
	}
	printf("--------------------------\n");
}

//duplex sort
void sort1(struct table table[], int col,int row)
{
	int left = 0;
	int right = row - 1;
	int minIdx = -1, maxIdx = -1, min = 1000, max = -1;
	struct table tmp = {0,0,0};

	while (left < right) {

		for (int i = left; i <= right; i++) {

			if (max < table[i].num[col]) {

				maxIdx = i;

				max = table[i].num[col];

			}
			if (min > table[i].num[col]) {

				minIdx = i;

				min = table[i].num[col];

			}

		}
		if (maxIdx == left && minIdx == right)
		{
			SWAP(table[right], table[maxIdx], tmp);
		}
		else
		{
			SWAP(table[right], table[maxIdx], tmp);
			SWAP(table[left], table[minIdx], tmp);
		}

		min = 1000;

		max = -1;

		left++;

		right--;

	}
}

//quick sort
void sort2(struct table table[], int col, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int pivot = left;
	int i = pivot + 1;
	int j = right;
	struct table temp = { 0,0,0 };
	 
	while (i <= j)
	{
		while (i <= right && table[i].num[col] <= table[pivot].num[col])
		{
			i++;
		}
		while (j > left && table[j].num[col] >= table[pivot].num[col])
		{
			j--;
		}

		if (i > j)
		{
			SWAP(table[j], table[pivot], temp);
		}
		else
		{
			SWAP(table[i], table[pivot], temp);
		}
	}

	sort2(table, col, left, j - 1);
	sort2(table, col, j+1, right);
}

//merge join
void join(struct table table1[], struct table table2[], int col1, int col2, int val)
{
	
	for (int i = 0; i < 15; i++)
	{
		if (table1[i].num[col1] == 55)
		{
			for (int j = 0; j < 10; j++)
			{
				if (table2[j].num[col2] == 55)
				{
					printf("Merge join\n");
					printf("%3d %3d %3d %3d %3d \n", table1[i].num[0], table1[i].num[1], table1[i].num[2], table2[j].num[1], table2[j].num[2]);
				}
			}
		}
	}
}

void main()
{
	//create table
	create_table();
	//print table
	print_table(table1,table2);
	//update table
	table1[9].num[2] = 55;
	table1[14].num[2] = 55;
	table2[4].num[0] = 55;
	//duplex sort table1, table2
	sort1(table1, 3-1, 15);
	sort1(table2, 1-1, 10);
	//print duplex sorting table
	printf("Duplex sorting\n");
	print_table(table1, table2);
	//Quick sort table3, table4 (not sorting table)
	sort2(table3, 2, 0, 14);
	sort2(table4, 0, 0, 0, 9);
	// print quick sorting table
	printf("Quick sorting\n");
	print_table(table1, table2);
	// merge join funtion
	join(table1, table2, 2, 0, 55);
}