#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "test_set.txt"
#define TYPE_OF_STONES 4

typedef enum
{
    z,
    r,
    t,
    s
} stone;

int *get_stones_occ(FILE *fp, int *tot);
stone *init_val(int *occ, int size);
void print_arr(void *v, int n, size_t size);
int is_promising(stone prec, stone curr, int *mark, int nz, int ns, int max_r, stone *sol, int pos, int val, int val_disp, int max_val);
void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *len, int *val, int *max_val, int *stones_val, int max_rip, stone *best_sol, int *nz, int *ns, int *val_disp, int *vet_rip);
void get_stones_val(FILE *fp, int *vals, char *stones[TYPE_OF_STONES], int *occ);
void print_sol(stone *v, int n);

int main(void)
{
    FILE *fp = fopen(FILE_PATH, "r");
    int n_test, i, j, tot, *occ, len, stones_val[TYPE_OF_STONES], max_rip, max_val, val_curr, nz, ns, val_disp, *vet_rip;
    stone *val, *sol, *best_sol, dist_val[TYPE_OF_STONES];
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
        occ = get_stones_occ(fp, &tot);
        get_stones_val(fp, stones_val, stones, occ);
        fscanf(fp, "%d", &max_rip);

        printf("TOT = %d {max_rip = %d}\n", tot, max_rip);

        val = init_val(occ, tot);
        val_disp = nz = ns = val_curr = max_val = len = 0;
        sol = (stone *)malloc(tot * sizeof(stone));
        best_sol = (stone *)malloc(tot * sizeof(stone));
        vet_rip = (int *)malloc(tot * sizeof(int));

        for (j = 0; j < TYPE_OF_STONES; val_disp += occ[j] * stones_val[j], j++)
            ;

        perm_r(0, dist_val, sol, occ, tot, TYPE_OF_STONES, &len, &val_curr, &max_val, stones_val, max_rip, best_sol, &nz, &ns, &val_disp, vet_rip);

        printf("Soluzione ottima di valore %d usando %d gemma/e\nComposizione collana: ", max_val, len);
        print_sol(best_sol, len);
        printf("\n");

        free(vet_rip);
        free(best_sol);
        free(sol);
        free(occ);
        free(val);
    }

    fclose(fp);
    return 0;
}

void perm_r(int pos, stone *dist_val, stone *sol, int *mark, int n, int n_dist, int *len, int *val, int *max_val, int *stones_val, int max_rip, stone *best_sol, int *nz, int *ns, int *val_disp, int *vet_rip)
{
    int i, new_rip;

    if (pos >= n)
        return;

    for (i = 0; i < n_dist; i++)
    {
        if (mark[i] > 0)
        {
            if (pos != 0 && sol[pos - 1] == dist_val[i])
                new_rip = vet_rip[pos - 1] + 1;
            else
                new_rip = 1;

            if (new_rip <= max_rip)
            {
                vet_rip[pos] = new_rip;

                if (pos == 0 || is_promising(sol[pos - 1], dist_val[i], mark, *nz, *ns, max_rip, sol, pos, *val, *val_disp, *max_val))
                {
                    if (dist_val[i] == z)
                        (*nz)++;
                    if (dist_val[i] == s)
                        (*ns)++;

                    mark[i]--;
                    *val += stones_val[i];
                    *val_disp -= stones_val[i];
                    sol[pos] = dist_val[i];

                    if (*val > *max_val)
                    {
                        *len = pos + 1;
                        *max_val = *val;
                        memcpy(best_sol, sol, (*len) * sizeof(stone));
                    }

                    perm_r(pos + 1, dist_val, sol, mark, n, n_dist, len, val, max_val, stones_val, max_rip, best_sol, nz, ns, val_disp, vet_rip);

                    mark[i]++;
                    *val -= stones_val[i];
                    *val_disp += stones_val[i];

                    if (dist_val[i] == z)
                        (*nz)--;
                    if (dist_val[i] == s)
                        (*ns)--;
                }
            }
        }
    }
    return;
}

int is_promising(stone prec, stone curr, int *mark, int nz, int ns, int max_r, stone *sol, int pos, int val, int val_disp, int max_val)
{
    if (curr == z)
        nz++;
    if (curr == s)
        ns++;

    if (nz > ns || val + val_disp <= max_val)
        return 0;

    switch (prec)
    {
    case z:
    case t:
        return (curr == z || curr == r);
        break;

    case r:
    case s:
        return (curr == s || curr == t);
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

void print_sol(stone *v, int n)
{
    char name[TYPE_OF_STONES] = "zrts";
    for (int i = 0; i < n; printf("%c", name[v[i]]), i++)
        ;
}

void print_arr(void *v, int n, size_t size)
{
    for (int i = 0; i < n; printf("%d ", *(int *)(v + i * size)), i++)
        ;
}

void get_stones_val(FILE *fp, int *vals, char *stones[TYPE_OF_STONES], int *occ)
{
    for (int i = 0; i < TYPE_OF_STONES; i++)
    {
        fscanf(fp, "%d", vals + i);
        printf("%s = %d [%d], ", stones[i], occ[i], vals[i]);
    }
}

int *get_stones_occ(FILE *fp, int *tot)
{
    int j, *occ = malloc(TYPE_OF_STONES * sizeof(int));
    for (j = 0, *tot = 0; j < TYPE_OF_STONES; *tot += occ[j], j++)
        fscanf(fp, "%d", occ + j);
    return occ;
}