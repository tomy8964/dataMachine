#include<stdio.h>
#include<malloc.h>

// definition of linked list node
struct Node {
	int key;
	struct Node* next;
};

// definition rear, front
struct Node* rear,*front;

// check queue is empty
int queue_empty()
{
	// front point nothing means empty
	if (front == NULL)
	{
		printf("Queue is Empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

// enqueue data
void enqueue(data)
{
	// make new node, push data and make rear point new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->key = data;
	new_node->next = NULL;

	// if queue is empty, front and rear point new node
	if (front == NULL&&rear==NULL)
	{
		front = new_node;
		rear = new_node;
	}
	else // link new node and rear point new node
	{
		rear->next = new_node;
		rear = new_node;
	}
	printf("sucess enqueue : %d\n", data);
}

// dequeue 
void dequeue()
{
	if (queue_empty() == 0)
	{
		//save data to temp and print data
		struct Node* temp = front;
		int data = temp->key;
		printf("dequeue:%d\n", data);
		
		// rear and front point same node means node is one left
		if (rear == front)
		{
			//rear point null and queue is empty
			rear = rear->next;
		}
		//front point null and queue is empty
		front = temp->next;
		//delete last node
		free(temp);
	}
}

void main()
{
	enqueue(1);
	dequeue();
	dequeue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	dequeue();
	dequeue();
	dequeue();
	enqueue(5);
	enqueue(6);
	dequeue();
	dequeue();
	dequeue();
}