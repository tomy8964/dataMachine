#include<stdio.h>
#include<string.h>

int main() {
	struct {
		char RRN[13];
		char name[20];
		float salary;
		float bonus;
	}employee[1000];

	for (int i = 0;i < 4;i++)
	{
		printf("Type RRN\n");
		scanf_s("%d", employee[i].RRN,sizeof(employee[i].RRN));
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				j++;
			}
			else if (strcmp(employee[i].RRN,employee[j].RRN)==0)
			{
				printf("error:Unnique RRN\n");
				break;
			}
			
		}
		printf("Type name\n", employee[i].name);
		scanf_s("%s", employee[i].name, sizeof(employee[i].name));
		printf("Type salary\n", employee[i].salary);
		scanf_s("%d", &employee[i].salary);
		printf("Type bonus\n", employee[i].bonus);
		scanf_s("%d", &employee[i].bonus);
		if (employee[i].bonus > employee[i].salary)
		{
			printf("error:bonus > salary\n");
		}
	}

	return 0;
}