#include<stdio.h>

int main() {
	
	void word_count(char[]);
	
	char str[] = "hello";

	word_count(str);

	return 0;
}

void word_count(char string[])
{
	int i = 0;
	while (string[i] != NULL)
	{
		i++;
	}

	printf("%d", i);
}
