#include <stdio.h>

void call_by_value(int num)
{
	num = num + 10;
	printf("In the call_by_value function : \n");
	printf("value: %d, Addrss: %p\n", num, &num);
}
void call_by_reference(int* num)
{
	*num = (*num) + 10;
	printf("In the call_by_reference function : \n");
	printf("value: %d, Addrss: %p\n", (*num), num);
}

void main()
{
	int num;

	printf("The difference between 'call by reference' and 'call by value'\n");
	printf("Input an integer: ");
	scanf("%d", &num);
	printf("Before the call_by_value function : \n");
	printf("value: %d, Addrss: %p\n", num, &num);
	call_by_value(num);
	printf("After the call_by_value function : \n");
	printf("value: %d, Addrss: %p\n", num, &num);

	printf("Before the call_by_reference function : \n");
	printf("value: %d, Addrss: %p\n", num, &num);
	call_by_reference(&num);
	printf("After the call_by_reference function : \n");
	printf("value: %d, Addrss: %p\n", num, &num);

}