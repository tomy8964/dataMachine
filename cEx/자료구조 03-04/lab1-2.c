#include<stdio.h>
int queue[10];
int front = -1, rear = -1;

//dequeue function print the first item of queue and delete it
int dequeue()
{
	int empty = queue_empty();
	if (empty == 1)
	{
		printf("It's empty\n");
		return 0;
	}
	else
	{
		int item;
		item = queue[front + 1];
		printf("dequeue:%d\n", item);
		front++;
		return 0;
	}
}

// enqueue function put newitem to queue
enqueue(int newitem)
{
	int full = queue_full();
	if (full == 1)
	{
		printf("It's full\n");
		return 1;
	}
	else
	{
		queue[rear+1] = newitem;
		printf("enqueue:%d\n", newitem);
		rear++;
		return 0;
	}
}

// queue_full function check queue is full and return value to enqueue function
int queue_full()
{
	if ((rear - front) == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// queue_empty function check queue is empty and return value to dequeue function
int queue_empty()
{
	if (rear == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
	enqueue(1);
	dequeue();
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	enqueue(11);
	enqueue(12);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
}