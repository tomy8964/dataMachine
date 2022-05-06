#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RMAX 100

//Count 45 unique numbers using global variable j
int j = 0;

//To check last node
int k = 0;

//check 13,21,53,72,91 is founded
int c = 0;

//structure definition
typedef struct node
{
	int data;
	struct node* left, * right;
	int ht;
}node;

//function definition
node* insert(node*, int);
void preorder(node*);
int preorder1(node*);
void preorder2(node*);
void preorder3(node*);
void preorder4(node*);
void preorder5(node*);
int height(node*);
node* rotateright(node*);
node* rotateleft(node*);
node* RR(node*);
node* LL(node*);
node* LR(node*);
node* RL(node*);
int BF(node*);

int main()
{
	// definition integer
	int first[200], i;
	// ramdom value by time
	srand(time(NULL));

	// make ramdom 198 numbers integers to array
	for (i = 2;i < 200;i++)
	{
		int random_no = 1 + (int)rand() % RMAX;
		first[i] = random_no;
	}

	// Add '17' '55' to the list
	first[0] = 17;
	first[1] = 55;

	//empty tree
	node* root = NULL;

	// reset i
	i = 0;

	//make 45 unique integer arrays
	while (j < 45)
	{
		root = insert(root, first[i]);
		i++;
		j++;
	}

	printf("Search the tree for keys 13, 21, 53, 72, 91\n");
	if (preorder1(root) == 1)
	{
		printf("Nothing is founded\n");
	}
	printf("\n");
	preorder2(root);
	printf("\n");
	printf("Search and print all keys < 17\n");
	preorder3(root);
	printf("\n");
	printf("Search and print all keys > 55\n");
	preorder4(root);
	printf("\n");
	printf("Search and print all keys between 17 and 55 (not including 17 or 55)\n");
	preorder5(root);

	return 0;
}

node* insert(node* T, int x)
{
	if (T == NULL)
	{
		T = (node*)malloc(sizeof(node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	// It's duplicated number
	else if (x == T->data)
	{
		j--;
	}
	else
		// insert in right subtree
		if (x > T->data)
		{
			T->right = insert(T->right, x);
			if (BF(T) == -2)
				if (x > T->right->data)
					T = RR(T);
				else
					T = RL(T);
		}
	// insert in left subtree
		else
			if (x < T->data)
			{
				T->left = insert(T->left, x);
				if (BF(T) == 2)
					if (x < T->left->data)
						T = LL(T);
					else
						T = LR(T);
			}

	// Check height
	T->ht = height(T);

	//return root
	return(T);
}

//calculate height
int height(node* T)
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	if (lh > rh)
		return(lh);

	return(rh);
}

// rotate to right
node* rotateright(node* x)
{
	node* y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}

// rotate to left
node* rotateleft(node* x)
{
	node* y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);

	return(y);
}

// It's RR state
node* RR(node* T)
{
	T = rotateleft(T);
	return(T);
}

// It's LL state
node* LL(node* T)
{
	T = rotateright(T);
	return(T);
}

// It's LR state
node* LR(node* T)
{
	// rotate T->left to left
	T->left = rotateleft(T->left);
	// rotate to right
	T = rotateright(T);
	return(T);
}

// It's RL state
node* RL(node* T)
{
	// rotate T->right to right
	T->right = rotateright(T->right);
	// rotate to right
	T = rotateleft(T);
	return(T);
}

// calculate the difference of level between left and right subtrees 
int BF(node* T)
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;
	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	return(lh - rh);
}

//traversal the tree by preorder
void preorder(node* T)
{
	if (T != NULL)
	{
		printf("%d\n", T->data);
		preorder(T->left);
		preorder(T->right);
	}
}

// Search the tree for keys 13, 21, 53, 72, 91 (and print the result)
int preorder1(node* T)
{
	if (T != NULL)
	{
		// if 13 founded
		if (T->data == 13)
		{
			printf("%d is founded\n", T->data);
			c = 1;
		}
		// if 21 founded
		else if (T->data == 21)
		{
			printf("%d is founded\n", T->data);
			c = 1;
		}
		// if 53 founded
		else if (T->data == 53)
		{
			printf("%d is founded\n", T->data);
			c = 1;
		}
		// if 72 founded
		else if (T->data == 72)
		{
			printf("%d is founded\n", T->data);
			c = 1;
		}
		// if 91 founded
		else if (T->data == 91)
		{
			printf("%d is founded\n", T->data);
			c = 1;
		}
		preorder1(T->left);
		preorder1(T->right);
	}
	
	//nothing is founded
	if (c==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Search and print the highest key
void preorder2(node* T)
{
	if (T != NULL)
	{
		//last preorder key is highest key
		if (k == 44)
		{
			printf("%d is the highest key.\n", T->data);
		}
		k++;
		preorder2(T->left);
		preorder2(T->right);
	}
}

//Search and print all keys < 17
void preorder3(node* T)
{
	if (T != NULL)
	{
		//if data < 17, print data
		if (T->data < 17)
		{
			printf("%d\n", T->data);
		}
		preorder3(T->left);
		preorder3(T->right);
	}
}

//Search and print all keys > 55
void preorder4(node* T)
{
	if (T != NULL)
	{
		// if data > 55, print data
		if (T->data > 55)
		{
			printf("%d\n", T->data);
		}
		preorder4(T->left);
		preorder4(T->right);
	}
}

//Search and print all keys between 17 and 55 (not including 17 or 55)
void preorder5(node* T)
{
	if (T != NULL)
	{
		//if 17 < data < 55, print data
		if ((T->data > 17)&&(T->data<53))
		{
			printf("%d\n", T->data);
		}
		preorder5(T->left);
		preorder5(T->right);
	}
}