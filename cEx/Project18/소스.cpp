#include <iostream>
using namespace std;

int main(void) {
	char* p = new char[100];
	strcpy(p, "This is a test");
	puts(p);
	delete[] p;

	return 0;
}