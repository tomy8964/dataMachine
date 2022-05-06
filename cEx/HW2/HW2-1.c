#include <stdio.h>

int main() 
{
	int hours;
	float rate;

	// repeat
	while (1)
	{
		//input hourst
		printf("Enter # of hours worked (-1 to end): ");
		scanf("%d", &hours);

		// if hours -1, break the loop
		if (hours == -1)
		{
			break;
		}
		// input rate
		else
		{
			printf("Enter hourly rate of the worker ($00.00): ");
			scanf("%f", &rate);
			// exceed 40 hours
			if (hours > 40)
			{
				printf("salary is $%0.2f\n", ((40*rate)+((hours-40)*1.5*rate)));
			}
			// not exceed 40 hours
			else
			{
				printf("salary is $%0.2f\n", rate * hours);
			}
		}
	}

	return 0;
}