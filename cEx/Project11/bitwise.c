#include<stdio.h>
#define MASK 0x80

void main() 
{
	char c;
	scanf("%c", &c);
	printf("%d\n", c);

	for (int i = 0;i < 8;i++)
	{
		if (c&MASK)
		{
			printf("1");
			c = c << 1;
		}
		else
		{
			printf("0");
			c = c << 1;
		}
	}
}