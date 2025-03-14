#include <stdio.h>

void print_vet(int len, int v[len]);
void bubble_sort(int len, int v[len]);
void optimized_bubble_sort(int len, int v[len]);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    // bubble_sort(sizeof(v) / sizeof(int), v);
    optimized_bubble_sort(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void optimized_bubble_sort(int len, int v[len])
{
    for (int i = 0; i < len; i++)
    {
        int swapped = 0;
        for (int j = 0; j < len - 1; j++)
            if (v[j] > v[j + 1])
            {
                swapped = 1;
                v[j] = v[j] ^ v[j + 1];
                v[j + 1] = v[j] ^ v[j + 1];
                v[j] = v[j] ^ v[j + 1];
            }
        if (swapped == 0)
            return;
    }
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