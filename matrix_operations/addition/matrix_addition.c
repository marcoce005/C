#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void split(char *str)
{
    char val[10] = {'\0'};
    int index_val = 0, arr[strlen(str)], index_arr = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
            val[index_val++] = str[i];
        else
        {
            // printf("%s\n", val);
            arr[index_arr++] = atoi(val);
            for (int j = 0; j < sizeof(val); j++) // clear the string putting '\0' in all character
                val[j] = '\0';
            index_val = 0;
        }
    }
    arr[index_arr++] = atoi(val);

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main(void)
{
    FILE *mat1, *mat2;

    mat1 = fopen("./mat1.txt", "r");
    mat2 = fopen("./mat2.txt", "r");

    char value[20];
    while (!feof(mat2))
    {
        fgets(value, 10, mat2);

        split(value);
        // fscanf(mat1, "%s", value);
        // printf("%d\t", strcmp(value, "\n"));
        // printf("%s\n", value);
    }

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

    fclose(mat1);
    fclose(mat2);

    return 0;
}