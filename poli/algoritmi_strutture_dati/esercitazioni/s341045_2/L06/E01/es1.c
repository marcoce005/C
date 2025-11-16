#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "att2.txt"

typedef struct
{
    int si, fi;
} att;

void print_arr(int *v, int n);
void print_arr_att(att *v, int n);
void print_att(att x, char *prefix, char *suffix);
void print_sol(att *v, int *index, int i);
void merge_sort(att *v, int n); // wrapper
void merge_sort_rec(att *a, att *b, int l, int r);
void merge_2_way(att *a, att *b, int l, int m, int r);
void solve_DP(att *v, int n);
att *get_from_file(int *n);
att void_att(void);
int is_void_att(att x);
int is_compatible(att prec, att curr);
int max(int *v, int n, int *index_max);

int main(void)
{
    att *V;
    int n_att;

    V = get_from_file(&n_att);

    merge_sort(V, n_att); // sort by fi [when the activity end]

    solve_DP(V, n_att);

    free(V);
    return 0;
}

void print_sol(att *v, int *index, int i)
{
    if (i == -1)
        return;
    print_sol(v, index, index[i]);
    print_att(v[i], "", "\n");
}

int max(int *v, int n, int *index_max)
{
    int i, max;
    for (i = 0, max = v[0], *index_max = 0; i < n; i++)
        if (v[i] > max)
        {
            max = v[i];
            *index_max = i;
        }
    return max;
}

int is_compatible(att prec, att curr)
{
    return curr.si >= prec.fi;
}

void solve_DP(att *v, int n)
{
    int *time = (int *)malloc(n * sizeof(int)),
        *prec_index = (int *)malloc(n * sizeof(int)),
        i, j, index_max_time, index_best_time;

    prec_index[0] = -1;
    time[0] = v[0].fi - v[0].si;
    index_best_time = 0;

    for (i = 1; i < n; i++)
    {
        // search for the first compatilble
        for (j = i - 1; j >= 0 && !is_compatible(v[j], v[i]); j--)
            ;

        if (j == -1) // no one is compatible
        {
            time[i] = v[i].fi - v[i].si;
            prec_index[i] = -1;
        }
        else
        {
            time[i] = v[i].fi - v[i].si + max(time, j + 1, &index_max_time); // sum the best compatible
            prec_index[i] = index_max_time;
        }

        if (time[i] > time[index_best_time])
            index_best_time = i;
    }

    printf("\nBest duration time:\t%d\nSequence:\n", time[index_best_time]);
    print_sol(v, prec_index, index_best_time);

    free(time);
    free(prec_index);
}

void merge_2_way(att *a, att *b, int l, int m, int r)
{
    int i = l,
        j = m + 1,
        k;
    for (k = l; k <= r; k++)
    {
        if (i > m)
            b[k] = a[j++];
        else if (j > r)
            b[k] = a[i++];
        else if (a[i].fi <= a[j].fi)
            b[k] = a[i++];
        else
            b[k] = a[j++];
    }

    for (k = l; k <= r; k++)
        a[k] = b[k];
}

void merge_sort_rec(att *a, att *b, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    merge_sort_rec(a, b, l, m);
    merge_sort_rec(a, b, m + 1, r);
    merge_2_way(a, b, l, m, r);
}

void merge_sort(att *v, int n)
{
    att *v2 = (att *)malloc(n * sizeof(att));
    merge_sort_rec(v, v2, 0, n - 1);
    free(v2);
}

int is_void_att(att x) { return x.si == -1 && x.fi == -1; }

att void_att(void)
{
    att x = {-1, -1};
    return x;
}

void print_att(att x, char *prefix, char *suffix) { printf("%s%d %d%s", prefix, x.si, x.fi, suffix); }

void print_arr(int *v, int n)
{
    for (int i = 0; i < n; printf("%d ", v[i]), i++)
        ;
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