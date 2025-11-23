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
    TYPE_ELEMENT
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

int is_valid_program(int *sol, int pos, int k, int curr, diag_t *diags, element_t *elems, int *DP_values, int max_DP);
int is_valid_diag(int *sol, int pos, int k, int curr, element_t *elems, int *acro_f, int *acro_b, int max_DD, int *values);
int *init_val(int n);
element_t *get_elements_from_file(int *n);
void print_arr(void *arr, int n, size_t size, type_t type);
void print_element(element_t x);
void free_possible_diag(diag_t *v, int n);
void ins_diag(diag_t **possible_diag_p, int *dim, int *index, int *sol, int n_sol, int acro_f, int acro_b, int acro_seq, int difficulty, float value);
void diag_disp_r(int pos, int *val, element_t *elems, int *sol, int n, int k, int *acro_front, int *acro_bakc, int *acro_seq, int max_DD, int *DD_values, diag_t **possible_diags, int *dim_diag, int *index_diag, float *diag_val);
void program_disp_r(int pos, int *val, diag_t *diags, element_t *elems, int *sol, int *best_sol, int n, int k, int *DP_values, int max_DP, float *max_point, float *prog_val);

int main(void)
{
    int i, j, k, n_elements, *val, *val_prog, *sol, *sol_prog, *best_sol_prog, *acro_f, *acro_b, *acro_seq, *DD_values, *DP_values, dim_diag, index_diag,
        tests[N_TEST][2] = {// DD, DP
                            {10, 20},
                            {7, 30},
                            {10, 35},
                            {12, 28},
                            {12, 30},
                            {11, 33}};
    element_t *elements = get_elements_from_file(&n_elements);
    diag_t *possible_diag;
    float max_point, *diag_val, *prog_val;
    val = init_val(n_elements);

    // sol = (int *)malloc(MAX_ELEMENTS_FOR_DIAGONAL * sizeof(int));
    // acro_f = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
    // acro_b = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
    // acro_seq = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
    // DD_values = (int *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(int));
    // diag_val = (float *)calloc(MAX_ELEMENTS_FOR_DIAGONAL, sizeof(float));

    // dim_diag = 1000;
    // index_diag = 0;
    // possible_diag = (diag_t *)malloc(dim_diag * sizeof(diag_t));

    // diag_disp_r(0, val, elements, sol, n_elements, MAX_ELEMENTS_FOR_DIAGONAL, acro_f, acro_b, acro_seq, tests[0][0], DD_values, &possible_diag, &dim_diag, &index_diag, diag_val);

    // free(acro_f);
    // free(acro_b);
    // free(acro_seq);
    // free(DD_values);
    // free(diag_val);
    // free(sol);

    // val_prog = init_val(index_diag);
    // sol_prog = (int *)malloc(MAX_DIAGS_FOR_PROGRAM * sizeof(int));
    // best_sol_prog = (int *)malloc(MAX_DIAGS_FOR_PROGRAM * sizeof(int));
    // DP_values = (int *)calloc(MAX_DIAGS_FOR_PROGRAM, sizeof(int));
    // prog_val = (float *)calloc(MAX_DIAGS_FOR_PROGRAM, sizeof(float));
    // max_point = 0.0;

    // program_disp_r(0, val_prog, possible_diag, elements, sol_prog, best_sol_prog, index_diag, MAX_DIAGS_FOR_PROGRAM, DP_values, tests[0][1], &max_point, prog_val);

    // printf("TOT = %.3f\n", max_point);
    // for (i = 0; i < MAX_DIAGS_FOR_PROGRAM; i++)
    // {
    //     diag_t x = possible_diag[best_sol_prog[i]];

    //     printf("DIAG #%d > %.3f", i + 1, x.value);
    //     if (i == MAX_DIAGS_FOR_PROGRAM - 1 && elements[x.arr_elems[x.n_elem - 1]].difficulty >= 8)
    //         printf(" * 1.5 (BONUS)");
    //     printf("\n");
    //     for (j = 0; j < possible_diag[best_sol_prog[i]].n_elem; j++)
    //         printf("%s ", elements[possible_diag[best_sol_prog[i]].arr_elems[j]].name);
    //     printf("\n");
    // }

    // free(prog_val);
    // free(val_prog);
    // free(DP_values);
    // free_possible_diag(possible_diag, index_diag);
    // free(best_sol_prog);
    // free(sol_prog);

    for (i = 0; i < N_TEST; i++)
    {
        printf("--- Test Case #%d ---\n", i + 1);
        printf("DD = %d DP = %d\n", tests[i][0], tests[i][1]);

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

        free(acro_f);
        free(acro_b);
        free(acro_seq);
        free(DD_values);
        free(diag_val);
        free(sol);

        val_prog = init_val(index_diag);
        sol_prog = (int *)malloc(MAX_DIAGS_FOR_PROGRAM * sizeof(int));
        best_sol_prog = (int *)malloc(MAX_DIAGS_FOR_PROGRAM * sizeof(int));
        DP_values = (int *)calloc(MAX_DIAGS_FOR_PROGRAM, sizeof(int));
        prog_val = (float *)calloc(MAX_DIAGS_FOR_PROGRAM, sizeof(float));
        max_point = 0.0;

        program_disp_r(0, val_prog, possible_diag, elements, sol_prog, best_sol_prog, index_diag, MAX_DIAGS_FOR_PROGRAM, DP_values, tests[i][1], &max_point, prog_val);

        printf("TOT = %.3f\n", max_point);
        for (j = 0; j < MAX_DIAGS_FOR_PROGRAM; j++)
        {
            diag_t x = possible_diag[best_sol_prog[j]];

            printf("DIAG #%d > %.3f", j + 1, x.value);
            if (j == MAX_DIAGS_FOR_PROGRAM - 1 && elements[x.arr_elems[x.n_elem - 1]].difficulty >= 8)
                printf(" * 1.5 (BONUS)");
            printf("\n");
            for (k = 0; k < possible_diag[best_sol_prog[j]].n_elem; k++)
                printf("%s ", elements[possible_diag[best_sol_prog[j]].arr_elems[k]].name);
            printf("\n");
        }
        printf("\n");

        free(prog_val);
        free(val_prog);
        free(DP_values);
        free_possible_diag(possible_diag, index_diag);
        free(best_sol_prog);
        free(sol_prog);
    }

    free(val);
    free(elements);
    return 0;
}

int is_valid_program(int *sol, int pos, int k, int curr, diag_t *diags, element_t *elems, int *DP_values, int max_DP)
{
    int tot_acro_f, tot_acro_b, tot_acro_seq;
    if (pos == k - 1) /* check the presence of a sequence of acro style and both acro front and back */
    {
        for (int i = tot_acro_f = tot_acro_b = tot_acro_seq = 0; i < pos; i++)
        {
            tot_acro_f += diags[sol[i]].acro_front_count;
            tot_acro_b += diags[sol[i]].acro_back_count;
            tot_acro_seq += diags[sol[i]].acro_sequence;
        }
        tot_acro_f += diags[curr].acro_front_count;
        tot_acro_b += diags[curr].acro_back_count;
        tot_acro_seq += diags[curr].acro_sequence;

        if (tot_acro_seq == 0 || tot_acro_b == 0 || tot_acro_f == 0)
            return 0;
    }
    if (pos == 0 && diags[curr].difficulty > max_DP) /* check if is less difficult than max DP */
        return 0;
    if (pos > 0 && diags[curr].difficulty + DP_values[pos - 1] > max_DP)
        return 0;
    return 1;
}

void program_disp_r(int pos, int *val, diag_t *diags, element_t *elems, int *sol, int *best_sol, int n, int k, int *DP_values, int max_DP, float *max_point, float *prog_val)
{
    if (pos >= k)
    {
        element_t last_elem = elems[diags[sol[pos - 1]].arr_elems[diags[sol[pos - 1]].n_elem - 1]];
        if (last_elem.difficulty >= 8)
        {
            prog_val[pos - 1] -= diags[sol[pos - 1]].value;
            prog_val[pos - 1] += diags[sol[pos - 1]].value * 1.5;
        }
        if (prog_val[pos - 1] > *max_point)
        {
            *max_point = prog_val[pos - 1];
            // print_arr(sol, pos, sizeof(int), TYPE_INT);
            // printf("\n");
            memcpy(best_sol, sol, MAX_DIAGS_FOR_PROGRAM * sizeof(int));
        }
        return;
    }

    int i;
    for (i = 0; i < n; i++)
    {
        if (is_valid_program(sol, pos, k, val[i], diags, elems, DP_values, max_DP))
        {
            sol[pos] = val[i];

            DP_values[pos] = diags[val[i]].difficulty + (pos > 0 ? DP_values[pos - 1] : 0);
            prog_val[pos] = diags[val[i]].value + (pos > 0 ? prog_val[pos - 1] : 0);

            program_disp_r(pos + 1, val, diags, elems, sol, best_sol, n, k, DP_values, max_DP, max_point, prog_val);
        }
    }
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
    if (pos > 0 && elems[sol[pos - 1]].out_direction != elems[curr].in_direction) /* check cooration beetwen start and end */
        return 0;
    if (pos == k - 1 && acro_f[pos - 1] + acro_b[pos - 1] + elems[curr].type == 0) /* check presence of an acro movement */
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
                // print_arr(sol, pos + 1, sizeof(int), TYPE_INT);
                // printf("\t-->\t");
                // print_arr(diag_val, pos + 1, sizeof(float), TYPE_FLOAT);
                // printf("\n");
                ins_diag(possible_diags, dim_diag, index_diag, sol, pos + 1, acro_front[pos], acro_back[pos], acro_seq[pos], DD_values[pos], diag_val[pos]);
            }
            diag_disp_r(pos + 1, val, elems, sol, n, k, acro_front, acro_back, acro_seq, max_DD, DD_values, possible_diags, dim_diag, index_diag, diag_val);
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