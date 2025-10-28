#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "easy_test_set.txt"
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
stone *get_dist(stone *v, int n, int *n_dist, int **mark);
void print_arr(void *v, int n, size_t size);
void comb(int pos, stone *val, stone *sol, int n, int k, int start, int *exit);
void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit);
int is_promising(stone prec, stone curr);

int main(void)
{
    FILE *fp = fopen(FILE_PATH, "r");
    int n_test, i, k, tot, *occ, exit;
    stone *val, *sol;
    char *stones[TYPE_OF_STONES] = {
        "zaffiro",
        "rubini",
        "topazi",
        "smeraldi"};

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

        for (k = tot; k > 1 && exit == 0; k--)
        {
            sol = (stone *)malloc(k * sizeof(stone));
            exit = 0;
            comb(0, val, sol, tot, k, 0, &exit);
            free(sol);
        }

        printf("Collana massima di lunghezza %d\n", k + 1);
        exit = 0;

        free(occ);
        free(val);
    }

    return 0;
}

void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *exit)
{
    int i;
    if (pos >= n)
    {
        // print_arr(sol, n, sizeof(stone));
        // printf("\n");
        *exit = 1;
        return;
    }

    for (i = 0; i < n_dist && *exit == 0; i++)
    {
        // print_arr(sol, n, sizeof(int));
        // printf("\nprec --> %d\tcurr --> %d\tmark[i] --> %d\tpos --> %d\n", sol[pos - 1], dist_val[i], mark[i], pos);
        if (mark[i] > 0 && (pos == 0 || is_promising(sol[pos - 1], dist_val[i])))
        {
            mark[i]--;
            sol[pos] = dist_val[i];
            perm_r(pos + 1, dist_val, sol, mark, n, n_dist, exit);
            mark[i]++;
        }
    }
    return;
}

void comb(int pos, stone *val, stone *sol, int n, int k, int start, int *exit)
{
    int i, j, *mark, n_dist;
    stone *dist, *sol_perm;
    if (pos >= k)
    {
        sol_perm = (stone *)malloc(k * sizeof(stone));
        dist = get_dist(sol, k, &n_dist, &mark);

        perm_r(0, dist, sol_perm, mark, k, n_dist, exit);

        free(dist);
        free(mark);
        free(sol_perm);
        return;
    }

    for (i = start; i < n && *exit == 0; i++)
    {
        sol[pos] = val[i];
        comb(pos + 1, val, sol, n, k, i + 1, exit);
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

stone *get_dist(stone *v, int n, int *n_dist, int **mark)
{
    int i, *occ = (int *)calloc(n, sizeof(int)), index;
    stone *dist;
    for (i = 0; i < n; occ[v[i]]++, i++)
        ;

    for (i = 0, *n_dist = 0; i < n; i++)
        if (occ[i] > 0)
            (*n_dist)++;

    dist = (stone *)malloc((*n_dist) * sizeof(stone));
    *mark = (int *)malloc((*n_dist) * sizeof(int));

    for (i = 0, index = 0; i < n; i++)
        if (occ[i] > 0)
        {
            dist[index] = i;
            (*mark)[index++] = occ[i];
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