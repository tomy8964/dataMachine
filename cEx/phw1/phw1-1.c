#include<stdio.h>
#include<malloc.h>

// definition of linked list node
struct Node{
	int key;
	struct Node* next;
};

// point top stack data
struct Node* top;

// check stack is empty
int stack_empty()
{
	// top point nothing means empty
	if (top == NULL)
	{
		printf("Stack is Empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

// push data
void push(data)
{
	// make new node, push data and make top point new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->key = data;
	new_node->next = top;
	top = new_node;
	printf("sucess push : %d\n", data);
}

// pop data and print
void pop()
{
	if (stack_empty() == 0)
	{
		//save data to temp and print data
		struct Node* temp = top;
		int data = temp->key;
		printf("pop:%d\n", data);
		//make top point node that under the last node
		top = temp->next;
		//delete last node
		free(temp);
	}
}

void main()
{
	push(1);
	pop();
	pop();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
}