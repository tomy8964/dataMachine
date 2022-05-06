#include <stdio.h>
#define MAXNUM 4
void main()
{
	void findMax(int[MAXNUM]);
	int numList[MAXNUM] = { 1,2,3,4 };

	findMax(numList);
}

void findMax(int local_array[])
{
	int i, max = local_array[0];

	for (i = 1; i < MAXNUM; i = i + 1)
		if (max < local_array[i])
			max = local_array[i];
	printf("%d", max);
}