#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>

int main()
{
    char string[1000] = "A thief named hong gil dong lived with freinds named hhhong gil dong and hong gil don is a village named hong gil dong village.";
    char s_string[100] = "hong gil dong";
    int i,count, cursor = 0;
    int cursor = 0;
    for (cursor = 0;cursor<strlen(string+1);cursor++) 
    {
        while(1) {
            if (string[cursor] == s_string[0]) //h찾기
            {
                for (i = 0;i < strlen(s_string + 1);i++) {
                    if (string[cursor] == s_string[i]) {
                        cursor++;
                        if (i == strlen(s_string)) {
                            count++;
                            break;
                        }
                    }
                    else {
                        i = 0;
                        cursor++;
                    }
                }
            }
            else {
                printf("Not Founded\n");
            }
        }
        
    }

    printf("%d times founded", count);


}