#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "att1.txt"

typedef struct
{
    int si, fi;
} att;

void attSel(int N, att *V);
void print_arr_att(att *v, int n);
void print_att(att x, char *prefix, char *suffix);
void comb(int pos, int start, int n, int k, att *sol, att *best_sol, att *val, int *len_max, int *max_hours, int *hours);
void arr_att_copy(att *dest, att *src, int n);
att *get_from_file(int *n);
att void_att(void);
int is_promising(att *sol, int n, att x);
int is_void_att(att x);

int main(void)
{
    att *V;
    int n_att;

    V = get_from_file(&n_att);

    attSel(n_att, V);

    free(V);
    return 0;
}

int is_promising(att *sol, int n, att x)
{
    for (int i = 0; i < n; i++)
        if (x.si >= sol[i].si && x.si < sol[i].fi)
            return 0;
    return 1;
}

void comb(int pos, int start, int n, int k, att *sol, att *best_sol, att *val, int *len_max, int *max_hours, int *hours)
{
    int i;

    if (pos >= k)
    {
        if (*hours > *max_hours)
        {
            *max_hours = *hours;
            *len_max = pos;
            arr_att_copy(best_sol, sol, *len_max);
        }
        return;
    }

    for (i = start; i < n; i++)
    {
        if (pos == 0 || is_promising(sol, pos, val[i]))
        {
            if (!is_void_att(sol[pos]))
                *hours -= (sol[pos].fi - sol[pos].si);

            *hours += val[i].fi - val[i].si;
            sol[pos] = val[i];

            comb(pos + 1, i + 1, n, k, sol, best_sol, val, len_max, max_hours, hours);
        }
    }
    return;
}

void attSel(int N, att *V)
{
    att *sol, *best_sol;
    int k = N, max_h, h, i, len_max;

    best_sol = (att *)malloc(N * sizeof(att));

    for (len_max = max_h = 0, k = N; k > 0; k--)
    {
        h = 0;
        sol = (att *)malloc(k * sizeof(att));

        for (i = 0; i < k; sol[i] = void_att(), i++) // init to void
            ;

        comb(0, 0, N, k, sol, best_sol, V, &len_max, &max_h, &h);

        free(sol);
    }

    print_arr_att(best_sol, len_max);
    printf("Durata %d\n", max_h);

    free(best_sol);
}

void arr_att_copy(att *dest, att *src, int n)
{
    for (int i = 0; i < n; dest[i] = src[i], i++)

        ;
}

int is_void_att(att x) { return x.si == -1 && x.fi == -1; }

att void_att(void)
{
    att x = {-1, -1};
    return x;
}

void print_att(att x, char *prefix, char *suffix)
{
    printf("%s%d %d%s", prefix, x.si, x.fi, suffix);
}

void print_arr_att(att *v, int n)
{
    for (int i = 0; i < n; print_att(v[i], "", "\n"), i++)
        ;
}

att *get_from_file(int *n)
{
    FILE *fp = fopen(FILE_PATH, "r");
    att *v;

    if (fp == NULL)
    {
        printf("\nFile error.\n");
        exit(1);
    }

    fscanf(fp, "%d", n);
    v = (att *)malloc(*n * sizeof(att));

    for (int i = 0; i < *n; fscanf(fp, "%d %d", &v[i].si, &v[i].fi), i++)
        ;

    fclose(fp);
    return v;
}