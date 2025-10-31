#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "hard_test_set.txt"
#define TYPE_OF_STONES 4

typedef enum
{
    z,
    r,
    t,
    s
} stone;

int *get_stones_occ(FILE *fp, char *stones[TYPE_OF_STONES], int *tot);
stone *init_val(int *occ, int size);
void print_arr(void *v, int n, size_t size);
int is_promising(stone prec, stone curr, int *mark);
void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit, int *max);

int main(void)
{
    FILE *fp = fopen(FILE_PATH, "r");
    int n_test, i, tot, *occ, exit, max_len;
    stone *val, *sol, dist_val[TYPE_OF_STONES];
    char *stones[TYPE_OF_STONES] = {
        "zaffiro",
        "rubino",
        "topazio",
        "smeraldo"};

    if (fp == NULL)
    {
        printf("\nFile error");
        return 0;
    }

    for (i = 0; i < TYPE_OF_STONES; dist_val[i] = i, i++)
        ;

    fscanf(fp, "%d", &n_test);
    for (i = 0; i < n_test; i++)
    {
        printf("TEST #%d\n", i + 1);
        occ = get_stones_occ(fp, stones, &tot);
        printf("TOT = %d\n", tot);

        val = init_val(occ, tot);
        max_len = 0;
        sol = (stone *)malloc(tot * sizeof(stone));
        exit = 0;

        perm_r(0, dist_val, sol, occ, tot, TYPE_OF_STONES, &exit, &max_len);

        printf("Collana massima di lunghezza %d\n", max_len);

        free(sol);
        free(occ);
        free(val);
    }

    return 0;
}

void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit, int *max)
{
    int i, occ_special, j;
    if (pos >= n)
    {
        *max = n;
        *exit = 1;
        return;
    }

    for (i = 0; i < n_dist && *exit == 0; i++)
    {
        if (mark[i] > 0 && (pos == 0 || is_promising(sol[pos - 1], dist_val[i], mark)))
        {
            // force to put all the 'z' or 's' toghether --> zzzzzz or sssss

            occ_special = (dist_val[i] == z || dist_val[i] == s) ? mark[i] : 1;

            for (j = 0; j < occ_special; j++)
            {
                mark[i]--;
                sol[pos + j] = dist_val[i];
            }

            if (pos + occ_special > *max)
                *max = pos + occ_special;

            perm_r(pos + occ_special, dist_val, sol, mark, n, n_dist, exit, max);
            mark[i] += occ_special;
        }
    }
    return;
}

int is_promising(stone prec, stone curr, int *mark)
{
    switch (prec)
    {
    case z:
    case t:
        return (curr == z || curr == r) && (mark[z] + mark[r] > 0);
        break;

    case r:
    case s:
        return (curr == s || curr == t) && (mark[s] + mark[t] > 0);
        break;
    }
}

stone *init_val(int *occ, int size)
{
    int i, j, cnt = 0;
    stone *v = (stone *)malloc(size * sizeof(stone));
    for (i = 0; i < TYPE_OF_STONES; i++)
        for (j = 0; j < occ[i]; v[cnt++] = i, j++)
            ;
    return v;
}

void print_arr(void *v, int n, size_t size)
{
    for (int i = 0; i < n; printf("%d ", *(int *)(v + i * size)), i++)
        ;
}

int *get_stones_occ(FILE *fp, char *stones[TYPE_OF_STONES], int *tot)
{
    int j, *occ = malloc(TYPE_OF_STONES * sizeof(int));
    for (j = 0, *tot = 0; j < TYPE_OF_STONES; *tot += occ[j], j++)
    {
        fscanf(fp, "%d", occ + j);
        printf("%s = %d, ", stones[j], occ[j]);
    }
    return occ;
}