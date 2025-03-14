#include <stdio.h>

void print_vet(int len, int v[len]);
void bubble_sort(int len, int v[len]);

int main(void)
{
    int v[] = {3, 5, 7, 4, 8, 9, 4, 3, 2, 1};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    bubble_sort(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void bubble_sort(int len, int v[len])
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++)
            if (v[j] > v[j + 1])
            {
                v[j] = v[j] ^ v[j + 1];
                v[j + 1] = v[j] ^ v[j + 1];
                v[j] = v[j] ^ v[j + 1];
            }
}

void print_vet(int len, int v[len])
{
    for (int i = 0; i < len; i++)
        printf(" %d", v[i]);
}