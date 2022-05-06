#include <stdio.h>
#include <malloc.h>

// define node struct
typedef struct node
{
	float xp;
	float yp;
	// decide whether interior node or not
	int onoff;
	// height
	float h;
	// width
	float w;
	struct node* q1;
	struct node* q2;
	struct node* q3;
	struct node* q4;
}node;

//divide 21*21
node* build_tree(float x, float y,float h, float w, node* ptr)
{
	// When the width and height are less than 1, finish divide
	if (w<=1 || h <= 1)
	{
		ptr = NULL;
		return ptr;
	}
	else
	{
		ptr = (node*)malloc(sizeof(node));
		ptr->xp = x;
		ptr->yp = y;
		ptr->w = w/2;
		ptr->h = h/2;
		ptr->onoff = 0;
		ptr->q1 = build_tree(x - w / 2, y + w / 2, h / 2, w / 2, ptr->q1);
		ptr->q2 = build_tree(x + w / 2, y + w / 2, h / 2, w / 2, ptr->q2);
		ptr->q3 = build_tree(x + w / 2, y - w / 2, h / 2, w / 2, ptr->q3);
		ptr->q4 = build_tree(x - w / 2, y - w / 2, h / 2, w / 2, ptr->q4);
	}
	return ptr;
}

//insert leaf node
insert_node(float x, float y, node* ptr)
{
	// if enter the leaf node, input data
	if (ptr == NULL)
	{
		ptr = (node*)malloc(sizeof(node));
		ptr->xp = x;
		ptr->yp = y;
		ptr->onoff= 1;
		ptr->q1 = NULL;
		ptr->q2 = NULL;
		ptr->q3 = NULL;
		ptr->q4 = NULL;
	}
	else if ((x < ptr->xp) && (y >= ptr->yp))
	{
		// if leaf node
		if (ptr->q1 == NULL)
		{
			ptr->q1=insert_node(x, y, ptr->q1);
		}
		// go to q1
		else
		{
			insert_node(x, y, ptr->q1);
		}
	}
	else if ((x >= ptr->xp) && (y > ptr->yp))
	{
		// if leaf node
		if (ptr->q2 == NULL)
		{
			ptr->q2 = insert_node(x, y, ptr->q2);
		}
		// go to q2
		else
		{
			insert_node(x, y, ptr->q2);
		}
	}
	else if ((x > ptr->xp) && (y <= ptr->yp))
	{
		// if leaf node
		if (ptr->q3 == NULL)
		{
			ptr->q3 = insert_node(x, y, ptr->q3);
		}
		// go to q3
		else
		{
			insert_node(x, y, ptr->q3);
		}
	}
	else if ((x <= ptr->xp) && (y < ptr->yp))
	{
		// if leaf node
		if (ptr->q4 == NULL)
		{
			ptr->q4 = insert_node(x, y, ptr->q4);
		}
		// go to q4
		else
		{
			insert_node(x, y, ptr->q4);
		}
	}
}

// search point
point_search(float x, float y, node* ptr)
{
	if (ptr != NULL)
	{
		// point is exist
		if ((x == ptr->xp) && (y == ptr->yp))
		{
			//its leaf node
			if ((ptr->onoff) == 1)
			{
				printf("Search Complete\n");
			}
		}
		else if ((x < ptr->xp) && (y >= ptr->yp))
		{
			// go to q1
			point_search(x, y, ptr->q1);
		}
		else if ((x >= ptr->xp) && (y > ptr->yp))
		{
			// go to q2
			point_search(x, y, ptr->q2);
		}
		else if ((x > ptr->xp) && (y <= ptr->yp))
		{
			// go to q3
			point_search(x, y, ptr->q3);
		}
		else if ((x <= ptr->xp) && (y < ptr->yp))
		{
			// go to q4
			point_search(x, y, ptr->q4);
		}
	}
	// search failed
	else
	{
		printf("Search Failed\n");
	}
}

// search for range
range_search(int lx,int ly, int width, int height, node* ptr)
{
	if (ptr != NULL)
	{
		// point is in range
		if (((ptr->xp) < (lx + width)) && ((ptr->xp) > lx))
		{
			// point is in range
			if (((ptr->yp) < (ly + height)) && ((ptr->yp) > ly))
			{
				// point is leaf node
				if ((ptr->onoff) == 1)
				{
					printf("%d,%d\n\n", (int)ptr->xp, (int)ptr->yp);
				}
			}
		}
		range_search(lx, ly, width, height, ptr->q1);
		range_search(lx, ly, width, height, ptr->q2);
		range_search(lx, ly, width, height, ptr->q3);
		range_search(lx, ly, width, height, ptr->q4);
	}
}

void main()
{
	// empty root
	node* root = NULL;
	// build tree 21*21
	root = build_tree(10.5,10.5,10.5,10.5,root);
	int choice = 0;
	float x, y;

	while (choice != 4)
	{
		// choose what you do
		printf("1.insert 2.search 3.range_search 4.quit\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			// type data for input
			printf("input x,y\n");
			scanf("%f %f", &x, &y);
			insert_node(x, y, root);
		}
		else if (choice == 2)
		{
			// type data for search
			printf("search x,y\n");
			scanf("%f %f", &x, &y);
			point_search(x, y, root);
		}
		else if (choice == 3)
		{
			int lx, ly, width, height;
			printf("left x :");
			scanf("%d",&lx);
			printf("left y :");
			scanf("%d",&ly);
			printf("width :");
			scanf("%d",&width);
			printf("height :");
			scanf("%d",&height);
			range_search(lx,ly,width,height,root);
		}
	}
}