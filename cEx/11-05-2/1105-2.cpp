#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	struct person {
		char name[100];
		int age;
		float salary;
	}p[100],p1[100];

	FILE* v1file, *v2file, *v3file;

	v1file = fopen("salary_v1.txt", "r");
	if (v1file == NULL)
	{
		printf("Could Not open data.txt!\n");
		exit(1);
	}

	int n = 0;

	while (fscanf(v1file, "%s %d %f", p[n].name, &p[n].age, &p[n].salary) == 3)
	{
		n++;
	}

	v2file = fopen("salary_v2.txt", "w");

	for (int i = 0; i < n; i++)
	{
		if ((40 <= p[i].age) && (p[i].age <= 49))
		{
			p[i].salary = p[i].salary * 1.10;
		}
	}

	for (int i = 0;i < n; i++)
	{
		fprintf(v2file, "%s %d %6.1f\n", p[i].name, p[i].age,p[i].salary);
	}
	
	v3file = fopen("salary_v3.txt", "w");

	for (int i = 0; i < n; i++)
	{
		if ((30 <= p[i].age) && (p[i].age <= 39))
		{
			p[i].salary = p[i].salary * 1.20;
		}
	}
	
	for(int i=0; i<n; i++)
	{
		fprintf(v3file, "%s %d %6.1f\n", p[i].name, p[i].age, p[i].salary);
	}

	n = 0;

	for (int i = 0; i < n; i++)
	{
		while (fscanf(v1file, "%s %d %f", p1[n].name, &p1[n].age, &p1[n].salary) == 3)
		{
			n++;
		}
		printf("%s  %d %6.1f -> %6.1f", p[i].name, p[i].age, p[i].salary, p1[i].salary);
		
	}

	fclose(v1file);
	fclose(v2file);
	fclose(v3file);

}