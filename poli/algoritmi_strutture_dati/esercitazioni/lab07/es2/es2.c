#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH_ELEMENTS "elementi.txt"
#define MAX_LEN_STR 100
#define N_TEST 6

#define MAX_ELEMENTS_FOR_DIAGONAL 5

/* directions */
#define FRONT 1
#define BACK 0

/* element's type */
#define ACRO_FRONT 2
#define ACRO_BACK 1
#define TRANSITION 0

typedef struct
{
    char name[MAX_LEN_STR];
    int type,
        in_direction,
        out_direction,
        require_prec,
        is_last,
        difficulty;
    float value;

} element_t;

int is_valid_diag(int *sol, int pos, int k, int curr, element_t *elems, int *acro, int max_DD, int *values);
int *init_val(int n);
element_t *get_elements_from_file(int *n);
void print_arr(void *arr, int n, size_t size);
void print_element(element_t x);
void free_possible_diag(int **v, int n);
void ins_diag(int ***possible_diag_p, int *dim, int *index, int *sol, int n_sol);
void diag_disp_r(int pos, int *val, element_t *elems, int *sol, int n, int k, int *acro, int max_DD, int *DD_values, int ***possible_diags, int *dim_diag, int *index_diag);

int main(void)
{
    int i, n_elements, *val, *sol, *acro, *DD_values, **possible_diag, dim_diag, index_diag,
        tests[N_TEST][2] = {// DD, DP
                            {10, 20},
                            {7, 30},
                            {10, 35},
                            {12, 28},
                            {12, 30},
                            {11, 33}};
    element_t *elements = get_elements_from_file(&n_elements);
    val = init_val(n_elements);

    sol = (int *)malloc(MAX_ELEMENTS_FOR_DIAGONAL * sizeof(int));
    acro = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
    DD_values = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));

    dim_diag = 100;
    index_diag = 0;
    possible_diag = (int **)malloc(dim_diag * sizeof(int *));

    diag_disp_r(0, val, elements, sol, n_elements, MAX_ELEMENTS_FOR_DIAGONAL, acro, tests[0][0], DD_values, &possible_diag, &dim_diag, &index_diag);

    free_possible_diag(possible_diag, index_diag);
    free(acro);
    free(DD_values);
    free(sol);

    // for (i = 0; i < N_TEST; i++)
    // {
    //     printf("--- Test Case #%d ---\n", i + 1);
    //     printf("DD = %d DP = %d\n", tests[i][0], tests[i][1]);
    // }

    free(val);
    free(elements);
    return 0;
}

void ins_diag(int ***possible_diag_p, int *dim, int *index, int *sol, int n_sol)
{
    if (*index >= *dim)
    {
        *dim *= 2;
        *possible_diag_p = realloc(*possible_diag_p, *dim * sizeof(int *));
    }

    (*possible_diag_p)[*index] = (int *)malloc(n_sol * sizeof(int));
    memcpy((*possible_diag_p)[*index], sol, n_sol * sizeof(int));
    (*index)++;
}

void free_possible_diag(int **v, int n)
{
    for (int i = 0; i < n; i++)
        free(v[i]);
    free(v);
}

int is_valid_diag(int *sol, int pos, int k, int curr, element_t *elems, int *acro, int max_DD, int *values)
{
    if (pos == 0 && elems[curr].in_direction != FRONT) /* check start front */
        return 0;
    if (pos > 0 && elems[sol[pos - 1]].out_direction != elems[curr].in_direction) /* check cooration beetwen start and end */
        return 0;
    if (pos == k - 1 && acro[pos - 1] + elems[curr].type == 0) /* check presence of an acro movement */
        return 0;
    if (pos == 0 && elems[curr].difficulty > max_DD) /* check if is less of equal to max DD */
        return 0;
    if (pos > 0 && elems[curr].difficulty + values[pos - 1] > max_DD)
        return 0;
    return 1;
}

void diag_disp_r(int pos, int *val, element_t *elems, int *sol, int n, int k, int *acro, int max_DD, int *DD_values, int ***possible_diags, int *dim_diag, int *index_diag)
{
    if (pos >= k)
        return;

    int i;
    for (i = 0; i < n; i++)
    {
        if (is_valid_diag(sol, pos, k, val[i], elems, acro, max_DD, DD_values))
        {
            sol[pos] = val[i];

            acro[pos] = (elems[val[i]].type != TRANSITION) + (pos > 0 ? acro[pos - 1] : 0);
            DD_values[pos] = elems[sol[pos]].difficulty + (pos > 0 ? DD_values[pos - 1] : 0);

            if (pos < k)
            {
                // print_arr(sol, pos + 1, sizeof(int));
                // printf("\t-->\t");
                // print_arr(DD_values, pos + 1, sizeof(int));
                // printf("\n");
                ins_diag(possible_diags, dim_diag, index_diag, sol, pos + 1);
            }
            diag_disp_r(pos + 1, val, elems, sol, n, k, acro, max_DD, DD_values, possible_diags, dim_diag, index_diag);
        }
    }
}

int *init_val(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

void print_arr(void *arr, int n, size_t size)
{
    for (int i = 0; i < n; i++)
    {
        switch (size)
        {
        case sizeof(int):
            printf("%d ", *(int *)(arr + (i * size)));
            break;
        case sizeof(element_t):
            print_element(*(element_t *)(arr + (i * size)));
            break;
        }
    }
}

void print_element(element_t x)
{
    printf("%s %d %d %d %d %d %.2f %d\n",
           x.name,
           x.type,
           x.in_direction,
           x.out_direction,
           x.require_prec,
           x.is_last,
           x.value,
           x.difficulty);
}

element_t *get_elements_from_file(int *n)
{
    FILE *fp = fopen(FILE_PATH_ELEMENTS, "r");
    element_t *arr;

    if (fp == NULL)
    {
        printf("\nFile error. File %s not found or corrupted.\n", FILE_PATH_ELEMENTS);
        exit(1);
    }

    fscanf(fp, "%d", n);
    arr = (element_t *)malloc(*n * sizeof(element_t));

    for (int i = 0; i < *n; i++)
    {
        fscanf(fp, "%s %d %d %d %d %d %f %d",
               arr[i].name,
               &arr[i].type,
               &arr[i].in_direction,
               &arr[i].out_direction,
               &arr[i].require_prec,
               &arr[i].is_last,
               &arr[i].value,
               &arr[i].difficulty);
    }
    return arr;
}