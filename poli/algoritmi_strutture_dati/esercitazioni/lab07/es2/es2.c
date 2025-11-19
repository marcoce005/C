#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH_ELEMENTS "elementi.txt"
#define MAX_LEN_STR 100
#define DEFAULT_IN_DIRECTION 1

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

element_t *get_elements_from_file(int *n);
void print_elements(element_t *arr, int n);

int main(void)
{
    int n_elements;
    element_t *elements = get_elements_from_file(&n_elements);

    // print_elements(elements, n_elements);

    return 0;
}

void print_elements(element_t *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%s %d %d %d %d %d %.1f %d\n",
               arr[i].name,
               arr[i].type,
               arr[i].in_direction,
               arr[i].out_direction,
               arr[i].require_prec,
               arr[i].is_last,
               arr[i].value,
               arr[i].difficulty);
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
    arr = (element_t *)malloc(sizeof(*arr));

    for (int i = 0; i < *n; i++)
        fscanf(fp, "%s %d %d %d %d %d %f %d",
               arr[i].name,
               &arr[i].type,
               &arr[i].in_direction,
               &arr[i].out_direction,
               &arr[i].require_prec,
               &arr[i].is_last,
               &arr[i].value,
               &arr[i].difficulty);
    return arr;
}