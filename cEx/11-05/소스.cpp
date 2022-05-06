#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() 
{
	struct person {
		char region[100];
		int age;
		char voted[100];
	}p[100],pt[100],pten[100];

	float cnt_Biden=0, cnt_Trump=0;
	int k = 0, j = 0;
	float p_B = 0.0, p_T = 0.0;

	FILE* vfile;

	vfile = fopen("vote.txt", "r");
	if (vfile == NULL)
	{ 
		printf("Could Not open personal.txt!\n");
		exit(1);
	}
	
	int n = 0;
	
	while (fscanf(vfile,"%s %d %s", p[n].region, &p[n].age, p[n].voted) == 3)
	{
		n++;
	}

	for (int i = 0; i < n; i++)
	{
		if (strcmp(p[i].voted, "Biden") == 0)
		{
			cnt_Biden++;
		}
		else if (strcmp(p[i].voted, "Trump") == 0)
		{
			cnt_Trump++;
		}
	}


	p_B = (cnt_Biden / n)*100;
	p_T = (cnt_Trump / n)*100;
	
	printf("ALL : Biden %2.2f%%, Trump %2.2f%%\n", p_B, p_T);
	printf("------------------------------------\n");
	printf("Every third row\n");
	printf("------------------------------------\n");

	cnt_Biden=0, cnt_Trump = 0;

	p_B = 0.0, p_T = 0.0;
	int cnt = 0;
	
	for (int i = 2; i < n; i=i+3)
	{
		pt[k] = p[i];
		printf("%s %d %s\n", pt[k].region, pt[k].age, pt[k].voted);
		k++;
		if (strcmp(p[i].voted, "Biden") == 0)
		{
			cnt_Biden++;
		}
		else if (strcmp(p[i].voted, "Trump") == 0)
		{
			cnt_Trump++;
		}
		cnt++;
	}

	p_B, p_T = 0;

	p_B = (cnt_Biden / cnt) * 100;
	p_T = (cnt_Trump / cnt) * 100;

	printf("Third : Biden %2.2f%%, Trump %2.2f%%\n", p_B, p_T);

	printf("------------------------------------\n");
	printf("Every tenth row\n");
	printf("------------------------------------\n");
	
	for (int i = 9; i < n; i = i + 10)
	{
		pten[k] = p[i];
		printf("%s %d %s\n", pten[k].region, pten[k].age, pten[k].voted);
		k++;
	}

	p_B, p_T = 0;
	cnt = 0;

	p_B = (cnt_Biden / cnt) * 100;
	p_T = (cnt_Trump / cnt) * 100;

	printf("Third : Biden %2.2f%%, Trump %2.2f%%\n", p_B, p_T);

	
	fclose(vfile);
	

}