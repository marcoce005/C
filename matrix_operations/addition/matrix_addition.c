#include <stdio.h>
#include <stdlib.h>

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

    int **ans = (int **)malloc(r * sizeof(int *));          // create a matrix dinamically
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

int main(void)
{
    int mat1[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}};

    int mat2[3][3] = {
        {8, 7, 6},
        {5, 4, 3},
        {2, 1, 0}};

    int **result = addition((int *)mat1, 3, 3, (int *)mat2, 3, 3);

    if (result == -1)
    {
        printf("\nSorry, you can't sum this matrix.\nYou can only addition matrix having the same numbers of lines and rows.");
        return -1;
    }

    print_matrix(result, 3, 3);

    return 0;
}