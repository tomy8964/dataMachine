#include <stdio.h>
#include <math.h>

// frosh position sturcture
struct frosh {

	float y;

	float x;

}froshs[100];

//compute Angle function
float computeAngle(struct frosh a[], int i, int j)
{
	float dx, dy;
	float ang;
	float angle;

	//compute dx, dy
	dx = a[j].x - a[i].x;
	dy = a[j].y - a[i].y;

	if ((dx >= 0) && (dy == 0)) angle = 2;
	else
	{
		ang = abs(dx) + abs(dy);
		angle = abs(dy) / ang;

		if ((dx < 0) && (dy >= 0))angle = 2 - angle;

		else if ((dx <= 0) && (dy < 0))angle = 2 + angle;

		else if ((dx > 0) && (dy < 0))angle = 4 - angle;
	}

	return (angle * 90);
}

void main() {

	int testCase;

	int froshNum;

	//input Test case #
	printf("Test case:\n");
	scanf("%d", &testCase);

	//input frosh #
	printf("Input frosh Num\n");
	scanf("%d", &froshNum);

	//input first froshs member (0,0)
	froshNum++;
	froshs[0].x = 0;
	froshs[0].y = 0;


	//input position of froshs members
	for (int i = 1;i < froshNum;i++)
	{
		printf("%d frosh point\n", i);
		scanf("%f %f", &froshs[i].y, &froshs[i].x);
	}

	float angle[100];
	float nextPoint=360;
	int point[30];
	int k = 0;

	for (int i = 0;i < froshNum-1;i++)
	{
		for (int j = 1;j < froshNum;j++)
		{
			//if same frosh skip
			if (k == j)
			{
				j++;
			}
			// calculate angle use javis March algorithm
			//if min angle
			if (nextPoint > computeAngle(froshs, k, j))
			{
				//Check if already meeted point
				for (int q = 0;q < i;q++)
				{
					if (point[q] == j)
					{
						j++;
						//if over froshs
						if (j >= froshNum)
						{
							continue;
						}
					}
				}
				//if over froshs
				if (j >= froshNum)
				{
					continue;
				}
				//set min angle
				nextPoint = computeAngle(froshs, k, j);
				//input outer members
				point[i] = j;
			}
		}
		nextPoint = 360;
		k = point[i];
	}

	double distance=0;
	double x1, x2;
	double y1, y2;
	
	// calculate distance
	for (int i = 0;i < froshNum;i++)
	{
		if (i == 0)
		{
			x1 = 0;
			y1 = 0;
			x2 = froshs[point[i]].x;
			y2 = froshs[point[i]].y;
			distance = distance + sqrt(pow(x1 - x2,2) + pow(y1-y2,2));
			continue;
		}
		if (i == froshNum - 1)
		{
			x1 = 0;
			y1 = 0;
			x2 = froshs[point[i-1]].x;
			y2 = froshs[point[i-1]].y;
			distance = distance + sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		}
		else
		{
			x1 = froshs[point[i - 1]].x;
			y1 = froshs[point[i - 1]].y;
			x2 = froshs[point[i]].x;
			y2 = froshs[point[i]].y;

			distance = distance + sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		}
	}

	//print length+2
	printf("%0.2f", distance + 2);

}