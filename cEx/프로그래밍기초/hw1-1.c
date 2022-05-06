#include<stdio.h>

void main()
{
	int insec,hours,minutes,seconds;

	printf("enter the total time elapsed, in seconds\n");
	scanf("%d",&insec);

	hours = (insec / 60)/60;
	minutes = (insec/60)%60;
	seconds = insec%60;

	printf("%d : %d : %d", hours, minutes, seconds);
}