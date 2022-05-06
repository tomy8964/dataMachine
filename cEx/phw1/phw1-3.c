#include<stdio.h>
int queue1[9];
int queue2[9];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

//dequeue1 function return queue1 front data and delete it
int dequeue1()
{
	int item;
	item = queue1[front1 + 1];
	front1++;
	return item;
}

//enqueue2 function put queue1 front data to queue2 rear position. 
enqueue2(int item)
{
	queue2[rear2 + 1] = item;
	rear2++;
}

// pop function use two queue
pop()
{
	if (queue_empty() == 1)
	{
		printf("It's empty\n");
	}
	else
	{
		// except rear data of queue1
		for (int i = 0; i < (rear1 - front1);i++)
		{
			enqueue2(dequeue1());
		}
		//print the rear data of queue1
		printf("pop:%d\n", queue1[rear1]);
		//set rear and front position
		rear1--; // rear data is deleted
		front1 = -1; // set point front data
		front2 = -1; // reset
		rear2 = -1; // reset
	}
}



// enqueue function put newitem to queue1
enqueue1(int newitem)
{
	int full = queue_full();
	if (full == 1)
	{
		printf("It's full\n");
		return 1;
	}
	else
	{
		queue1[rear1 + 1] = newitem;
		printf("push:%d\n", newitem);
		rear1++;
		return 0;
	}
}

push(int item)
{
	enqueue1(item);
}

// queue_full function check queue1 is full and return value to enqueue1 function
int queue_full()
{
	if ((rear1 - front1) == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// queue_empty function check queue1 is empty and return value to dequeue function
int queue_empty()
{
	if (rear1 == front1)
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
	push(1);
	push(2);
	push(3);
	pop();
	pop();
	pop();
	pop();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
}