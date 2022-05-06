#include <stdio.h>

// get num and calculate digits of the number and return sum
int sumdig(int num)
{
	int a, b, c, d,sum;
	a = num / 1000;
	b = (num % 1000) / 100;
	c = ((num % 1000) % 100) / 10;
	d = ((num % 1000) % 100) % 10;

	sum = a + b + c + d;

	return sum;
}
void main()
{
	int num,sum;
	printf("Enter a number between 1 and 9999: \n");
	scanf("%d", &num);
	sum=sumdig(num);
	printf("The sum of the digits of the number %d is  %d", num, sum);
}
