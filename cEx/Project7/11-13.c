#include<stdio.h>
#include<stdlib.h>

struct NODE {
	int key;
	struct NODE* next;
};

void printList(struct NODE* ptr)
{
	while (ptr)
	{
		printf("key:%d\n", ptr->key);
		ptr = ptr->next;
	}
}

int main()
{
	struct NODE *ptr=NULL,*firstNode, * node1, * node2, * node0, * prev=NULL, * node3;

	node0 = (struct NODE*)malloc(sizeof(struct NODE));
	node1 = (struct NODE*)malloc(sizeof(struct NODE));
	node2 = (struct NODE*)malloc(sizeof(struct NODE));
	node3 = (struct NODE*)malloc(sizeof(struct NODE));

	int newkey,delkey=250, deleted=-1, fail = -1;

	node3->key = newkey = 300;
	node3->next = NULL;

	node0-> key = 100;
	node1-> key = 250;
	node2-> key = 467;

	node0->next = node1;
	node1->next = node2;
	node2->next = NULL;

	firstNode = node0;
	
	printf("Original\n");
	printList(firstNode);

	ptr = firstNode;

	while (ptr)
	{
		if (ptr->key == newkey)
		{
			printf("300 already exists");
			break;
		}
		if (ptr->key < newkey)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		else
		{
			prev->next = node3;
			node3->next = ptr;
			printf("key inserted\n");
			break;
		}
	}

	printList(firstNode);

	ptr = firstNode;

	while (ptr)
	{
		if (ptr->key == delkey)
		{
			prev->next = ptr->next;
			ptr->next = NULL;
			deleted = 1;
			break;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if (deleted==1)
	{
		printf("del key\n");
		printList(node0);
	}
	else if(deleted==-1)
	{
		printf("delkey not founded\n");
		printList(node0);
	}

	return 0;
}
