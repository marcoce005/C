#include <stdio.h>

int main(void)
{
    char operation;
    float val1, val2, ans;

    printf("\nInsert the operation [+][-][*][/]:\t");
    operation = getchar();

    printf("\nInsert value 1:\t");
    scanf("%f", &val1);
    printf("\nInsert value 2:\t");
    scanf("%f", &val2);

    switch (operation)
    {
    case '+':
        ans = val1 + val2;
        break;

    case '-':
        ans = val1 - val2;
        break;

    case '*':
        ans = val1 * val2;
        break;

    case '/':
        ans = val1 / val2;
        break;

    default:
        printf("\nWrong operation.");
        return -1;
    }

    printf("\n%.2f %c %.2f = %.2f", val1, operation, val2, ans);

    return 0;
}