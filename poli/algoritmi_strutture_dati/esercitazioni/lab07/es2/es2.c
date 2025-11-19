#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH_ELEMENTS "elementi.txt"
#define MAX_LEN_STR 100
#define DEFAULT_IN_DIRECTION 1
#define N_TEST 6

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

int *init_val(int n);
element_t *get_elements_from_file(int *n);
void print_arr(void *arr, int n, size_t size);
void print_element(element_t x);

int main(void)
{
    int i, n_elements, *val,
        tests[N_TEST][2] = {// DD, DP
                            {10, 20},
                            {7, 40},
                            {10, 35},
                            {12, 28},
                            {12, 30},
                            {11, 33}};
    element_t *elements = get_elements_from_file(&n_elements);
    val = init_val(n_elements);

    for (i = 0; i < N_TEST; i++)
    {
        printf("--- Test Case #%d ---\n", i + 1);
        printf("DD = %d DP = %d\n", tests[i][0], tests[i][1]);
    }

    val[-1] = 1;

    free(val);
    free(elements);
    return 0;
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