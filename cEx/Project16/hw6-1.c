#include <stdio.h>
#include <stdlib.h>

void fcopy(char*, char*); //function prototype

void main()
{
	char inputFile[100] = "employee.dat"; //input file name
	char outputFile[100] = "employee.bak"; //output file name
	
	fcopy(inputFile, outputFile); // function call

}

void fcopy(char*infName,char*oufName) // function definition
{
	struct EMPLOYEE {          // made struture to save data
		char lastName[100];
		char name[100];
		int num;
		float grade;
		char score[100];
	}employee[100];

	FILE* inf, * ouf;     // file header definition

	inf = fopen(infName, "r");  // connect file and header
	if (inf == NULL)
	{
		printf("Could Not open employee.dat!\n");
		exit(1);
	}
	ouf = fopen(oufName, "w"); // connect file and header

	int n = 0;

	// scan from input file and save data to structure

	while (fscanf(inf, "%s %s %d %f %s", employee[n].lastName, employee[n].name, &employee[n].num, &employee[n].grade, employee[n].score) == 5)
	{
		n++;
	}

	//print data to output file

	for (int k = 0; k < n; k++)
	{
		fprintf(ouf, "%s %s %d %f %s\n", employee[k].lastName, employee[k].name, employee[k].num, employee[k].grade, employee[k].score);
	}

	//close file header

	fclose(inf);
	fclose(ouf);

}