#include <stdio.h>
#include <string.h>

int main()
{
    char string[200] = "A thief named hong gil dong lived with friends named hong gildon and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village.";
    char s_string[100] = "hong gil dong";
    int i, count = 0;
    int cursor = 0;

    while (string[cursor] != NULL)
    {
        if (string[cursor] == s_string[0]) //Find the first character of a search string
        {
            for (i = 0;i < strlen(s_string);i++) //Repeat the length of the string
            {
                if (string[cursor] == s_string[i]) //It's match

                {
                    if (i == strlen(s_string + 1)) //All match > count++ and break
                    {
                        count++;
                        break;
                    }
                    else
                    {
                        cursor++; // move cursor
                    }
                }
                else
                {
                    cursor--; // Not all match
                    break;
                }
            }
        }
        cursor++;    // Move cursor
    }

    printf("%d Founded\n", count); // Print count

    return 0;
}