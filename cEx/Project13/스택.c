#include<stdio.h>
int ds[5];
int top=-1;


int get(int* item)
{
	*item = ds[top];
	int empty = is_empty();
	top--;
	return empty;
}

int put(int newitem)
{
	int full=is_full();
	ds[top + 1] = newitem;
	top++;
	return full;
}

int is_full() 
{
	if (top == 4)
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
	if (top == -1)
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
	char c[100];
	int newitem;
	int full,empty;
	
	top = -1;
	int pop_val;
	
	put(10);
	put(40);
	put(15);
	put(35);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	put(50);
	put(20);
	put(25);
	put(50);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	if (get(&pop_val) != -1) printf("pop: %d\n", pop_val);
	
		
}