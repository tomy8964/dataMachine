#include <stdio.h>

void main()
{
	int man=0;
	int money[10] = {0,};

	printf("? :\n");
	scanf("%d", &man);

	for (int i = 0; i < man;i++)
	{
		printf("?:\n");
		scanf("%d", &money[i]);
	}

	int sum = 0;

	for (int i = 0; i < man;i++)
	{
		sum = money[i] + sum;
	}
	
	int moneyOne = sum / man;
	int moneyone[10] = { 0, };
	
	for (int i = 0; i < man;i++)
	{
		moneyone[i] = moneyOne - money[i];
	}

	int output = 0;

	for (int i = 0; i < man;i++)
	{
		if (moneyone[i] > 0)
		{
			output = moneyone[i] + output;
		}
	}
	printf("%d", output);

}