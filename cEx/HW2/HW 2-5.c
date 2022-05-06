#include <stdio.h>

int main()
{
	//set value 0
	int num=0;

	//value 0 to 127
	while (num <= 127)
	{
		//10 vlaues per 1 line
		for (int i = 0; i<10; i++)
		{
			//print ASCII value of character
			printf("%c", num);
			//next vlaue
			num++;
		}
		//plus line
		printf("\n");
	}

	return 0;
}