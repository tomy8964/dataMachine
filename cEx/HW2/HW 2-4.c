#include <stdio.h>

int main()
{
	//first prime num is 2
	int num = 2, divided;

	// loop 2 to 100
	while (num <= 100)
	{
		//set divided 0
		divided = 0;
		//loop until divided
		for (int div = 2; div < num; div++)
		{
			// not prime number
			if (num % div == 0)
			{
				//set divided 1 and break the loop
				divided = 1;
				break;
			}
		}
		// yes prime number
		if (divided == 0)
		{
			printf("%d\n", num);
		}
		// next number
		num++;
	}
}