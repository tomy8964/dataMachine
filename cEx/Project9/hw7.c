//201835546 ÇÔ°Ç¿í
#include <stdio.h>
#include <stdlib.h>

struct NODE {     //struct declaration
	int key;
	struct NODE* next;
};


void ScanList(struct NODE* ptr) //ScanList function
{
	while (ptr)
	{
		printf("key:%d\n", ptr->key);
		ptr = ptr->next;
	}
}

int insertKey(struct NODE* head, int key)  // Insert key function
{
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE)); // assign memory
	new_node->key = key;  //input key
	new_node->next = NULL; //input NULL

	struct NODE* prev = head;
	struct NODE* ptr = head->next;

	// Input key in order
	while (ptr)
	{
		if (ptr->key == key)
		{
			printf("%d already exists\n", key); // exits return -1
			return -1;
		}
		if (ptr->key < key) // move next node
		{
			prev = ptr;
			ptr = ptr->next;
			if (ptr == NULL) // ptr point NULL(next to the last list)
			{                // means insert key must be inputed at last of the list 
				prev->next = new_node;
				printf("%d key inserted\n", key);
			}
		}
		else
		{
			prev->next = new_node; // input node in order
			new_node->next = ptr;
			printf("%d key inserted\n",key); // insert return 0
			return 0;
		}
	}
}

int main()
{
	// create 3 node
	struct NODE* ptr, * prev, * node0, * node1, * node2; 
	node0 = (struct NODE*)malloc(sizeof(struct NODE));
	node1 = (struct NODE*)malloc(sizeof(struct NODE));
	node2 = (struct NODE*)malloc(sizeof(struct NODE));
	node0->key = 100;
	node1->key = 250;
	node2->key = 467;
	node0->next = node1; // linked list
	node1->next = node2;
	node2->next = NULL;

	//head declaration
	struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
	head->next = node0; // head->next point to node0

	prev = head; //prev point to head
	ptr = head->next; //ptr is head->next

	printf("original list\n");
	ScanList(head->next);

	printf("\ninserted Key\n");

	insertKey(head, 250);
	insertKey(head, 300);
	insertKey(head, 50);
	insertKey(head, 500);

	
	ScanList(head->next);

	return 1;
}