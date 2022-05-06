#include<stdio.h>
#include<malloc.h>

// definition of linked list node
struct Node {
	int key;
	struct Node* next;
};

// point top1, top2 stack data
struct Node* top1,*top2;

void push1(int num);
void push2(int num);
void convert(int num1);
void pop1();
void pop2();

void main()
{
	int num = 0;
	// get decimal number
	printf("Type the number\n");
	scanf("%d", &num);
	// call convert function and give decimal number
	convert(num);
}

// Convert decimal number to binary
void convert(int num1)
{
	// num1 == 0  means convert is finish
	if (num1 != 0)
	{
		int num2;
		int binary;
		// input num1 divided 2 to num2
		num2 = num1 / 2;
		// input num1%2 to binary 
		binary = num1 % 2;
		// put binary num to stack
		push1(binary);
		// give num2 and convert
		convert(num2);
	}
	else
	{
		// go to stack1
		pop1();
	}
}
// check stack is empty
int stack_empty()
{
	// top1 point NULL means stack1 is empty
	if (top1 == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// push binary num to stack1
void push1(int binary)
{
	// make new node, push data and make top point new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->key = binary;
	new_node->next = top1;
	top1 = new_node;
}

void push2(int binary)
{
	// make new node, push data and make top point new node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->key = binary;
	new_node->next = top2;
	top2 = new_node;
}

// pop data and print
void pop1()
{
	if (stack_empty() == 0)
	{
		//save data to temp
		struct Node* temp = top1;
		int data = temp->key;
		// move to stack2 for reverse binary num
		push2(data);
		//make top1 point node that under the last node
		top1 = temp->next;
		//delete last stack1 node
		free(temp);
		// repeat pop1
		pop1();
	}
	// move stack1 binary num to stack2 finish call pop2
	pop2();
}

void pop2()
{
	//top2 == NULL means printf is finished
	if (top2 != NULL)
	{
		//save data to temp and print data
		struct Node* temp = top2;
		int data = temp->key;
		// print top2 node binary num
		printf(" %d", data);
		//make top2 point node that under the last node
		top2 = temp->next;
		//delete last node
		free(temp);
		//repeat
		pop2();
	}
}

