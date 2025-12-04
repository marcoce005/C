#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH_ELEMENTS "elementi.txt"
#define MAX_LEN_STR 100
#define N_TEST 6

#define MAX_ELEMENTS_FOR_DIAGONAL 5
#define MAX_DIAGS_FOR_PROGRAM 3

/* directions */
#define FRONT 1
#define BACK 0

/* element's type */
#define ACRO_FRONT 2
#define ACRO_BACK 1
#define TRANSITION 0

typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_ELEMENT,
    TYPE_DIAG
} type_t;

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

typedef struct
{
    int n_elem,
        acro_front_count,
        acro_back_count,
        acro_sequence,
        difficulty,
        *arr_elems;
    float value;
} diag_t;

element_t *get_elements_from_file(int *n);
void print_arr(void *arr, int n, size_t size, type_t type);
void print_element(element_t x);
void merge_sort(diag_t *v, int n);
void merge_sort_r(diag_t *v, diag_t *b, int l, int r);
void merge(diag_t *v, diag_t *b, int l, int m, int r);
int *greedy_resolver(diag_t *v, int n_diags, int DP);
int *init_val(int n);
void diag_disp_r(int pos, int *val, element_t *elems, int *sol, int n, int k, int *acro_front, int *acro_back, int *acro_seq, int max_DD, int *DD_values, diag_t **possible_diags, int *dim_diag, int *index_diag, float *diag_val);
void ins_diag(diag_t **possible_diag_p, int *dim, int *index, int *sol, int n_sol, int acro_f, int acro_b, int acro_seq, int difficulty, float value);
void free_possible_diag(diag_t *v, int n);
int is_valid_diag(int *sol, int pos, int k, int curr, element_t *elems, int *acro_f, int *acro_b, int max_DD, int *values);
void print_diag(diag_t x, element_t *elems);
int min_difficulty(diag_t *v, int n);
int match_by_function(diag_t *v, int n, int DP, int min_diff, int *constraints, int (*func)(diag_t, int, int, int *));
int check_constraint(diag_t x, int DP, int min_diff, int *constraints); // that one that have all the constraints > 0
int check_DP(diag_t x, int DP, int min_diff, int *v);                   // x <= DP - min_difficulty
void print_sol(diag_t *diags, element_t *elems, int *sol);

int main(void)
{
    int i, j, k, n_elements, *val, *sol, *sol_program, *acro_f, *acro_b, *acro_seq, *DD_values, dim_diag, index_diag,
        tests[N_TEST][2] = {// DD, DP
                            {10, 20},
                            {7, 30},
                            {10, 35},
                            {12, 28},
                            {12, 30},
                            {11, 33}};
    element_t *elements = get_elements_from_file(&n_elements);
    diag_t *possible_diag;
    float *diag_val;

    for (i = 0; i < N_TEST; i++)
    {
        printf("--- Test Case #%d ---\n", i + 1);
        printf("DD = %d DP = %d\n", tests[i][0], tests[i][1]);

        val = init_val(n_elements);
        sol = (int *)malloc(MAX_ELEMENTS_FOR_DIAGONAL * sizeof(int));
        acro_f = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
        acro_b = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
        acro_seq = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
        DD_values = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
        diag_val = (float *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(float));

        dim_diag = 1000;
        index_diag = 0;
        possible_diag = (diag_t *)malloc(dim_diag * sizeof(diag_t));

        diag_disp_r(0, val, elements, sol, n_elements, MAX_ELEMENTS_FOR_DIAGONAL, acro_f, acro_b, acro_seq, tests[i][0], DD_values, &possible_diag, &dim_diag, &index_diag, diag_val);

        merge_sort(possible_diag, index_diag);

        sol_program = (int *)greedy_resolver(possible_diag, index_diag, tests[i][1]);

        print_sol(possible_diag, elements, sol_program);

        free(acro_f);
        free(acro_b);
        free(acro_seq);
        free(DD_values);
        free(diag_val);
        free(sol);
        free_possible_diag(possible_diag, index_diag);
        free(val);
        free(sol_program);
    }
    free(elements);

    return 0;
}

void print_sol(diag_t *diags, element_t *elems, int *sol)
{
    int i, j, last_elem_diag;
    float tot;

    for (tot = i = 0; i < MAX_DIAGS_FOR_PROGRAM; i++)
    {
        last_elem_diag = diags[sol[i]].arr_elems[diags[sol[i]].n_elem - 1];
        if (i == MAX_DIAGS_FOR_PROGRAM - 1 && elems[last_elem_diag].difficulty >= 8)
            tot += diags[sol[i]].value * 1.5;
        else
            tot += diags[sol[i]].value;
    }
    printf("TOT = %.3f\n", tot);

    for (i = 0; i < MAX_DIAGS_FOR_PROGRAM; i++)
    {
        printf("DIAG #%d > %.3f", i + 1, diags[sol[i]].value);
        printf(i == MAX_DIAGS_FOR_PROGRAM - 1 && elems[last_elem_diag].difficulty >= 8 ? " * 1.5 (BONUS)\n" : "\n");

        for (j = 0; j < diags[sol[i]].n_elem; j++)
            printf("%s ", elems[diags[sol[i]].arr_elems[j]].name);
        printf("\n");
    }
    printf("\n");
}

void print_diag(diag_t x, element_t *elems)
{
    printf("acro_f --> %d\tacro_b --> %d\tacro_seq --> %d\n", x.acro_front_count, x.acro_back_count, x.acro_sequence);
    printf("difficulty --> %d\tvalue --> %.2f\n", x.difficulty, x.value);
    for (int i = 0; i < x.n_elem; i++)
        printf("%s ", elems[x.arr_elems[i]].name);
    printf("\n");
}

void ins_diag(diag_t **possible_diag_p, int *dim, int *index, int *sol, int n_sol, int acro_f, int acro_b, int acro_seq, int difficulty, float value)
{
    if (*index >= *dim)
    {
        *dim *= 2;
        *possible_diag_p = realloc(*possible_diag_p, *dim * sizeof(diag_t));
    }

    (*possible_diag_p)[*index].arr_elems = (int *)malloc(n_sol * sizeof(int));
    (*possible_diag_p)[*index].n_elem = n_sol;
    (*possible_diag_p)[*index].acro_front_count = acro_f;
    (*possible_diag_p)[*index].acro_back_count = acro_b;
    (*possible_diag_p)[*index].acro_sequence = acro_seq;
    (*possible_diag_p)[*index].difficulty = difficulty;
    (*possible_diag_p)[*index].value = value;
    memcpy((*possible_diag_p)[*index].arr_elems, sol, n_sol * sizeof(int));
    (*index)++;
}

void free_possible_diag(diag_t *v, int n)
{
    for (int i = 0; i < n; i++)
        free(v[i].arr_elems);
    free(v);
}

int is_valid_diag(int *sol, int pos, int k, int curr, element_t *elems, int *acro_f, int *acro_b, int max_DD, int *values)
{
    if (pos == 0 && elems[curr].require_prec)
        return 0;
    if (pos == 0 && elems[curr].in_direction != FRONT) /* check start front */
        return 0;
    if (pos > 0 && elems[sol[pos - 1]].out_direction != elems[curr].in_direction) /* check cooration beetwen
    start and end */
        return 0;
    if (pos == k - 1 && acro_f[pos - 1] + acro_b[pos - 1] + elems[curr].type == 0) /* check presence of an a
    cro movement */
        return 0;
    if (pos == 0 && elems[curr].difficulty > max_DD) /* check if is less of equal to max DD */
        return 0;
    if (pos > 0 && elems[curr].difficulty + values[pos - 1] > max_DD)
        return 0;
    return 1;
}

void diag_disp_r(int pos, int *val, element_t *elems, int *sol, int n, int k, int *acro_front, int *acro_back, int *acro_seq, int max_DD, int *DD_values, diag_t **possible_diags, int *dim_diag, int *index_diag, float *diag_val)
{
    if (pos >= k)
        return;

    int i;
    for (i = 0; i < n; i++)
    {
        if (pos > 0 && elems[sol[pos - 1]].is_last)
            return;
        if (is_valid_diag(sol, pos, k, val[i], elems, acro_front, acro_back, max_DD, DD_values))
        {
            sol[pos] = val[i];

            acro_front[pos] = (elems[val[i]].type == ACRO_FRONT) + (pos > 0 ? acro_front[pos - 1] : 0);
            acro_back[pos] = (elems[val[i]].type == ACRO_BACK) + (pos > 0 ? acro_back[pos - 1] : 0);
            acro_seq[pos] = (pos > 0 && elems[sol[pos - 1]].type != TRANSITION && elems[val[i]].type != TRANSITION) + (pos > 0 ? acro_seq[pos - 1] : 0);
            DD_values[pos] = elems[val[i]].difficulty + (pos > 0 ? DD_values[pos - 1] : 0);
            diag_val[pos] = elems[val[i]].value + (pos > 0 ? diag_val[pos - 1] : 0);

            if (pos < k && acro_front[pos] + acro_back[pos] > 0)
            {
                ins_diag(possible_diags, dim_diag, index_diag, sol, pos + 1, acro_front[pos], acro_back[pos], acro_seq[pos], DD_values[pos], diag_val[pos]);
                // print_arr(sol, pos + 1, sizeof(int), TYPE_INT);
                // printf("\n");
            }

            diag_disp_r(pos + 1, val, elems, sol, n, k, acro_front, acro_back, acro_seq, max_DD, DD_values,
                        possible_diags, dim_diag, index_diag, diag_val);
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

int min_difficulty(diag_t *v, int n)
{
    int i, min;
    for (i = 0, min = v[0].difficulty; i < n; i++)
        if (v[i].difficulty < min)
            min = v[i].difficulty;
    return min;
}

int check_DP(diag_t x, int DP, int min_diff, int *v) { return DP - x.difficulty - min_diff >= 0; }

int check_constraint(diag_t x, int DP, int min_diff, int *constraints) { return constraints[0] + x.acro_front_count > 0 && constraints[1] + x.acro_back_count > 0 && constraints[2] + x.acro_sequence > 0 && check_DP(x, DP, 0, constraints); }

int match_by_function(diag_t *v, int n, int DP, int min_diff, int *constraints, int (*func)(diag_t, int, int, int *))
{
    for (int i = 0; i < n; i++)
        if (func(v[i], DP, min_diff, constraints))
            return i;
    return -1;
}

int *greedy_resolver(diag_t *v, int n_diags, int DP)
{
    int i,
        *sol = (int *)malloc(MAX_DIAGS_FOR_PROGRAM * sizeof(int)),
        min_diff = min_difficulty(v, n_diags), // minimum difficult of a diagonal
        constraints[3] = {0};                  // constraints about acro front, back and sequence

    for (i = MAX_DIAGS_FOR_PROGRAM - 1; i >= 0; i--)
    {
        if (i == 0)
            sol[i] = match_by_function(v, n_diags, DP, min_diff, constraints, check_constraint);
        else
            sol[i] = match_by_function(v, n_diags, DP, min_diff, constraints, check_DP);

        constraints[0] += v[sol[i]].acro_front_count;
        constraints[1] += v[sol[i]].acro_back_count;
        constraints[2] += v[sol[i]].acro_sequence;

        if (sol[i] == -1)
        {
            printf("\nImpossible to find a correct program.\n");
            exit(1);
        }
        DP -= v[sol[i]].difficulty;
    }
    return sol;
}

void merge(diag_t *v, diag_t *b, int l, int m, int r)
{
    int i = l, j = m + 1, k;

    for (k = l; k <= r; k++)
    {
        if (i > m)
            b[k] = v[j++];
        else if (j > r)
            b[k] = v[i++];
        else if (v[i].value > v[j].value || (v[i].value == v[j].value && v[i].difficulty <= v[j].difficulty))
            b[k] = v[i++];
        else
            b[k] = v[j++];
    }
    for (k = 0; k <= r; v[k] = b[k], k++)
        ;
}

void merge_sort_r(diag_t *v, diag_t *b, int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    merge_sort_r(v, b, l, m);
    merge_sort_r(v, b, m + 1, r);
    merge(v, b, l, m, r);
}

void merge_sort(diag_t *v, int n)
{
    diag_t *b = (diag_t *)malloc(n * sizeof(diag_t));
    merge_sort_r(v, b, 0, n - 1);
    free(b);
}

void print_arr(void *arr, int n, size_t size, type_t type)
{
    for (int i = 0; i < n; i++)
    {
        switch (type)
        {
        case TYPE_INT:
            printf("%d ", *(int *)(arr + (i * size)));
            break;
        case TYPE_FLOAT:
            printf("%.2f ", *(float *)(arr + (i * size)));
            break;
        case TYPE_ELEMENT:
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