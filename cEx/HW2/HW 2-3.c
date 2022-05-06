#include <stdio.h>

int main(void)
{
    float fahrenheit;
    // set celsius 30
    int celsius = 30;

    printf("Celsius to Fahrenheit\n");

    // 30 to 50 repeat
    while (celsius <= 50)
    {
        fahrenheit = (9.0 / 5.0) * celsius + 32.0;
        printf("%d         %0.2f\n", celsius, fahrenheit);
        // +1 to celsius
        celsius++;
    }

    return 0;
}