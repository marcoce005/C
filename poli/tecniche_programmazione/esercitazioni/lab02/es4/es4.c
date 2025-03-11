#include <stdio.h>

void analize_output(char s[20], int result[2]);

int main(void)
{
    int a, b, result[2] = {0, 0}; // result = {pari, dispari}
    char str[20];

    printf("\t\t\t\tAnalize output of a prod\n\n");
    printf("Insert first number [integer]:\t");
    scanf("%d", &a);
    printf("Insert second number [integer]:\t");
    scanf("%d", &b);

    sprintf(str, "%d", a * b);

    analize_output(str, result);

    printf("\nEven digit:\t%d\nOdd digit:\t%d\nTot digits:\t%d", result[0], result[1], result[0] + result[1]);

    return 0;
}

void analize_output(char s[20], int result[2])
{
    int i = 0;
    for (;;)
    {
        if (s[i] == '\0')
            return;

        if ((s[i++] - '0') % 2 == 0)
            result[0]++;
        else
            result[1]++;
    }
}