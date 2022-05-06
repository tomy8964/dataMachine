#include<stdio.h>

void main()
{
	int  num,num1, num2, num3, num4, num5;

	printf("inputs one five-digit number\n");
	scanf("%d", &num);

	num1 = num / 10000;
	num2 = (num % 10000) / 1000;
	num3 = ((num % 10000) % 1000) / 100;
	num4 = (((num % 10000) % 1000) % 100) / 10;
	num5 = (((num % 10000) % 1000) % 100) % 10;

	printf("%d   %d   %d   %d   %d\n", num1, num2, num3, num4, num5);
}