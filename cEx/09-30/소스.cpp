#include <stdio.h>
#include <string.h>

struct MyStruct {
	char name[100];
	int age;
	char hobby[100];
};

struct Itable {
	char key[100];
	struct MyStruct* address;
};

int main() 
{	
	 MyStruct dataset[5] = {
		{"Kim",39,"Tennis"},
		{"Ko", 15, "Soccer"},
		{"Lee",17,"Soccer"},
		{"Choi",21,"Tennis"},
		{"Park",10,"Tennis"}
	};

	 struct Itable index[5] = {
		 {"kim",&dataset[0]},
		 {"Ko",&dataset[1]},
		 {"Lee",&dataset[2]},
		 {"Choi",&dataset[3]},
		 {"Park",&dataset[4]}
	 };

	 int i;

	 for (i = 0; i < 5; i++) {
		 if (strcmp(index[i].key, "Lee") == 0 ||
			 strcmp(index[i].key, "Park") == 0) {
			 printf("name: %s age:%d hobby:%s\n",
				 index[i].address->name, 
				 index[i].address->age,
				 index[i].address->hobby
				 );
		 };
	 };


	return  0;
}