#include <stdio.h>
#include <malloc.h>

typedef struct quadnode {
	float x;
	float y;
	struct quadnode* quadrant1;
	struct quadnode* quadrant2;
	struct quadnode* quadrant3;
	struct quadnode* quadrant4;
}quadnode;

typedef struct interiornode {
	struct quadnode* quadrant1;
	struct quadnode* quadrant2;
	struct quadnode* quadrant3;
	struct quadnode* quadrant4;
};

quadnode* build_tree(float x, float y, quadnode *ptr)
{
	if (ptr == NULL)
	{
		ptr = (quadnode*)malloc(sizeof(quadnode));
		ptr->x = x;
		ptr->y = y;
		ptr->quadrant1 = NULL;
		ptr->quadrant2 = NULL;
		ptr->quadrant3 = NULL;
		ptr->quadrant4 = NULL;
	}
	else if ((x < ptr->x) && (y >= ptr->y))
	{
		ptr->quadrant1 = build_tree(x, y, ptr->quadrant1);
	}
	else if ((x >= ptr->x) && (y > ptr->y))
	{
		ptr->quadrant2 = build_tree(x, y, ptr->quadrant2);
	}
	else if ((x > ptr->x) && (y <= ptr->y))
	{
		ptr->quadrant3 = build_tree(x, y, ptr->quadrant3);
	}
	else if ((x <= ptr->x) && (y < ptr->y))
	{
		ptr->quadrant4 = build_tree(x, y, ptr->quadrant4);
	}
	
	return ptr;
}

point_search(float x, float y,quadnode *ptr)
{
	if (ptr != NULL)
	{
		if ((x == ptr->x) && (y == ptr->y))
		{
			printf("Search Complete\n");
		}
		else if ((x < ptr->x) && (y >= ptr->y))
		{
			point_search(x, y, ptr->quadrant1);
		}
		else if ((x >= ptr->x) && (y > ptr->y))
		{
			point_search(x, y, ptr->quadrant2);
		}
		else if ((x > ptr->x) && (y <= ptr->y))
		{
			point_search(x, y, ptr->quadrant3);
		}
		else if ((x <= ptr->x) && (y < ptr->y))
		{
			point_search(x, y, ptr->quadrant4);
		}
	}
	else
	{
		printf("Search Failed\n");
	}

	
}

range_search(quadnode *ptr)
{
	if(ptr != NULL)
	{
		if (((ptr->x) <= 10.0) && ((ptr->x) >= 4.0))
		{
			if (((ptr->y) <= 9.0) && ((ptr->y) >= 4.0))
			{
				printf("%f,%f\n", ptr->x, ptr->y);
			}
		}
		range_search(ptr->quadrant1);
		range_search(ptr->quadrant2);
		range_search(ptr->quadrant3);
		range_search(ptr->quadrant4);
	}
}
void main()
{
	quadnode* root = NULL;
	root = build_tree(10.5,10.5,root);
	int choice=0;
	float x, y;
	
	while (choice != 4)
	{
		printf("1.insert 2.search 3.range_search 4.quit\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("input x,y\n");
			scanf("%f %f",&x,&y);
			root=build_tree(x, y, root);
		}
		else if (choice == 2)
		{
			printf("input x,y\n");
			scanf("%f %f", &x, &y);
			point_search(x, y, root);
		}
		else if (choice == 3)
		{
			printf("To test the range_search function, specify a rectangle with(left x = 4, left y = 4), width6, height 5.\n");
			range_search(root);
		}
	}

}