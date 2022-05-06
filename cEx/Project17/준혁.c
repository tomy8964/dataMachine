#include <stdio.h>
#define ABS(x) (x>0? x,-x)
main()
{
	float x;

	scanf("%f", &x);
	printf("%.2f의 절대값: %.2f\n", x, ABS(x));
}

