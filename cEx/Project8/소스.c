#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
	int number;
	char name[100];
	int age;
	int amatch;
	int goals;
	struct NODE* next;
};


void printList(struct NODE* ptr)
{
	while (ptr)
	{
		printf("num%d name:%s age:%d Amatch:%d goals:%d\n", ptr->number, ptr->name, ptr->age, ptr->amatch, ptr->goals);
		ptr = ptr->next;
	}
}

// not sorting
void insertNode(struct NODE* head, int number, const char name[], int age, int amatch, int goals)
{
	// assign memory
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	new_node->number = number;
	strcpy(new_node->name, name);
	new_node->age = age;
	new_node->amatch = amatch;
	new_node->goals = goals;
	new_node->next = NULL;

	struct NODE* prev = head;
	struct NODE* ptr = head->next;
	// set ptr to the last node
	while (ptr) {
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = new_node;
}

void insertAgeNode(struct NODE* head, struct NODE* node)
{
	// assign memory
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	*new_node = *node;
	new_node->next = NULL;

	struct NODE* prev = head;
	struct NODE* ptr = head->next;
	// set ptr to the last node
	while (ptr) {
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = new_node;
}

int main()
{
	struct NODE* head_all = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* head_age = (struct NODE*)malloc(sizeof(struct NODE));
	head_all->next = NULL;
	head_age->next = NULL;

	insertNode(head_all, 1, "Jung Sung-Ryong", 25, 22, 0);
	insertNode(head_all, 7, "Park Ji-Sung", 29, 94, 13);
	insertNode(head_all, 10, "Park Chu-Young", 25, 47, 15);
	insertNode(head_all, 12, "Lee Young-Pyo", 33, 119, 5);
	insertNode(head_all, 16, "Ki Sung-Yueng", 21, 28, 4);
	insertNode(head_all, 17, "Lee Chung-Yong", 22, 27, 4);
	insertNode(head_all, 22, "Cha Du-Ri", 30, 51, 4);

	printf("original list");
	printList(head_all->next);

	// predicate-based search
	// create a new linked list consist of age of nodes between 25~29

	struct NODE* ptr = head_all->next;
	while (ptr) {
		if (ptr->age >= 25 && ptr->age <= 29) {
			insertAgeNode(head_age, ptr);
		}
		ptr = ptr->next;
	}

	printf("predicated-based search result\n");
	printList(head_age->next);

	return 1;
}