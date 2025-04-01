#include <stdio.h>

void print_vet(int len, int v[len]);
void shell_sort_standard(int len, int v[len]);
void shell_sort_hibbard(int len, int v[len]);
void shell_sort_knuth(int len, int v[len]);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    // shell_sort_standard(sizeof(v) / sizeof(int), v);
    // shell_sort_hibbard(sizeof(v) / sizeof(int), v);
    shell_sort_knuth(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void shell_sort_standard(int len, int v[])
{
    int index, tmp;
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i++)
        {
            index = i;
            tmp = v[i];
            while (index >= gap && tmp < v[index - gap])
            {
                v[index] = v[index - gap];
                index -= gap;
            }
            v[index] = tmp;
        }
    }
}

void shell_sort_hibbard(int len, int v[])
{
    int index, tmp, gap = 1;

    while ((gap * 2) + 1 <= len)
        gap = (gap * 2) + 1;

    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            index = i;
            tmp = v[i];
            while (index >= gap && tmp < v[index - gap])
            {
                v[index] = v[index - gap];
                index -= gap;
            }
            v[index] = tmp;
        }
        gap = (gap - 1) / 2;
    }
}

void shell_sort_knuth(int len, int v[len])
{
    int index, tmp, gap = 1;

    while ((gap * 3) + 1 <= len)
        gap = (gap * 3) + 1;

    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            index = i;
            tmp = v[i];
            while (index >= gap && tmp < v[index - gap])
            {
                v[index] = v[index - gap];
                index -= gap;
            }
            v[index] = tmp;
        }
        gap = (gap - 1) / 3; // or gap /= 3
    }
}

void print_vet(int len, int v[])
{
    for (int i = 0; i < len; i++)
        printf(" %d", v[i]);
}