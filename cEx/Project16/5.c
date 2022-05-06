/*
setup code(array_open, print_array, linked_open, print_linked)
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
void ageOrder(Data*, int);

//-----------------------------
//MAIN
//-----------------------------

int main()
{
	Data regi_data[50];
	Data* regi_head;
	int data_num;
	int age_array;

	data_num = array_open(regi_data);

	printf("\n");

	regi_head = linked_open();

	ageOrder(regi_data,data_num);

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

//------------------------------------------------------------
// Sort array age order & print 5-1.txt - 201835546 함건욱
//-------------------------------------------------------------

void ageOrder(Data* array, int data_num) //bring array and data_num
{
	Data temp;

	for (int i = 0; i < data_num;i++) //sort data age order
	{
		for (int j = 0;j < data_num - i;j++)
		{
			if (array[j].age > array[j + 1].age)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (int k = 0;k < data_num;k++)
	{
		temp = array[k + 1];
		array[k] = temp;
	}

	FILE* age_file; // FIle header

	age_file = fopen("5-1.txt", "w"); //write data to 5-1.txt
	{
		fprintf(age_file,"===age order array===\n");
		for (int i = 0; i < data_num; i++)
		{
			fprintf(age_file, "%d %s %s %s %d %s %s\n", array[i].tag, array[i].date, array[i].fee_paid, array[i].name, array[i].age, array[i].organization, array[i].job);
		}
		fprintf(age_file,"======\n");
	}

	fclose(age_file);

}