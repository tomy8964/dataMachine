#include <stdio.h>
#include <math.h>

void main()
{
	//define struct dots
	struct dot 
	{
		float x;
		float y;
		float px;
		float py;
		int idx;
	}dots[30];

	//define struct paths
	struct paths
	{
		float x1;
		float x2;
		float y1;
		float y2;
		int idx1;
		int idx2;
		double weight;
	}path[100],temp;

	//input dotsNum
	int dotsNum;
	printf("How many dots?\n");
	scanf("%d",&dotsNum);
	
	//input dots information
	for (int i = 0;i < dotsNum; i++)
	{
		printf("%d's dots x,y?(0<n<30)\n",i+1);
		scanf("%f %f",&dots[i].x,&dots[i].y);
		dots[i].idx = i;
	}

	//calculate edgeNum
	int edgeNum = (dotsNum*(dotsNum - 1)) / 2;
	
	// calculate path weight and save
	int j = 0;
	int k = 1;
	for (int i = 0;i < edgeNum;i++)
	{
		path[i].x1 = dots[j].x;
		path[i].y1 = dots[j].y;
		path[i].x2 = dots[j + k].x;
		path[i].y2 = dots[j + k].y;
		path[i].idx1 = dots[j].idx;
		path[i].idx2 = dots[j + k].idx;
		path[i].weight = sqrt(pow(path[i].x1-path[i].x2, 2) + pow(path[i].y1-path[i].y2, 2));
		k++;
		if (j+k == dotsNum)
		{
			j++;
			k = 1;
		}
	}
	
	//sort in ascending order by weight
	for (int i = 0; i < edgeNum; i++) {
		for (j = 0; j < (edgeNum - 1) - i; j++) 
		{
			if (path[j].weight > path[j + 1].weight) 
			{
				temp = path[j];
				path[j] = path[j + 1];
				path[j + 1] = temp;
			}
		}
	}

	// Initializes the dots parent to itself
	for (int i = 0; i < dotsNum;i++)
	{
		dots[i].px = dots[i].x;
		dots[i].py = dots[i].y;
	}
	
	//find the minimum total length of ink lines that can connect all the dots
	float weight=0.0;
	j = 0;
	for (int i = 0; i < edgeNum;i++)
	{
		if (j == dotsNum-1)
		{
			break;
		}
		//first path
		if (i == 0)
		{
			//set dot's parent itself
			dots[path[i].idx1].px = dots[path[0].idx1].x;
			dots[path[i].idx1].py = dots[path[0].idx1].y;
			//set first path dots are connected
			dots[path[i].idx2].px = dots[path[0].idx1].x;
			dots[path[i].idx2].py = dots[path[0].idx1].y;
			weight = path[i].weight + weight;
			j++;
		}
		// if already path dots are connected
		if (((dots[path[i].idx1].px) == dots[path[i].idx2].px) && ((dots[path[i].idx1].py) == dots[path[i].idx2].py))
		{
			continue;
		}
		// connect path dots and set parent to show connected
		else
		{
			dots[path[i].idx2].px = dots[path[i].idx1].px;
			dots[path[i].idx2].py = dots[path[i].idx1].py;
			weight = path[i].weight + weight;
			j++;
		}
	}
	
	//print total weight
	printf("%0.2f", weight);	
	
}