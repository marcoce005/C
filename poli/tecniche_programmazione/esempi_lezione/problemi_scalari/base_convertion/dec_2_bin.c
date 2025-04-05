#include <stdio.h>

void dec_2_bin(int n);

int main(void)
{
    int n;

    printf("\nInsert a decimal number:\t");
    scanf("%d", &n);

    printf("\nDecimal:\t%d\nBinary:\t", n);
    dec_2_bin(n);

    return 0;
}

void dec_2_bin(int n)
{
    int next;

    for (next = 1; next * 2 <= n; next *= 2);

    while (next > 0)
    {
        if (n >= next)
        {
            printf("1");
            n -= next;
        }
        else
            printf("0");

        next /= 2;
    }
}