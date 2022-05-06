#include <stdio.h>
#include <string.h>

int main()
{
    char string[1000] = "¡°My name is hong gil dong. My brother is hong je dong. My sister is hong gilja, and her friend is hongdong.";
    char s_string[100] = "hong * dong";
    char s_s1[10] = "hong";
    char s_s2[10] = "dong";
    int i, j, count = 0;
    int cursor = 0;

    while (string[cursor] != NULL)
    {
        if (string[cursor] == s_s1[0]) //Find the first letter of the first part of the search string
        {
            for (i = 0;i < strlen(s_s1);i++) //Repeat the length of the first part of the search string
            {
                if (string[cursor] == s_s1[i]) //It's matching

                {
                    if (i == strlen(s_s1 + 1)) //All match > second part of the search string
                    {
                        while (string[cursor] != NULL) //Repeat by meet NULL
                        {
                            cursor++;
                            if (string[cursor] == s_s2[0]) //Find the first letter of the second part of the search string
                            {
                                for (j = 0;j < strlen(s_s2);j++) //Repeat the length of the second of the serch string
                                {
                                    if (string[cursor] == s_s2[j]) //It's matching

                                    {
                                        if (j == strlen(s_s2 + 1)) //All match > count++ and break
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
                        }
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