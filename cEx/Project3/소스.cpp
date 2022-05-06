#include<stdio.h>
int bs(int list[], int lo, int hi, int key)
{
	int mid;

	if (lo > hi)
		return -1;
	mid = (lo + hi) / 2;
	if (list[mid] == key)
		printf("Found\n");
	else if (list[mid] > key)
		bs(list, lo, mid - 1, key);
	else if (list[mid] < key)
		bs(list, mid + 1, hi, key);
}

int main() 
{
	int li[13] = {1,5,10,15,25,45,50,55,60,65,70,75,85};
	int n = 5;
	
	bs(li,0, 12, 5);
	
	return 0;
}
