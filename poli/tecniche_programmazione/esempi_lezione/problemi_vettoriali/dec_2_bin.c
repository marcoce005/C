#include <stdio.h>
#include <math.h>

#define MAX_BIT 32

int dec_2_bin(int v[], int n);

int main(void)
{
    int n, bits[MAX_BIT] = {0}, end;

    printf("\nInsert an number between 0 <-> %.0lf:\t", pow(2, MAX_BIT) - 1);
    scanf("%d", &n);

    if ((double)n > pow(2, MAX_BIT) || n < 0)
    {
        printf("\nError!!!");
        return -1;
    }

    end = dec_2_bin(bits, n);

    printf("\n%d\t-->\t", n);
    for (int i = end; i >= 0; i--)
        printf("%d", bits[i]);

    return 0;
}

int dec_2_bin(int v[], int n)
{
    int i;
    for (i = 0; n != 0; n /= 2)
        v[i++] = n % 2;
    return i - 1;
}