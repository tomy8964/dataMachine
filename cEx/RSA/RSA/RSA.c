//201835546 ÇÔ°Ç¿í

#include <stdio.h>
#include <math.h>

// use modExp to find original message M
int	modExp(int	a, int b, int c)
{
	// b>=0
	// value is M
	int	value;
	if (b == 0) {
		value = 1;
	}
	else {
		value = modExp(a, b / 2, c);
		
		// if the last bit is 1
		if (b & 1) 
		{
			value = value * value % c * a % c;
		}
		else
		{
			value = value * value % c;
		}
	}
	return value;
}

void main()
{
	// definition
	int e;
	int n;
	int c;
	int p=0, q=0;

	//input e,n,c
	printf("public key(n,e)\ncipertext C\n");
	printf("Input e, n, c\n");
	scanf("%d %d %d",&e,&n,&c);
	
	// find p, q
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			p = i;
			q = n / i;
			break;
		}
	}
	// calculate pi
	int pi = (p - 1) * (q - 1);
	int m;
	int d=0;

	//d*e = 1 mod pi, d<pi
	//find d
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		num = i * pi + 1;
		if (num % e == 0)
		{
			d = num / e;
			break;
		}
	}
	
	// use modExp to find m
	m = modExp(c, d, n);
	printf("Original message is %d", m);
}