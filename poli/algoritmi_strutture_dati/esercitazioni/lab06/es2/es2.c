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
void best_cain(int *occ);
int is_promising(stone prec, stone curr, int *mark);
int div_imper(stone start, int *occ, int possible_stone, int **known, int max_occ);
int max(int *v, int n);
int cal_index_col(int *occ, int max_occ);

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

        best_cain(occ);

        free(sol);
        free(occ);
        free(val);
    }

    fclose(fp);
    return 0;
}

int cal_index_col(int *occ, int max_occ) { return occ[z] + max_occ * occ[r] + max_occ * max_occ * occ[t] + max_occ * max_occ * max_occ * occ[s]; }

int max(int *v, int n)
{
    int i, max = v[0];
    for (i = 0; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

void best_cain(int *occ)
{
    int l[TYPE_OF_STONES],
        k = max(occ, TYPE_OF_STONES) + 1,
        n_cols = cal_index_col(occ, k),
        **known, i, j;

    known = (int **)malloc(TYPE_OF_STONES * sizeof(int *));
    for (i = 0; i < TYPE_OF_STONES; i++)
    {
        known[i] = (int *)malloc(n_cols * sizeof(int));
        for (j = 0; j < n_cols; known[i][j] = -1, j++)
            ;
    }

    occ[z]--;
    l[0] = div_imper(z, occ, occ[z] + occ[r], known, k);
    occ[z]++;

    occ[r]--;
    l[1] = div_imper(r, occ, occ[s] + occ[t], known, k);
    occ[r]++;

    occ[t]--;
    l[2] = div_imper(t, occ, occ[z] + occ[r], known, k);
    occ[t]++;

    occ[s]--;
    l[3] = div_imper(s, occ, occ[s] + occ[t], known, k);
    occ[s]++;

    for (i = 0; i < TYPE_OF_STONES; i++)
        free(known[i]);
    free(known);

    printf("Collana massima di lunghezza %d\n", 1 + max(l, TYPE_OF_STONES));
}

int div_imper(stone start, int *occ, int possible_stone, int **known, int max_occ)
{
    if (possible_stone == 0)
    {
        known[start][cal_index_col(occ, max_occ)] = 0;
        return 0;
    }

    int l[2], index;
    switch (start)
    {
    case z:
    case t:
        if (occ[z] > 0)
        {
            occ[z]--;

            index = cal_index_col(occ, max_occ);

            if (known[z][index] != -1)
                l[0] = known[z][index];
            else
            {
                l[0] = 1 + div_imper(z, occ, occ[z] + occ[r], known, max_occ);
                known[z][index] = l[0];
            }

            occ[z]++;
        }
        else
            l[0] = 0;

        if (occ[r] > 0)
        {
            occ[r]--;

            index = cal_index_col(occ, max_occ);

            if (known[r][index] != -1)
                l[1] = known[r][index];
            else
            {
                l[1] = 1 + div_imper(r, occ, occ[s] + occ[t], known, max_occ);
                known[r][index] = l[1];
            }

            occ[r]++;
        }
        else
            l[1] = 0;
        break;

    case r:
    case s:
        if (occ[t] > 0)
        {
            occ[t]--;

            index = cal_index_col(occ, max_occ);

            if (known[t][index] != -1)
                l[0] = known[t][index];
            else
            {
                l[0] = 1 + div_imper(t, occ, occ[z] + occ[r], known, max_occ);
                known[t][index] = l[0];
            }

            occ[t]++;
        }
        else
            l[0] = 0;

        if (occ[s] > 0)
        {
            occ[s]--;

            index = cal_index_col(occ, max_occ);

            if (known[s][index] != -1)
                l[1] = known[s][index];
            else
            {
                l[1] = 1 + div_imper(s, occ, occ[s] + occ[t], known, max_occ);
                known[s][index] = l[1];
            }

            occ[s]++;
        }
        else
            l[1] = 0;
        break;
    }
    return max(l, 2);
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