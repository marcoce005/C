#include <stdio.h>

int majority(int *a, int N); // wrapper
int majority_recursive(int *a, int N, int start);

int main(void)
{
    int vet[] = {3, 3, 9, 4, 3, 5, 3},
        vet1[] = {0, 1, 0, 2, 3, 4, 0, 5};

    printf("vet --> %d\n", majority(vet, sizeof(vet) / sizeof(int)));
    printf("vet1 --> %d\n", majority(vet1, sizeof(vet1) / sizeof(int)));

    return 0;
}

int majority(int *a, int N) { return majority_recursive(a, N, 0); }

int majority_recursive(int *a, int N, int start)
{
    int i, occ = 1;

    if (N == 0)
        return -1;

    for (i = 1; i < N; i++)
        if (*a == a[i])
            occ++;

    if (occ > (N + start) / 2)
        return *a;
    else
        return majority_recursive(a + 1, N - 1, start + 1);
}