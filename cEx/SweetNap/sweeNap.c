#include<stdio.h>

void main() 
{
	int s = 10;

	printf("Input s num\n");
	scanf("%d", &s);

	struct schedule
	{
		int startHours;
		int startminute;
		int finishHours;
		int finishminute;
		char name[30];
	}schedule[10];

	struct schedule2
	{
		int startHours;
		int startminute;
		int interval;
	}starttime;

	
	for (int i = 0;i < s;i++)
	{
		scanf("%2d:%2d %2d:%2d %s",
			&schedule[i].startHours, 
			&schedule[i].startminute, 
			&schedule[i].finishHours, 
			&schedule[i].finishminute,
	        &schedule[i].name[30]
		);
	}

	int interval=0;
	
	

	for (int i = 0; i < s;i++)
	{
		int newInterval = (schedule[i + 1].startHours
			- schedule[i].finishHours) * 60
			+ schedule[i + 1].startminute
			- schedule[i].finishminute;
		
		if (interval < newInterval)
		{
			interval = (schedule[i + 1].startHours
				- schedule[i].finishHours) * 60
				+ schedule[i + 1].startminute
				- schedule[i].finishminute;
			starttime.interval = interval;
			starttime.startHours = schedule[i].finishHours;
			starttime.startminute = schedule[i].finishminute;
		}
	}

	printf("Day #1: the longest nap starts at %2d:%2d and will last for %d hours and %d minutes"
		, starttime.startHours
		, starttime.startminute
		, (starttime.interval) / 60
		, (starttime.interval) % 60
	);

}