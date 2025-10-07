#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b);

int main(void)
{
    int i, n1, n2;

    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        n1 = rand() % 100;
        n2 = rand() % 100;
        printf("gcd(%d, %d) --> %d\n", n1, n2, gcd(n1, n2));
    }

    return 0;
}

int gcd(int a, int b)
{
    if (b > a)
        return gcd(b, a);

    if (a == b || b == 0)
        return a;

    if (b == 1)
        return 1;

    if (a % 2 == 0 && b % 2 == 0)
        return 2 * gcd(a / 2, b / 2);
    if (a % 2 == 1 && b % 2 == 0)
        return gcd(a, b / 2);
    if (b % 2 == 1 && a % 2 == 0)
        return gcd(a / 2, b);
    if (a % 2 == 1 && b % 2 == 1)
        return gcd((a - b) / 2, b);
}