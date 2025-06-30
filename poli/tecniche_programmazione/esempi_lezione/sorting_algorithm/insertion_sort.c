#include <stdio.h>

void print_vet(int len, int v[len]);
void insertion_sort(int len, int v[len]);
void reverse_insertion_sort(int len, int v[]);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    reverse_insertion_sort(sizeof(v) / sizeof(int), v);

    printf("\nAfter:\t");
    print_vet(sizeof(v) / sizeof(int), v);

    return 0;
}

void insertion_sort(int len, int v[])
{
    int index, tmp;
    for (int i = 1; i < len; i++)
    {
        index = i;
        tmp = v[i];
        while (index > 0 && tmp < v[index - 1])
        {
            v[index] = v[index - 1]; // make space for the new number
            index--;
        }
        v[index] = tmp;
    }
}

void reverse_insertion_sort(int len, int v[])
{
    int index, tmp;
    for (int i = 1; i < len; i++)
    {
        index = i;
        tmp = v[i];
        while (index > 0 && tmp > v[index - 1])
        {
            v[index] = v[index - 1]; // make space for the new number
            index--;
        }
        v[index] = tmp;
    }
}

void print_vet(int len, int v[])
{
    for (int i = 0; i < len; i++)
        printf(" %d", v[i]);
}