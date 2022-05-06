#include<stdio.h>
#include<math.h>

//get a, b, c and calculate dis and print roots
void calculate(int a, int b, int c)
{
	int dis;
	
	dis = b * b - (4 * a * c);
	
	if (dis >= 0)
	{
		float root1, root2;
		printf("Two real and equal roots\n");
		root1 = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a);
		root2 = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a);
		printf("Roots are %f and %f", root1, root2);
	}
	else
	{
		printf("The equation has imaginary (or complex) roots. \n");
	}
}

void main()
{
	int a, b, c;
	printf("The coefficients of Quadratic Equation ax^2=bx+c=0 are a, b and c\n");
	printf("Enter values of a, b and c: \n");
	scanf("%d %d %d", &a, &b, &c);

	calculate(a, b, c);

}