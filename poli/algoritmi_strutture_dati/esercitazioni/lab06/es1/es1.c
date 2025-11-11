#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "att3.txt"

typedef struct
{
    int si, fi;
} att;

void print_arr_att(att *v, int n);
void print_att(att x, char *prefix, char *suffix);
void merge_sort(att *v, int n); // wrapper
void merge_sort_rec(att *a, att *b, int l, int r);
void merge_2_way(att *a, att *b, int l, int m, int r);
att *get_from_file(int *n);
att void_att(void);
int is_void_att(att x);

int main(void)
{
    att *V;
    int n_att;

    V = get_from_file(&n_att);

    print_arr_att(V, n_att);
    printf("\n\n");

    merge_sort(V, n_att);

    print_arr_att(V, n_att);

    free(V);
    return 0;
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
        else if (a[i].si <= a[j].si)
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