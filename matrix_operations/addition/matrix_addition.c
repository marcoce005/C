#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int **mat, int m, int n);

int **addition(int *mat, int r, int c, int *mat2, int r2, int c2);

void read_matrix(char *file_name);

int get_colums(FILE *file);

int get_rows(FILE *file);

int main(void)
{
    read_matrix("./mat1.txt");

    // mat2 = fopen("./mat2.txt", "r");

    // int mat1[3][3] = {
    //     {0, 1, 2},
    //     {3, 4, 5},
    //     {6, 7, 8}};

    // int mat2[3][3] = {
    //     {8, 7, 6},
    //     {5, 4, 3},
    //     {2, 1, 0}};

    // int **result = addition((int *)mat1, 3, 3, (int *)mat2, 3, 3);

    // if (result == -1)
    // {
    //     printf("\nSorry, you can't sum this matrix.\nYou can only addition matrix having the same numbers of lines and rows.");
    //     return -1;
    // }

    // print_matrix(result, 3, 3);

    return 0;
}

int get_colums(FILE *file)
{
    int colums = 0, val;
    char next_c;

    while (!feof(file))
    {
        fscanf(file, "%d", &val);
        colums++;
        next_c = fgetc(file);
        if (next_c == '\n' || next_c == '\0')
            return colums;
    }
    return -1;
}

int get_rows(FILE *file)
{
    int rows = 0;
    char str[100], next_c;

    while (!feof(file))
    {
        fgets(str, 100, file);
        rows++;
        next_c = fgetc(file);
        if (next_c == '\n' || next_c == '\0')
            break;
    }
    return rows;
}

void read_matrix(char *file_name)
{
    FILE *file;
    file = fopen(file_name, "r");

    int r = get_rows(file);
    rewind(file);
    int c = get_colums(file);
    rewind(file);

    int m[r][c], i = 0, j = 0, *pointer[r];

    while (!feof(file))
    {
        fscanf(file, "%d", &m[j][i++]);

        if (fgetc(file) == '\n')
        {
            pointer[j] = m[j];
            j++;
            i = 0;
        }
    }
    pointer[j] = m[j];

    print_matrix((int **)pointer, r, c);
}

void print_matrix(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int **addition(int *mat, int r, int c, int *mat2, int r2, int c2)
{
    if (r != r2 || c != c2)
        return (int **)-1;

    int **ans = (int **)malloc(r * sizeof(int *)); // create a matrix dinamically
    for (int i = 0; i < r; i++)
        ans[i] = (int *)malloc(c * sizeof(int));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans[i][j] = (int)*((mat + i * c) + j) + (int)*((mat2 + i * c) + j);
        }
    }
    return ans;
}