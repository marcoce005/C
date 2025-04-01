#include <stdio.h>

void print_vet(int len, int v[len]);
void selection_sort(int len, int v[len]);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    selection_sort(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void selection_sort(int len, int v[])
{
    int index_min, tmp;
    for (int i = 0; i < len - 1; i++)
    {
        index_min = i;
        for (int j = i + 1; j < len; j++)
            if (v[j] < v[index_min])
                index_min = j;

        if (i != index_min)
        {
            // v[i] = v[i] ^ v[index_min]; // swap using xor
            // v[index_min] = v[i] ^ v[index_min];
            // v[i] = v[i] ^ v[index_min];
            tmp = v[i];
            v[i] = v[index_min];
            v[index_min] = tmp;
        }
    }
}

void print_vet(int len, int v[])
{
    for (int i = 0; i < len; i++)
        printf(" %d", v[i]);
}