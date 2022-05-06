#include <stdio.h>
#include <string.h>

void main()
{
	char char1[10];
	printf("input string\n");
	scanf("%s", &char1);
	char char2[10];
	printf("input string\n");
	scanf("%s", &char2);


	int lis[11][11];

	for (int j = 0;j <= strlen(char1) + 1;j++)
	{
		lis[0][j] = 1;
	}
	for (int j = 0;j <= strlen(char2) + 1;j++)
	{
		lis[j][0] = 0;
	}
	lis[0][0] = 1;
	for (int i = 1;i < strlen(char2) + 1;i++)
	{
		for (int j = 1;j < strlen(char1) + 1;j++)
		{

			if (char1[j] == char2[i])
			{
				lis[i][j] = lis[i][j - 1] + lis[i - 1][j - 1];
			}
			else
			{
				lis[i][j] = lis[i][j - 1];
			}
		}
	}

	printf("%d", lis[strlen(char2) - 1][strlen(char1) - 1]);
}