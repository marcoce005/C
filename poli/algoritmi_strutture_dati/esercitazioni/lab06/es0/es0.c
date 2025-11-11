#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "val0.txt"

int *init_val(int *n);
void print_arr(int *v, int n);
void solve_DP(int *val, int n);
void displaySol(int *opt, int *val, int n);
void my_display(int *opt, int *val, int i);

int main(void)
{
    int n_val,
        *val = init_val(&n_val);

    solve_DP(val, n_val);

    free(val);
    return 0;
}

void displaySol(int *opt, int *val, int n)
{
    int i, j, *sol;
    sol = calloc((n + 1), sizeof(int));
    sol[1] = 1;
    i = n;
    while (i >= 2)
    {
        printf("i=%d\n", i);
        if (opt[i] == opt[i - 1])
        {
            sol[i] = 0;
            i--;
        }
        else if (opt[i] == opt[i - 2] + val[i])
        {
            sol[i] = 1;
            sol[i - 1] = 0;
            i -= 2;
        }
    }
    for (i = 1; i <= n; i++)
        if (sol[i])
            printf("%d ", val[i]);
    printf("\n");

    free(sol);
}

void my_display(int *opt, int *val, int i)
{
    if (i < 0)
        return;

    if (opt[i] == opt[i - 2] + val[i])
    {
        my_display(opt, val, i - 2);
        printf("City %d with %dk\n", i, val[i]);
    }
    else
        my_display(opt, val, i - 1);
}

void solve_DP(int *val, int n)
{
    int k,
        *opt = (int *)calloc(n + 1, sizeof(int));

    opt[0] = 0;
    opt[1] = val[1];

    for (k = 2; k < n + 1; k++)
    {
        if (opt[k - 2] + val[k] > opt[k - 1])

            opt[k] = opt[k - 2] + val[k];

        else

            opt[k] = opt[k - 1];
    }

    printf("Dynamic programming solution: ");
    printf("maximum population covered %dk\n", opt[n]);

    printf("\nWe install the tower in this city/ies:\n");

    // displaySol(opt, val, n);
    my_display(opt, val, n);

    free(opt);
}

void print_arr(int *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", v[i]);
    printf("\n");
}

int *init_val(int *n)
{
    FILE *fp = fopen(FILE_PATH, "r");
    int *v, i;

    if (fp == NULL)
    {
        printf("\nFile error.\n");
        exit(1);
    }

    fscanf(fp, "%d", n);

    v = (int *)malloc((*n + 1) * sizeof(int));
    v[0] = 0;

    for (i = 1; i < (*n + 1); fscanf(fp, "%d", v + i), i++)
        ;

    return v;
}