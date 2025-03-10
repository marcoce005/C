#include <stdio.h>

int MCD(int a, int b);

int main(void)
{
    int n, n2;

    printf("\nInsert the first number:\t");
    scanf("%d", &n);

    printf("\nInsert the second number:\t");
    scanf("%d", &n2);

    printf("\nMCD = %d", MCD(n, n2));

    return 0;
}

int MCD(int a, int b)
{
    int rest;
    do
    {
        if (a >= b)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        else
        {
            rest = b % a;
            b = a;
            a = rest;
        }
    } while (rest != 0);
    return a >= b ? a : b;
}