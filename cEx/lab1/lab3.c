//201835546 함건욱


#include<stdio.h>
#include<string.h>

int main()
{
	char text[100] = "finalexamiscanseled";
	char keyword[100] = "lemon";
	int itext[100];
	int ikeyword[100];
	int i=0,j=0,k=0;

	printf("\n");
	printf("original text:%s\n", text);
	printf(" text:");
	for (i = 0;i < strlen(text);i++)
	{
		if ((text[i] <= 'z') && (text[i] >= 'a')) // if smail letter
		{
			itext[i] = text[i] - 'a';
		}
		else if ((text[i] <= 'Z') && (text[i] >= 'A'))  // if big letter
		{
			itext[i] = text[i] - 'A';
		}
		else itext[i] = text[i] % 26; // if other character

		printf("%d ", itext[i]);
	}
	printf("\n");
	printf("\n");
	printf("+keyword\n lemon : ");
	for (j = 0;j < strlen(keyword);j++)
	{
		if ((keyword[j] <= 'z') && (keyword[j] >= 'a')) // if smail letter
		{                   
			ikeyword[j] = keyword[j] - 'a';
		}
		else if ((keyword[j] <= 'Z') && (keyword[j] >= 'A')) // if big letter
		{             
			ikeyword[j] = keyword[j] - 'A';
		}
		else
		{
			ikeyword[j] = ikeyword[j] % 26;    // if other character                       //영어소문자대문자아닌것
		}
		printf("%d ", ikeyword[j]);
	}
	printf("\n");
	printf("\n");
	printf(" cipertext:");
	for (k = 0;k < strlen(text);k++)
	{
		if (text[k] >= 'a' && text[k] <= 'z') // if smail letter
		{
			text[k] = ((text[k] - 'a' + ikeyword[k % strlen(keyword)]) % 26) + 'a';
			
		}
		else if (text[k] >= 'A' && text[k] <= 'Z') // if big letter
		{
			text[k] = ((text[k] - 'A' + ikeyword[k % strlen(keyword)]) % 26) + 'A';
			
		}
		printf("%d ", text[k]-'a');
	}

	printf("\ncipertext:%s\n",text);
	



	return 0;
}