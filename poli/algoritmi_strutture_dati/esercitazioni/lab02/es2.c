#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "mat.txt"

int **malloc2dR(int *r, int *c);
void malloc2dP(int ***m, int *r, int *c);
void free2d(int **m, int r);
void print_mat(int **m, int r, int c);
void print_vett(int v[], int len);
void separa(int **mat, int nr, int nc, int white[], int black[]);

int main(void)
{
    int **mat, nr, nc, *v_white, *v_black, nw, nb;

    // malloc2dP(&mat, &nr, &nc);
    mat = malloc2dR(&nr, &nc);

    if (mat == NULL)
        return -1;

    print_mat(mat, nr, nc);

    nw = (nr * nc) / 2;
    nb = (nr * nc) - nw;

    v_white = (int *)malloc(nw * sizeof(int));
    v_black = (int *)malloc(nb * sizeof(int));

    separa(mat, nr, nc, v_white, v_black);

    printf("\n\n");
    print_vett(v_white, nw);
    printf("\n\n");
    print_vett(v_black, nb);

    free(v_white);
    free(v_black);
    free2d(mat, nr);
    return 0;
}

void print_vett(int v[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", v[i]);
}

void separa(int **mat, int nr, int nc, int white[], int black[])
{
    int i, j, w = 0, b = 0;
    for (i = 0; i < nr; i++)
        for (j = 0; j < nc; j++)
            if ((i + j) % 2 == 0)
                black[b++] = mat[i][j];
            else
                white[w++] = mat[i][j];
}

void print_mat(int **m, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void free2d(int **m, int r)
{
    for (int i = 0; i < r; free(m[i]), i++)
        ;
    free(m);
}

void malloc2dP(int ***m, int *r, int *c)
{
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL)
    {
        printf("File error.");
        exit(1);
    }

    fscanf(fp, "%d %d", r, c);

    int **m_tmp = (int **)malloc((*r) * sizeof(int *)),
        i, j;

    if (m_tmp == NULL)
    {
        printf("Memory allocation error.");
        exit(1);
    }

    for (i = 0; i < *r; i++)
    {
        m_tmp[i] = (int *)malloc((*c) * sizeof(int));
        if (m_tmp[i] == NULL)
        {
            printf("Memory allocation error.");
            exit(1);
        }
        for (j = 0; j < *c; j++)
            fscanf(fp, "%d", m_tmp[i] + j);
    }
    *m = m_tmp;
}

int **malloc2dR(int *r, int *c)
{
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL)
    {
        printf("File error.");
        return NULL;
    }

    fscanf(fp, "%d %d", r, c);

    int **m = (int **)malloc((*r) * sizeof(int *)),
        i, j;

    if (m == NULL)
    {
        printf("Memory allocation error.");
        return NULL;
    }

    for (i = 0; i < *r; i++)
    {
        m[i] = (int *)malloc((*c) * sizeof(int));
        if (m[i] == NULL)
        {
            printf("Memory allocation error.");
            return NULL;
        }
        for (j = 0; j < *c; j++)
            fscanf(fp, "%d", m[i] + j);
    }
    return m;
}