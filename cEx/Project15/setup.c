/*
setup code(array_open, print_array, linked_open, print_linked) - 202035318 �����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DATA_NUM 30

typedef struct DATA
{
	int tag;
	char date[20];
	char fee_paid[10];
	char name[25];
	int age;
	char organization[30];
	char job[15];
	struct DATA* next;
}Data;

//-----------------------------
//Function prototype
//-----------------------------

int array_open(Data*);
void print_array(Data*, int);
Data* linked_open();
void print_linked(Data*);

//-----------------------------
//MAIN
//-----------------------------

int main()
{
	Data regi_data[50];
	Data* regi_head;
	int data_num;

	data_num = array_open(regi_data);
	print_array(regi_data, data_num);

	printf("\n");

	regi_head = linked_open();
	print_linked(regi_head->next);

	return 0;
}

//-----------------------------
//Read registraion_data.txt and store the data in a struct array
//-----------------------------

int array_open(Data* regi_data)
{
	int i = 0, data_num = 0;
	FILE* regi_file;

	regi_file = fopen("registraion_data.txt", "r");
	if (regi_file == NULL)
		printf("file open error\n");
	else
	{
		while (fscanf(regi_file, "%d %*[/] %[^/] %*[/] %[^/] %*[/] %[^/] %*[/] %d %*[/] %[^/] %*[/] %s", &regi_data[i].tag, regi_data[i].date, regi_data[i].fee_paid, regi_data[i].name, &regi_data[i].age, regi_data[i].organization, regi_data[i].job) == 7)
			i++;
	}
	data_num = i;

	fclose(regi_file);

	return data_num;
}

//-----------------------------
//Print array
//-----------------------------

void print_array(Data* regi_data, int data_num)
{
	printf("===array===\n");

	for (int i = 0; i < data_num; i++)
		printf("%d %s %s %s %d %s %s\n", regi_data[i].tag, regi_data[i].date, regi_data[i].fee_paid, regi_data[i].name, regi_data[i].age, regi_data[i].organization, regi_data[i].job);
	printf("======\n");
}

//-----------------------------
//Store the data in a linked list
//-----------------------------

Data* linked_open()
{
	int i = 0;
	FILE* regi_file;
	Data* node;
	Data* head;
	Data* prev_node;

	head = (Data*)malloc(sizeof(Data));
	prev_node = head;

	regi_file = fopen("registraion_data.txt", "r");
	if (regi_file == NULL)
		printf("file open error\n");
	else
	{
		node = (Data*)malloc(sizeof(Data));
		while (fscanf(regi_file, "%d %*[/] %[^/] %*[/] %[^/] %*[/] %[^/] %*[/] %d %*[/] %[^/] %*[/] %s", &node->tag, node->date, node->fee_paid, node->name, &node->age, node->organization, node->job) == 7)
		{
			prev_node->next = node;
			prev_node = node;
			node = (Data*)malloc(sizeof(Data));
		}
		free(node); //free trash node
		prev_node->next = NULL; //last node
	}

	fclose(regi_file);

	return head;
}

//-----------------------------
//Print linked list
//-----------------------------

void print_linked(Data* ptr)
{
	printf("===linked list===\n");
	while (ptr != NULL)
	{
		printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
		ptr = ptr->next;
	}
	printf("======\n");
}