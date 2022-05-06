#include<stdio.h>

int stack[10];
int top = -1;

// push function put newitem to stack
push(int newitem)
{
	int full = stack_full();
	if (full == 1)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("push=%d\n", newitem);
		stack[top + 1] = newitem;
		top++;
	}
	return full;
}

//pop function print the last item of stack and delete it
int pop()
{
	int pop_val;
	int empty = stack_empty();
	if (empty == 1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		pop_val = stack[top];
		printf("pop=%d\n",pop_val);
		top--;
	}
	return empty;
}

// stack_full function check stack is full and return value to push function
int stack_full()
{
	if (top == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// stack_empty function check stack is empty and return value to pop function
int stack_empty()
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
	push(1);
	push(2);
	push(3);
	pop();
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
	push(12);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
}