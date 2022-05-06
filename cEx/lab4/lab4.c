// 201835546 ÇÔ°Ç¿í
#include<stdio.h>

void fileCopy(const char* src, const char* tgt)
{
	FILE *inFile, *outFile; // file header
	char ch;
	int ich;  // ASCII code number of ch

	inFile = fopen(src,"r");
	if (inFile == NULL) {
		printf("Could not open data.txt!\n");
		exit(1);
	}
	
	outFile = fopen(tgt,"w");
	
	while ((ch = fgetc(inFile)) != EOF)
	{
		ich = ch; // input ch's ASCII code number to ich
		if ((ich <= 'z') && (ich >= 'a')) // if smail letter
		{
			ich = ich - ('a'-'A'); // ich change to uppercase ich
			ch = ich; // input uppercase ich number to ch
			fputc(ch, outFile); // print at file
		}
		else
		{
			fputc(ch, outFile); // print at file
		}
	}

	fclose(inFile);
	fclose(outFile);
}

int main()
{

	fileCopy("data.txt", "samedata.txt");
	return 1; 
}