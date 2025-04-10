#include <stdio.h>

#define maxN 30

int *ruota_swap_address(int v[maxN], int N, int P, int dir, int v2[]);
void ruota_without_2a_arr(int v[maxN], int N, int P, int dir);
void reverse_arr(int v[maxN], int start, int end);
void ruota_optimized(int v[maxN], int N, int P, int dir);
void print_arr(int v[maxN], int N);
void fill_arr(int v[maxN], int N);

int main(void)
{
    int N, v[maxN], P = -1, dir, *v1, v2[maxN], count = 0; // default value of P only to enter in the loop

    printf("\nInsert length of the array:\t");
    scanf("%d", &N);

    if (N < 0 || N > maxN)
    {
        printf("\nErorr:\nMax length of the array is %d values.", maxN);
        return -1;
    }

    printf("\nFill the array:\n");
    fill_arr(v, N);

    v1 = v;

    printf("\nOriganl array:\t");
    // print_arr(v, N);
    print_arr(v1, N);

    while (P != 0)
    {
        printf("\nHow many position [less then array length] [0 to exit]:\t");
        scanf("%d", &P);
        printf("\n[-1] rotate to right\n[1] rotate to left\n --> ");
        scanf("%d", &dir);

        if (P >= N || P < 0 || (dir != -1 && dir != 1))
            printf("\nWrong rotation number or direction.");
        else
        {
            // ruota_optimized(v, N, P, dir);
            // ruota_without_2a_arr(v, N, P, dir);

            v1 = count++ % 2 == 0 ? ruota_swap_address(v1, N, P, dir, v2) : ruota_swap_address(v1, N, P, dir, v);

            printf("\n\nArray:\t");
            // print_arr(v, N);
            print_arr(v1, N);
        }
    }

    return 0;
}

void reverse_arr(int v[maxN], int start, int end)
{
    int tmp;
    while (end > start)
    {
        tmp = v[start];
        v[start++] = v[end];
        v[end--] = tmp;
    }
}

void ruota_without_2a_arr(int v[maxN], int N, int P, int dir) // O(N)  works only left [trick to change direction], use the reversion of sub arr from 0 to P, from P to N and from 0 to N
{
    P = dir == -1 ? N - P : P;

    reverse_arr(v, 0, P - 1);
    reverse_arr(v, P, N - 1);
    reverse_arr(v, 0, N - 1);
}

void ruota_optimized(int v[maxN], int N, int P, int dir) // O(N + P), works only left [trick to change direction], remove the first subvector and copy it at the end
{
    int tmp[maxN], i, p2;

    P = dir == -1 ? N - P : P;

    for (i = 0; i < P; i++)
        tmp[i] = v[i];

    for (i = P; i < N; i++)
        v[i - P] = v[i];

    p2 = N - P;
    for (i = 0; i < P; i++)
        v[p2 + i] = tmp[i];
}

int *ruota_swap_address(int v[maxN], int N, int P, int dir, int v2[])
{
    P = dir == 1 ? N - P : P;
    for (int i = 0; i < N; i++)
        v2[(i + P) % N] = v[i];

    return v2;
}

void fill_arr(int v[maxN], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Value $%d:\t", i);
        scanf("%d", &v[i]);
    }
}

void print_arr(int v[maxN], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
}