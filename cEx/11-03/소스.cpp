#include<stdio.h>
#include<stdlib.h>

int main() {
	struct CAR {
		char name[20];
		int year;
		double price;
	}car[4] =
	{ 
		{"Avante",2007,13000.00},
		{"Sonata",2008, 18000.00},
		{"SM7", 2009, 22000.00},
		{"Equus", 2010, 35000.00}
	};

	int i = 0;
	char ch;

	FILE* carsWFile, * carsRFile;

	carsWFile = fopen("cars.txt", "w");
	if (carsWFile == NULL)
	{
		printf("Could not open data.txt!\n");
		exit(1);
	}

	fprintf(carsWFile, "------------------------------------\n");
	fprintf(carsWFile, "|Name    |Year    |Price     |\n");
	fprintf(carsWFile, "------------------------------------\n");

	while (i!=4)
	{	
		fprintf(carsWFile,"|%-8s|%8d|%10.2f|\n", car[i].name, car[i].year,car[i].price);
		i++;
	}

	fprintf(carsWFile, "------------------------------------\n");

	fclose(carsWFile);

	carsRFile = fopen("cars.txt", "r");
	if (carsRFile == NULL)
	{
		printf("Could not open samedata.txt!\n");
		exit(1);
	}

	while ((ch = fgetc(carsRFile)) != EOF)
	{
		putchar(ch);
	}
	
	fclose(carsRFile);

	return 0;
}