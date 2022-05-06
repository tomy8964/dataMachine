#include<stdio.h>

void convertToBin(int n, char c[])
{
	char t[1024];
	int i = 0;
	while (n > 0)
	{
		t[i] = n % 2+'0';
		n = n / 2;
		i++;
	}
	for (int j = 0;j < i;j++)
	{
		c[j] = t[i - j - 1];
	}

	c[i] = 0;
}

int main()
{
	char bin[1024];
	for (int i = 0; i<= 1000;i++)
	{
		convertToBin(i, bin);
		printf("%d %s %0x\n", i,bin, i);
	}
	return 1;
} 