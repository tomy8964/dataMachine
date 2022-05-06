#include<stdio.h>
int main() {
	struct car {
		int CarNum;
		int MilesDri;
		int GallonsUsed;
	};

	struct car cartest[5] = {
	{25,1450,62},
	{36,3240,136},
	{44,1792,76},
	{52,2360,105},
	{68,2114,67}
	};

	int i;
	float Ave=0.0;

	for (i = 0; i < 5; i++) {
		printf("%d car milese per gallon = %.2f\n",cartest[i].CarNum,(float)cartest[i].MilesDri/cartest[i].GallonsUsed);
		Ave = Ave + (float)cartest[i].MilesDri / cartest->GallonsUsed;
	}
	printf("\nThe average miles per gallon is %.2f\n", Ave / 5);
	return 0;
}