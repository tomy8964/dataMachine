#include<stdio.h>
int queue[5];
int front = 0, rear = 0;

int get(int*);
int put(int);
int empty();
int full();

int get(int* item)
{
	*item = queue[front%5];
	int empty = is_empty();
	if (empty == 1)
	{
		printf("It's empty\n");
		return -1;
	}
	else
	{
		printf("get:%d\n", queue[front%5]);
		front++;
		return 0;
	}
}

int put(int newitem)
{
	int full = is_full();
	if (full == 1)
	{
		printf("It's full\n");
		return -1;
	}
	else
	{
		queue[(rear%5)] = newitem;
		rear++;
		return 0;
	}
}

int empty()
{
	return 0;
}

int full()
{
	return 0;
}

int is_full()
{
	if ((rear-front)==4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int is_empty()
{
	if (rear==front)
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
	int get_val;

	put(10);
	put(50);
	put(20);
	put(70);
	get(&get_val);
	put(100);
	put(40);
	put(140);
	get(&get_val);
	get(&get_val);
	get(&get_val);
}