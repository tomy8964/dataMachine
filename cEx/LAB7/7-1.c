#include <stdio.h>

void main()
{
	char a = 'a';
	int b = 10;
	double c = 3.14;

	char* p1 = &a;
	int* p2 = &b;
	double* p3 = &c;

	*p1 = (*p1) + 1;
	*p2 = (*p2) + 1;
	*p3 = (*p3) + 1;

	printf("%c %d %0.2f %p %p %p",a,b,c, p1, p2, p3);

}