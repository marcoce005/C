#include <stdio.h>

void print_vet(int len, int v[len]);
void insertion_sort(int len, int v[len]);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    insertion_sort(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void insertion_sort(int len, int v[])
{
    int index;
    for (int i = 1; i < len; i++)
    {
        index = i;
        while (v[index] < v[index - 1] && index > 0)
        {
            v[index] = v[index] ^ v[index - 1];
            v[index - 1] = v[index] ^ v[index - 1];
            v[index] = v[index] ^ v[index - 1];
            index--;
        }
    }
}

void print_vet(int len, int v[])
{
    for (int i = 0; i < len; i++)
        printf(" %d", v[i]);
}