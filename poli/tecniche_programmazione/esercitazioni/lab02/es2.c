#include <stdio.h>

int recursive_fib(int n);
void fib(int n);

int main(void)
{
    int n;
    printf("\nHow many numbers of the Fibonacci's series you want display:\t");
    scanf("%d", &n);

    fib(n);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", recursive_fib(i));

    return 0;
}

void fib(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a >= b ? b : a);
        if (a >= b)
            b = a + b;
        else
            a = a + b;
    }
}

int recursive_fib(int n)
{
    if (n <= 1)
        return n;
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}