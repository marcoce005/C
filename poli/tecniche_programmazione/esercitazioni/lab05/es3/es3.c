#include <stdio.h>

#define MAX 20

void print_mat(int r, int c, int mat[][MAX]);
void get_data(FILE *in, int r, int c, int mat[][MAX]);
void submatrix(int size_sub, int r, int c, int mat[][MAX]);

int main(void)
{
    int nr, nc, mat[MAX][MAX], dim, min;
    char file_path[MAX];

    FILE *in;

    printf("\nInsert matrix path:\t");
    scanf("%s", file_path);

    in = fopen(file_path, "r");

    if (in == NULL)
    {
        printf("\nFile error.");
        return -1;
    }

    fscanf(in, "%d %d", &nr, &nc);

    if (nr > MAX || nc > MAX)
    {
        printf("\nMatrix size error.");
        return -1;
    }

    get_data(in, nr, nc, mat);

    min = nr >= nc ? nc : nr;

    do
    {
        printf("\nInsert dimension of the square submatrix:\t");
        scanf("%d", &dim);

        if (dim <= min)
        {
            printf("\nThe square submatrix %dx%d are:\n", dim, dim);
            submatrix(dim, nr, nc, mat);
        }
    } while (dim <= min);

    fclose(in);

    return 0;
}

void submatrix(int size_sub, int r, int c, int mat[][MAX])
{
    int max = 0, tot, row_max, col_max;

    for (int i = 0; i <= r - size_sub; i++)
        for (int j = 0; j <= c - size_sub; j++)
        {
            tot = 0;
            for (int k = 0; k < size_sub; k++)
            {
                for (int h = 0; h < size_sub; h++)
                {
                    tot += mat[i + k][j + h];
                    printf("%d ", mat[i + k][j + h]);
                }

                if (tot > max)
                {
                    row_max = i;
                    col_max = j;
                    max = tot;
                }

                printf("\n");
            }
            printf("\n");
        }

    printf("\nThe submatrix with the higher sum (%d) e':\n", max);
    for (int i = 0; i < size_sub; i++)
    {
        for (int j = 0; j < size_sub; j++)
            printf("%d ", mat[row_max + i][col_max + j]);
        printf("\n");
    }
}

void get_data(FILE *in, int r, int c, int mat[][MAX])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            fscanf(in, "%d", &mat[i][j]);
}

void print_mat(int r, int c, int mat[][MAX])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}