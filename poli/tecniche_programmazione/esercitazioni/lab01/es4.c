#include <stdio.h>

#define P 3.14

int main(void)
{
    int value;
    char figure, method;
    float ans;

    printf("\nSelect the figure:\n[Q] --> for square\n[C] --> circle\n--> ");
    scanf("%c", &figure);
    getchar();

    switch (figure)
    {
    case 'Q':
        printf("\nOK, where going to calculate square's area.\nWhat do you want use to calculate:\n[L] --> side\n[D] --> diagonal\n--> ");
        scanf("%c", &method);
        break;

    case 'C':
        printf("\nOK, where going to calculate circle's area.\nWhat do you want use to calculate:\n[R] --> radius\n[D] --> diameter\n--> ");
        scanf("%c", &method);
        break;

    default:
        printf("\nWrong input, retry!");
        return -1;
    }

    printf("\nInsert value:\t");
    scanf("%d", &value);

    if (figure == 'Q' && method == 'L')
        ans = value * value;
    else if (figure == 'Q' && method == 'D')
        ans = (float)value * value / 2;
    else if (figure == 'C' && method == 'R')
        ans = (float)value * value * P;
    else if (figure == 'C' && method == 'D')
        ans = ((float)value * value * P) / 4;

    printf("\nResult:\t%.1f", ans);

    return 0;
}