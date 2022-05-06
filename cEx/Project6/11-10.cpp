#include <stdio.h>
#include <stdlib.h>

void main() 
{
	struct NODE {
		int key;
		struct NODE* next;
	};
	struct NODE* node0,* node1,* node2;
	
	node1 = (struct NODE *)malloc(1 * sizeof(struct NODE));
	node2 = (struct NODE*)malloc(1 * sizeof(struct NODE));
	node0 = (struct NODE*)malloc(1 * sizeof(struct NODE));
	
	if (node1 == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	if (node0 == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	if (node2 == (struct NODE*)NULL)
	{
		printf("malloc failed");
		exit(1);
	}
	
	node0->next = node1;
	node1->next = node2;
	node2->next = NULL;


	free(node0);
	free(node1);
	free(node2);

}