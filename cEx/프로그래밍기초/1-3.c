#include<stdio.h>

void main()
{
	float miles, costGallon, milesGallon, parkingFees, tolls,drivingCost;

	printf("Total miles driven per day?(miles)\n");
	scanf("%f", &miles);
	printf("Cost per gallon of gasoline?$\n");
	scanf("%f", &costGallon);
	printf("Average miles per gallon?\n");
	scanf("%f", &milesGallon);
	printf("Parking fees per day?\n");
	scanf("%f", &parkingFees);
	printf("Tolls per day?\n");
	scanf("%f", &tolls);

	drivingCost = (((miles / milesGallon) * costGallon)+parkingFees)+tolls;

	printf("Drving Cost per day=%f$", drivingCost);
}