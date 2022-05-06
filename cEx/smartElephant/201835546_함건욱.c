//201835546 Ham Geonwook
#include <stdio.h>

//Declare structure
struct elephant
{
	int weight;
	int iq;
	int idx;
}ele[10],tmp[10],lds[10];


void main()
{
	// input elephants number
	int eleNum;
	printf("How many elephants?\n");
	scanf("%d", &eleNum);
	
	//input elephants weight and IQ
	for (int i = 0;i < eleNum;i++)
	{
		printf("%d elephant weight and IQ?\n", i + 1);
		scanf("%d %d", &ele[i].weight, &ele[i].iq);
		ele[i].idx = i + 1;
	}

	//sort with high weight

	for (int i = 0; i < eleNum; i++)
	{
		for (int j = 0; j < eleNum; j++)
		{
			if (ele[i].weight < ele[j].weight)
			{
				tmp[i] = ele[i];
				ele[i] = ele[j];
				ele[j] = tmp[i];
			}
		}
	}

	int min=10000;
	int cnt=0;
	int weight = 0;

	/*Using lds to create an elephant array 
	that increases in weight but decreases IQ*/
	for (int i = 0; i < eleNum;i++)
	{
		if (i==0)
		{
			lds[cnt] = ele[i];
			min = ele[i].iq;
			weight = ele[i].weight;
		}
		else if (min > ele[i].iq)
		{
			if (ele[i].weight == weight)
			{
				continue;
			}
			cnt++;
			lds[cnt] = ele[i];
			min = ele[i].iq;
			weight = ele[i].weight;
		}
		else if (min < ele[i].iq)
		{
			lds[cnt] = ele[i];
			min = ele[i].iq;
			weight = ele[i].weight;
		}
	}

	//print lds length
	printf("%d\n\n", cnt+1);
	
	//print idx for lds
	for (int i = 0; i < cnt+1;i++)
	{
		printf("%d\n",lds[i].idx);
	}
	
	
}