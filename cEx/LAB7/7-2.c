#include <stdio.h>

void main()
{
	int a = 10;
	int b = 20;

	int* p1 = &a;
	int* p2 = &b;
	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

	printf("%d %d %p %p", a, b, p1, p2);

}