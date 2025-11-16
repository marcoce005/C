#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "grafo.txt"

typedef struct
{
    int N,
        E,
        *couples;
} graph;

graph create_graph();
void print_arr(int v[], int n);
void fill_val(int *v, int n);
void simple_comb(int pos, int *val, int *sol, int n, int k, int start, int *couples, int len_couples);
int is_valid_sol(int *sol, int k, int *couples, int len_couples);
int in_arr(int x, int *v, int n); // x in v[] ?

int main(void)
{
    graph G = create_graph();
    int *val = (int *)malloc(G.N * sizeof(int)),
        *sol,
        k;

    fill_val(val, G.N);

    sol = (int *)malloc(k * sizeof(int));

    printf("\nVertex Cover:\n");

    for (k = 1; k <= G.N; k++)
    {
        simple_comb(0, val, sol, G.N, k, 0, G.couples, G.E);
        printf("\n");
    }

    free(val);
    free(sol);
    free(G.couples);
    return 0;
}

int in_arr(int x, int *v, int n)
{
    for (int i = 0; i < n; i++)
        if (x == v[i])
            return 1;
    return 0;
}

int is_valid_sol(int *sol, int k, int *couples, int len_couples)
{
    for (int i = 0; i < len_couples * 2; i += 2)
        if (!in_arr(couples[i], sol, k) && !in_arr(couples[i + 1], sol, k))
            return 0;
    return 1;
}

void simple_comb(int pos, int *val, int *sol, int n, int k, int start, int *couples, int len_couples)
{
    int i, j;

    if (pos >= k && is_valid_sol(sol, k, couples, len_couples))
    {
        printf("(");
        print_arr(sol, k);
        printf(")\n");
        return;
    }

    for (i = start; i < n; i++)
    {
        sol[pos] = val[i];
        simple_comb(pos + 1, val, sol, n, k, i + 1, couples, len_couples);
    }
    return;
}

void fill_val(int *v, int n)
{
    for (int i = 0; i < n; v[i] = i, i++)
        ;
}

void print_arr(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf(i != n - 1 ? "%d, " : "%d", v[i]);
}

graph create_graph()
{
    FILE *fp = fopen(FILE_PATH, "r");
    graph g;

    if (fp == NULL)
    {
        printf("\nFile error.");
        exit(1);
    }

    fscanf(fp, "%d %d", &g.N, &g.E);

    g.couples = (int *)malloc(2 * g.E * sizeof(int));
    for (int i = 0; i < 2 * g.E; i += 2)
        fscanf(fp, "%d %d", &g.couples[i], &g.couples[i + 1]);

    return g;
}