#include <stdio.h>
#include <malloc.h>
#include <string.h>

//table definition
struct table
{
	char hashkey[20];
	struct table* ptr;
}hashtable[33];

//search overflow bucket
void search_key_overflow(struct table* ptr, char* ch)
{
	//compare key and search key
	int ret = strcmp(ptr->hashkey, ch);

	//found 
	if (ret == 0)
	{
		printf("found\n");
	}
	else
	{
		// others key are in overflow bucket
		if (ptr->ptr != NULL)
		{
			search_key_overflow(ptr->ptr, ch);
		}
		//nothing is in overflow bucket
		else
		{
			printf("not found\n");
		}
	}
}

//delete overflow bucket
void delete_key_overflow(struct table* ptr, char* ch)
{
	//compare key and delete key
	int ret = strcmp(ptr->hashkey, ch);

	//found
	if (ret == 0)
	{
		//delete
		ptr->hashkey[0] = '\0';
		printf("deleted\n");
	}
	else
	{
		// others key are in overflow bucket
		if (ptr->ptr != NULL)
		{
			delete_key_overflow(ptr, ch);
		}
		//nothing is in overflow bucket
		else
		{
			printf("not found\n");
		}
	}
}

//insert overflow bucket
struct table* insert_key_overflow(struct table* ptr, char* ch)
{
	//empty overflow bucket
	if (ptr == NULL)
	{
		//make node and insert key
		ptr = (struct table*)malloc(sizeof(struct table));
		strcpy(ptr->hashkey, ch);
		printf("inserted\n");
		// others key are in overflow bucket
		if (ptr->ptr = NULL)
		{
			insert_key_overflow(ptr->ptr, ch);
		}
		//nothing is in overflow bucket
		else
		{
			ptr->ptr = NULL;
		}
	}
	// not empty
	else
	{
		//compare key and insert key
		int ret = strcmp(ptr->hashkey, ch);

		// is exists
		if (ret == 0)
		{
			printf("exists\n");
		}
		// others key are in overflow bucket
		else
		{
			//is deleted overflow bucket
			if ((ptr->hashkey[0]) == '\0')
			{
				//insert
				strcpy(ptr->hashkey, ch);
				printf("inserted\n");
			}
			// others key are in overflow bucket
			else
			{
				ptr->ptr = insert_key_overflow(ptr->ptr, ch);
			}
		}
	}

	return ptr;
}

void print_overflow(struct table* ptr)
{
	//empty
	if ((ptr) == NULL)
	{
		printf("\n");
	}
	//not empty print key
	else
	{
		printf("%s ",ptr->hashkey);
		print_overflow(ptr->ptr);
	}
}

//overflow occurs
struct table* overflow(struct table* ptr, char* ch)
 {
	//overflow bucket is empty
	if (ptr == NULL)
	{
		//make node and input key
		ptr = (struct table*)malloc(sizeof(struct table));
		strcpy(ptr->hashkey, ch);
		ptr->ptr = NULL;
	}
	// not empty
	else
	{
		overflow(ptr->ptr, ch);
	}

	return ptr;
}

// first input ket to hash table
void input_key()
{
	//file open and read
	FILE* fp = fopen("keyinput.txt", "r");
	fseek(fp, 0, SEEK_SET);
	//until finish
	while (!feof(fp))
	{
		//reset variable
		char ch[20] = { '\0' , };
		int ascii[20] = { 0 };
		//for one key
		while ((fscanf(fp, "%s", ch))==1)
		{
			int i = 0;
			int sum = 0;
			/*To hash, first sum the ASCII code of each alphabet 
			in the key, and then use the modulo function(sum % 33)*/
			while (ch[i] != NULL)
			{
				ascii[i] = (int)ch[i];
				i++;
			}
			for (int j = 0;j < i;j++)
			{
				sum = sum + ascii[j];
			}

			//empty bucket
 			if ((hashtable[(sum % 33)].hashkey[0]) == '\0')
			{
				strcpy(hashtable[(sum % 33)].hashkey,ch);
			}
			//not empty
			else
			{
				hashtable[(sum % 33)].ptr=overflow(hashtable[(sum % 33)].ptr, ch);
			}
		}
		
	}
	fclose(fp);
}

// search key
void search_key(char* ch)
{
	// calculate hash function
	int i = 0;
	int ascii[20] = { 0, };
	int sum = 0;
	while (ch[i] != NULL)
	{
		ascii[i] = (int)ch[i];
		i++;
	}
	for (int j = 0;j < i;j++)
	{
		sum = sum + ascii[j];
	}

	// compare key and search key
	int ret = strcmp(hashtable[(sum % 33)].hashkey, ch);

	//found
	if (ret == 0)
	{
		printf("found\n");
	}
	else
	{
		// others key are in overflow bucket
		if (hashtable[(sum % 33)].ptr != NULL)
		{
			search_key_overflow(hashtable[(sum % 33)].ptr, ch);
		}
		//nothing is in overflow bucket
		else
		{
			printf("not found\n");
		}
	}
}

//delete key
void delete_key(char* ch)
{
	// calculate hash function to find key
	int i = 0;
	int ascii[20] = { 0, };
	int sum = 0;
	while (ch[i] != NULL)
	{
		ascii[i] = (int)ch[i];
		i++;
	}
	for (int j = 0;j < i;j++)
	{
		sum = sum + ascii[j];
	}

	//compare key and delete key
	int ret = strcmp(hashtable[(sum % 33)].hashkey, ch);

	//found
	if (ret == 0)
	{
		//delete 
		hashtable[(sum % 33)].hashkey[0] = '\0';
		printf("deleted\n");
	}
	else
	{
		// others key are in overflow bucket
		if (hashtable[(sum % 33)].ptr != NULL)
		{
			delete_key_overflow(hashtable[(sum % 33)].ptr, ch);
		}
		//nothing is in overflow bucket
		else
		{
			printf("not found\n");
		}
	}
}

//insert key
void insert_key(char* ch)
{
	// calculate hash function to find key
	int i = 0;
	int ascii[20] = { 0, };
	int sum = 0;
	while (ch[i] != NULL)
	{
		ascii[i] = (int)ch[i];
		i++;
	}
	for (int j = 0;j < i;j++)
	{
		sum = sum + ascii[j];
	}

	//compare key and insert key
	int ret = strcmp(hashtable[(sum % 33)].hashkey, ch);

	//found
	if (ret == 0)
	{
		printf("exists\n");
	}
	else
	{
		//noting is in the bucket
		if ((hashtable[(sum % 33)].hashkey[0]) == '\0')
		{
			//insert
			strcpy(hashtable[(sum % 33)].hashkey, ch);
			printf("inserted\n");
		}
		// others key are in overflow bucket
		else if (hashtable[(sum % 33)].ptr != NULL)
		{
			hashtable[(sum % 33)].ptr =insert_key_overflow(hashtable[(sum % 33)].ptr, ch);
		}
	}
}

void main()
{
	// reset table
	for (int i = 0; i < 33;i++)
	{
		hashtable[i].hashkey[0] = '\0';
		hashtable[i].ptr = NULL;
	}
	
	//input key from file
	input_key();
	
	//print hash table
	for (int i = 0;i < 33;i++)
	{
		//print number of table
		printf("%d  ",i);
		//print key
		if ((hashtable[i].hashkey[0]) != '\0')
		{
			printf("%s ", hashtable[i].hashkey);
		}
		//if empty bucket
		else
		{
			printf("NULL");
		}
		//overflow bucket
		//empty
		if ((hashtable[i].ptr) == NULL)
		{
			printf("\n");
		}
		//not empty
		else
		{
			print_overflow(hashtable[i].ptr);
		}
	}

	//menu choice
	int choice = 0;
	while(choice!=4)
	{
		printf("\n\n1:search\n2:delete\n3:insert\n4:quit&print\n:");
		scanf("%d", &choice);

		//search
		if (choice == 1)
		{
			char ch[100] = { '\0' , };
			printf("search: ");
			scanf("%s", ch);
			search_key(ch);
		}
		//delete
		else if (choice == 2)
		{
			char ch[100] = { '\0' , };
			printf("delete: ");
			scanf("%s", ch);
			delete_key(ch);

		}
		//insert
		else if (choice == 3)
		{
			char ch[100] = { '\0' , };
			printf("insert: ");
			scanf("%s", ch);
			insert_key(ch);
		}
		else
		{
			break;
		}
	}

	//print hash table
	for (int i = 0;i < 33;i++)
	{
		//print number of table
		printf("%d  ", i);
		//print key
		if ((hashtable[i].hashkey[0]) != '\0')
		{
			printf("%s ", hashtable[i].hashkey);
		}
		//if empty bucket
		else
		{
			printf("NULL");
		}
		//overflow bucket
		//empty
		if ((hashtable[i].ptr) == NULL)
		{
			printf("\n");
		}
		//not empty
		else
		{
			print_overflow(hashtable[i].ptr);
		}
	}
}