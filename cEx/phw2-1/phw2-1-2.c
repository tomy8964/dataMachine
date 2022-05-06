#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tree node
struct node {
	int tree_level;
	int data;
	char child_key[10];
	struct node* lptr;
	struct node* rptr;
};

// tree pointer
typedef struct node node;
typedef node* tree_ptr;

void insertNode(tree_ptr* ptr, int treelevel, int data, char* childkey);
void preorder(tree_ptr ptr);

int main()
{
	// set rootptr
	tree_ptr rootptr = NULL;

	int choice = 0;
	int treelevel, data;
	char childkey[10];

	while (choice != 2)
	{
		printf("1.input general tree node 2.convert to binary tree\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Please type node data\n");
			scanf("%d %d %s", &treelevel, &data, childkey);
			//call insertNode function and give new node data
			insertNode(&rootptr, treelevel, data, childkey);
		}
		else if (choice == 2)
		{
			printf("preorder\n");
			preorder(rootptr);
		}
		else
		{
			break;
		}
	}

}

// make node and convert general tree to binary tree
void insertNode(tree_ptr* treeptr, int treelevel, int data, char* childkey)
{
	// treeptr point node is empty
	if (*treeptr == NULL)
	{
		*treeptr = malloc(sizeof(node));
		(*treeptr)->tree_level = treelevel;
		(*treeptr)->data = data;
		strcpy(((*treeptr)->child_key), childkey);
		(*treeptr)->lptr = NULL;
		(*treeptr)->rptr = NULL;
	}
	else
	{
		// input node is treeptr point node's child
		if (atoi((*treeptr)->child_key) == data)
		{
			//put node to lptr
			insertNode(&((*treeptr)->lptr), treelevel, data, childkey);
		}
		else
		{
			//treeptr had alreay left child
			if ((*treeptr)->lptr != NULL)
			{
				//move to right child node
				insertNode(&((*treeptr)->lptr), treelevel, data, childkey);
			}
			//treeptr had alreay rptr child
			else if ((*treeptr)->rptr != NULL)
			{
				//move to right child node
				insertNode(&((*treeptr)->rptr), treelevel, data, childkey);
			}
			//treeptr point node don't have child
			else
			{
				//move to left child node
				insertNode(&((*treeptr)->rptr), treelevel, data, childkey);
			}
		}
	}
}

//Traverse the binary tree and print the keys of the nodes visited in preorder
void preorder(tree_ptr treeptr)
{
	if (treeptr)
	{
		printf("%d\n", treeptr->data);
		preorder(treeptr->lptr);
		preorder(treeptr->rptr);
	}
}
