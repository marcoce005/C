#include <stdio.h>

#define maxN 30

void ruota(int v[maxN], int N, int P, int dir);
void ruota_optimized(int v[maxN], int N, int P, int dir);
void print_arr(int v[maxN], int N);
void fill_arr(int v[maxN], int N);

int main(void)
{
    int N, v[maxN], P, dir;

    printf("\nInsert length of the array:\t");
    scanf("%d", &N);

    if (N < 0 || N > maxN)
    {
        printf("\nErorr:\nMax length of the array is %d values.", maxN);
        return -1;
    }

    printf("\nFill the array:\n");
    fill_arr(v, N);

    printf("\nOriganl array:\t");
    print_arr(v, N);

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
            ruota_optimized(v, N, P, dir);
            printf("\n\nArray:\t");
            print_arr(v, N);
        }
    }

    return 0;
}

void ruota_optimized(int v[maxN], int N, int P, int dir) // O(N), works only left [trick to change direction], remove the first subvector and copy it at the end
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

void ruota(int v[maxN], int N, int P, int dir) // O(2N), this was better if we can change pointer of v into pointer of v2
{
    int v2[maxN], i;

    P = dir == 1 ? N - P : P;

    for (i = 0; i < N; i++)
        v2[(i + P) % N] = v[i];

    for (i = 0; i < N; i++)
        v[i] = v2[i];
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