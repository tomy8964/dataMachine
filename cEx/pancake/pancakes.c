#include <stdio.h>

void filp(int num,int pancakes, int pcakes[])
{
	int tmp[30];
	for (int i = 0;i < pancakes+1;i++)
	{
		tmp[i] = pcakes[i];
	}
	
	for (int i = 1;i < pancakes+1;i++)
	{
		tmp[pancakes-i] = pcakes[num+i-1];
	}

	for (int i = 0;i < pancakes+1;i++)
	{
		pcakes[i] = tmp[i];
	}
}

 
void main()
{
	int pancakes;
	
	printf("How many pancakes?\n");
	scanf("%d", &pancakes);
	
	int pcakes[30] = { NULL, };
	
	for (int i = 0;i < pancakes;i++)
	{
		printf("input:(1~10)");
		scanf("%d",&pcakes[i]);
	}

	int max = 0,idx=0;
	
	
	for (int j = 0;j < pancakes;j++)
	{
		max = 0;

		for (int i = 0;i < pancakes-j;i++)
		{
			if (max < pcakes[i])
			{
				max = pcakes[i];
				idx = i;
				if (idx == pancakes - j-1)
				{
					goto Exit;
				}
			}
		}
		filp(idx, pancakes-j, pcakes);

	}

	Exit:
	
	for (int i = 0;i < pancakes;i++)
	{
		printf("%d ", pcakes[i]);
		
	}

}

