#include <stdio.h>

// get character and side1 and side2 and display ractangle
ractangle(char c, int side1, int side2)
{
	for (int i = 0; i < side1;i++)
	{
		for (int j = 0; j < side2;j++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
}

void main()
{
	char c;
	int side1, side2;
	printf("Enter a character to fill the rectangle: ");
	scanf("%c", &c);
	printf("Enter sides: ");
	scanf("%d %d", &side1, &side2);

	ractangle(c, side1, side2);

}
