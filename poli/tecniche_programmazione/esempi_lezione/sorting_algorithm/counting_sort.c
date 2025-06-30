#include <stdio.h>

void print_arr(int v[], int n);
void counting_sort(int v[], int n);

int main(void)
{
    int v[] = {14, 6, 2, 5, 6, 2, 9, 11, 3};

    printf("\nBefore:\t");
    print_arr(v, sizeof(v) / sizeof(v[0]));

    counting_sort(v, sizeof(v) / sizeof(v[0]));

    printf("\nAfter:\t");
    print_arr(v, sizeof(v) / sizeof(v[0]));

    return 0;
}

void counting_sort(int v[], int n)
{
    int i, max = v[0], occurence[100], ans[n];

    for (i = 0; i < n; i++)             // find the max value for array of occurenec
        if (v[i] > max)
            max = v[i];

    for (i = 0; i <= max; i++)          // init occurences array
        occurence[i] = 0;

    for (i = 0; i < n; i++)             // calculate occurence for each number
        occurence[v[i]]++;

    for (i = 1; i <= max; i++)          // calculate multiple occurence
        occurence[i] += occurence[i - 1];
    
    for (i = n - 1; i >= 0; i--)        // sort using occurence
        ans[--occurence[v[i]]] = v[i];

    for (i = 0; i < n; i++)             // copy in original array
        v[i] = ans[i];
}

void print_arr(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
}