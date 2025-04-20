#include <stdio.h>

#define N 10

void selection_sort(int n[], int l);
void print_arr(int n[], int l);

int main(void)
{
    int numbers[N] = {42, 7, 19, 23, 3, 88, 15, 67, 5, 31};

    printf("\nBefore:\t");
    print_arr(numbers, sizeof(numbers) / sizeof(numbers[0]));

    selection_sort(numbers, sizeof(numbers) / sizeof(numbers[0]));

    printf("\nAfter:\t");
    print_arr(numbers, sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}

void selection_sort(int n[], int l)
{
    int i, min, j, tmp;
    for (i = 0; i < l - 1; i++)
    {
        min = i;
        for (j = i + 1; j < l; j++)
            if (n[j] < n[min])
                min = j;

        if (min != i)
        {
            tmp = n[i];
            n[i] = n[min];
            n[min] = tmp;
        }
    }
}

void print_arr(int n[], int l)
{
    for (int i = 0; i < l; i++)
        printf("%d ", n[i]);
}