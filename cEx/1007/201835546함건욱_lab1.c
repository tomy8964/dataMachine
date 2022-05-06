소프트웨어구현패턴 화,수 3,4교시 Lab.1
201835546 함건욱


#include<stdio.h>
#include<string.h>

int main() {
    char text[1000] = "tiger tiker tigger tiggggger tier"; // text 
    char word[50]; //input word
    char word1[100], word2[100]; // divide input word 2part > word1, word2

    int cursor = 0; 
    int i, j, count = 0;
    int type = 0; //check input type
    int inputtype = 0; //input type, Exact match is 0
    int count2 = 0; // '#' count times
    
    printf("%s\n", text);
    
    printf("input word: \n"); //input word
    scanf_s("%s", word, sizeof(word));
    
    printf("input word:%s\n", word); //show what you input


    while (word[type] != NULL) // checking input time by looping ex)nothing,*,#,##
    {
        if (word[type] == '*') 
        {
            inputtype = 1; // '*' > inputtype 1
            break;
        }
        else if (word[type] == '#') // '#' > inputype 2
        {
            while (word[type] != NULL)
            {
                
                if (word[type] == '#')
                {
                    count2++; // count '#'times
                }
                type++;
            }
            inputtype = 2;
            break;
        }

        type++;
    }

    switch (inputtype)
    {
    case 1: // Partial match ('*')
    {
        while (1) // Looping for divide word to part1, part2
        {
            if (word[cursor] == '*') // meet * 
            {
                cursor++; // move cursor 1times to pass *
                int i = 0;
                while (word[cursor] != NULL) // copy word after * to word2 before meet NULL
                {
                    word2[i] = word[cursor]; 
                    cursor++;
                    i++;
                    word2[i + 1] = NULL; // put NULL the end of the word2
                }
                break;
            }
            else 
            {
                strncpy_s(word1, sizeof(word1), word, cursor + 1); // copy word before * to word1
            }
            cursor++;
        }

        while (text[cursor] != NULL) //Looping before the text meet NULL
        {
            if (text[cursor] == word1[0]) //Find the first letter of the first part of the input word
            {
                for (i = 0;i < strlen(word1);i++) //Repeat the length of the first part of the input word
                {
                    if (text[cursor] == word1[i]) //It's matching

                    {
                        if (i == strlen(word1 + 1)) //All match > second part of the input word
                        {
                            while (text[cursor] != ' ') //Repeat before meet ' '
                            {
                                cursor++;
                                
                                if (text[cursor] == word2[0]) //Find the first letter of the second part of the input word
                                {
                                    for (j = 0;j < strlen(word2);j++) //Repeat the length of the second of the serch string
                                    {
                                        if (text[cursor] == word2[j]) //It's matching

                                        {
                                            if (j == strlen(word2 + 1)) //All match > count++ and break
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

        break;
    }

    case 0: // Exact match

    {
        while (text[cursor] != NULL) //looping
        {
            if (text[cursor] == word[0]) //Find the first character of a input word
            {
                int i = 0;

                for (unsigned i = 0; i < strlen(word);i++) //Looping the length of the string
                {
                    if (text[cursor] == word[i]) //It's match

                    {
                        if (i == strlen(word + 1)) //All match > count++ and break
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
    }

    case 2: // Partial match ('#')
    {
        switch (count2)
        {
        case 1: // # 1times
        {
            while (1) // Looping for divide word to part1, part2
            {
                if (word[cursor] == '#') // meet '#'
                {
                    cursor++; // move cursor 1times
                    int i = 0;
                    while (word[cursor] != NULL) // copy word after # to word2 before meet NULL
                    { 
                        word2[i] = word[cursor];
                        cursor++;
                        i++;
                        word2[i + 1] = NULL; // put NULL the end of the word2
                    }
                    break;
                }
                else
                {
                    strncpy_s(word1, sizeof(word1), word, cursor + 1); // copy word before * to word1
                }
                cursor++;
            }
            
            cursor = 0; // reset cursor
            
            while (text[cursor] != NULL)
            {
                if (text[cursor] == word1[0]) //Find the first letter of the first part of the input word
                {
                    for (i = 0;i < strlen(word1);i++) //Repeat the length of the first part of the input word
                    {
                        if (text[cursor] == word1[i]) //It's matching

                        {
                            if (i == strlen(word1 + 1)) //All match > second part of the input word
                            {
                                
                                    cursor++;
                                    cursor++; // move cursor 2times to pass #
                                    
                                    if (text[cursor] == word2[0]) //Find the first letter of the second part of the input word
                                    {
                                        for (j = 0;j < strlen(word2);j++) //Repeat the length of the second of the serch string
                                        {
                                            if (text[cursor] == word2[j]) //It's matching

                                            {
                                                if (j == strlen(word2 + 1)) //All match > count++ and break
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
            break;
        }

        case 2: // # 2times
        {
            while (1) // Looping for divide word to part1, part2
            {
                if (word[cursor] == '#') // meet '#'
                {
                    cursor++;
                    cursor++; //# is 2times > move cursor 2times
                    int i = 0;
                    while (word[cursor] != NULL) // copy word after ## to word2 before meet NULL
                    {
                        word2[i] = word[cursor];
                        cursor++;
                        i++;
                        word2[i + 1] = NULL;
                    }
                    break;
                }
                else
                {
                    strncpy_s(word1, sizeof(word1), word, cursor + 1); // copy word before ## to word1
                }
                cursor++;
            }

            cursor = 0; // reset cursor
            
            while (text[cursor] != NULL)
            {
                if (text[cursor] == word1[0]) //Find the first letter of the first part of the input word
                {
                    for (i = 0;i < strlen(word1);i++) //Repeat the length of the first part of the input word
                    {
                        if (text[cursor] == word1[i]) //It's matching

                        {
                            if (i == strlen(word1 + 1)) //All match > second part of the input word
                            {

                                cursor++;
                                cursor++;
                                cursor++; //# 2times > cursor move 3times

                                if (text[cursor] == word2[0]) //Find the first letter of the second part of the input word
                                {
                                    for (j = 0;j < strlen(word2);j++) //Repeat the length of the second of the serch string
                                    {
                                        if (text[cursor] == word2[j]) //It's matching

                                        {
                                            if (j == strlen(word2 + 1)) //All match > count++ and break
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
            break;
        }
        }
    }
    }
    printf("Number of times: %d\n", count); // print count

    return 0;


}
