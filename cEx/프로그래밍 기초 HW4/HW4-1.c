#include <stdio.h>

// get side1, side2 and print ractangle
void ractangle(int side1, int side2)
{
	for (int i = 0; i < side1;i++)
	{
		for (int j = 0; j < side2;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void main()
{
	int side1, side2;
	printf("Enter sides: ");
	scanf("%d %d", &side1, &side2);
	ractangle(side1, side2);

}
