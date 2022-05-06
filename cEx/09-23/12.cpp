#include<stdio.h>
int main()
{
    struct MonthDays
    {
        char name[10];
        int days;
    };
    struct MonthDays convert[12] = {
        {"January", 31},
        {"Feburary", 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}
    };
    for (int i = 0; i < 12; i++) 
        printf("%d %s : %d\n", i + 1, convert[i].name, convert[i].days);
    return 0;
}