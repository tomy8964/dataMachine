#include <stdio.h>

#define MAXNUM 5
void main()
{
	void mile2km(float[MAXNUM]);
	float miles[MAXNUM] = { 100,200,300,400,500};
	
	mile2km (miles);
}

void mile2km(float local_array[])
{
	int i;

	for (i = 0; i < MAXNUM; i = i+ 1)
		printf("%f\n",local_array[i] * 1.6093);
}