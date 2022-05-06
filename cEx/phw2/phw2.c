#include<stdio.h>
int queue[5];
int front = -1, rear = -1;

int dequeue();
int enqueue(int);

int dequeue()
{
	//queue is empty
	if (front==-1)
	{
		printf("circular queue underflow\n");
		return -1;
	}
	else
	{
		//front move to first circular queue
		if (front == 4)
		{
			printf("get:%d\n", queue[front]);
			front = 0;
			return 0;
		}
		//last data dequeue and set queue to the first state
		else if (front==rear)
		{
			printf("get:%d\n", queue[front]);
			front == -1;
			rear = -1;
			return 0;
		}
		//dequeue data and move front
		else
		{
			printf("get:%d\n", queue[front]);
			front++;
			return 0;
		}
	}
}

// insert new data
int enqueue(int newitem)
{
	//queue is full
	if ((front == 0) && (rear == 4) || (front == rear + 1))
	{
		printf("circular queue overflow\n");
		return -1;
	}
	else
	{
		//first data insert
		if (front == -1)
		{
			front++;
		}
		//rear is last of array so move rear to first of array
		else if (rear == 4)
		{
			rear = -1;
		}
		rear++;
		queue[rear] = newitem;
		return 0;
	}
}


void main()
{
	enqueue(10);
	enqueue(50);
	enqueue(20);
	enqueue(70);
	dequeue();
	enqueue(100);
	enqueue(40);
	enqueue(140);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
}