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
stone *get_dist(stone *v, int n, int *n_dist);
void print_arr(void *v, int n, size_t size);
int is_promising(stone prec, stone curr);
void perm_r2(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit, int *max);

int main(void)
{
    FILE *fp = fopen(FILE_PATH, "r");
    int n_test, i, k, tot, *occ, exit, max_len, n_dist;
    stone *val, *sol, *prec_sol, *dist_val;
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

    fscanf(fp, "%d", &n_test);
    for (i = 0; i < n_test; i++)
    {
        printf("TEST #%d\n", i + 1);
        occ = get_stones_occ(fp, stones, &tot);
        printf("TOT = %d\n", tot);

        val = init_val(occ, tot);
        max_len = 0;
        dist_val = get_dist(val, tot, &n_dist);
        sol = (stone *)malloc(tot * sizeof(stone));
        exit = 0;

        perm_r2(0, dist_val, sol, occ, tot, n_dist, &exit, &max_len);

        printf("Collana massima di lunghezza %d\n", max_len);

        free(dist_val);
        free(sol);
        free(occ);
        free(val);
    }

    return 0;
}

void perm_r2(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit, int *max)
{
    int i;
    if (pos >= n)
    {
        *max = n;
        *exit = 1;
        return;
    }

    for (i = 0; i < n_dist && *exit == 0; i++)
    {
        if (mark[i] > 0 && (pos == 0 || is_promising(sol[pos - 1], dist_val[i])))
        {
            mark[i]--;
            sol[pos] = dist_val[i];

            if (pos + 1 > *max)
                *max = pos + 1;

            perm_r2(pos + 1, dist_val, sol, mark, n, n_dist, exit, max);
            mark[i]++;
        }
    }
    return;
}

int is_promising(stone prec, stone curr)
{
    switch (prec)
    {
    case z:
    case t:
        return curr == z || curr == r;
        break;

    case r:
    case s:
        return curr == s || curr == t;
        break;
    }
}

stone *get_dist(stone *v, int n, int *n_dist)
{
    int i, *occ = (int *)calloc(n, sizeof(int)), index;
    stone *dist;
    for (i = 0; i < n; occ[v[i]]++, i++)
        ;

    for (i = 0, *n_dist = 0; i < n; i++)
        if (occ[i] > 0)
            (*n_dist)++;

    dist = (stone *)malloc((*n_dist) * sizeof(stone));
    // *mark = (int *)malloc((*n_dist) * sizeof(int));

    for (i = 0, index = 0; i < n; i++)
        if (occ[i] > 0)
        {
            dist[index++] = i;
            // (*mark)[index++] = occ[i];
        }

    free(occ);
    return dist;
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