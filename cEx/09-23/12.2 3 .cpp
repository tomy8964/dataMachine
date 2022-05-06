#include<stdio.h>
int main()
{
	struct pay {
		int ID_Number;
		char Name[10];
		float Payrate;
		float Hoursworked;
	};

	struct pay employee [6] = {
	{ 3462, "Jones", 4.62, 40.0},
	{ 6793, "Robbins", 5.83, 38.5},
	{ 6985, "Smith", 5.22, 45.5},
	{ 7834, "Swain", 6.89, 40.0},
	{ 8867, "Timmins", 6.43, 35.5},
	{ 9002, "Williams", 4.75, 42.0}
	};

	int i;
	float grosspay[6], total_gross = 0;

	for (i = 0; i < 6; i++) {
		grosspay[i] = employee[i].Payrate * employee[i].Hoursworked;
		printf("name:%s ID:%4d Gross pay:%lf", employee[i].Name, employee[i].ID_Number, grosspay[i]);
		total_gross = total_gross + grosspay[i];
		printf("total gross : %.2f", total_gross);
	};

	return 0;
}