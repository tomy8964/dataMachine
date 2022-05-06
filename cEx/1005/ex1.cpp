#include <stdio.h>
#include <string.h>

int main()
{
    char string[1000] = "A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village.";
    char s_string[100] = "hong gil dong";
    int i, count=0;
    int cursor = 0;
    
    while(string[cursor]!=NULL)
    {
       if (string[cursor] == s_string[0]) //Find the first character of a search string
       {
           for (i = 0;i < strlen(s_string);i++)
           {
               if (string[cursor]==s_string[i]) 
               {
                   if (s_string[i]==NULL)
                   {
                       i = 0;
                       count++;
                       break;
                       printf("Found\n");
                   }  
                   else
                   {
                       cursor++;
                   }
               }
               else
               {
                   break;
               }
           }
       }
       else
       {
           cursor++;
       }
       cursor++;
    }
    
    
    printf("%d Founded\n", count);



    
    return 0;
}