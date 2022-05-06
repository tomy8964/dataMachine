#include <stdio.h>

//sum num1 and num2
void summ(int *num1, int *num2, int* sum)
{
	*sum = *num1 + *num2;
}

//multiplies num1 and num2
void mutiplies(int* num1, int* num2, int* product)
{
	*product = *num1 * *num2;
}

void main()
{
	int num1, num2, sum, product;

	printf("Input two integer: ");
	scanf("%d %d", &num1, &num2);
	summ(&num1, &num2, &sum);
	mutiplies(&num1, &num2, &product);
	printf("Result: sum = %d product = %d", sum, product);
	

}