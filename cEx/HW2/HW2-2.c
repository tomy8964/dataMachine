#include <stdio.h>

int main() {
    
    int count = 0;
    int num;
    
    //input integer
    printf("Please type integer(5 digits or fewer):\n");
    scanf("%d", &num);

    //first digit of number
    if (num % 10 == 9) 
    {
        count++;
    }
    //second digit of number
    if (num / 10 % 10 == 9) 
    {
        count++;
    }
    //third digit of number
    if (num / 100 % 10 == 9) 
    {
        count++;
    }
    //fourth digit of number
    if (num / 1000 % 10 == 9) 
    {
        count++;
    }
    //fifth digit of number
    if (num / 10000 == 9) 
    {
        count++;
    }

    //print how many 9s in integer
    printf("how many digits in the integer are 9s?\n%d", count);

    return 0;
}