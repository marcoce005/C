#include <stdio.h>
#include <ctype.h>

#define MAX 20
#define FILE_PATH "./mat.txt"

typedef struct Cell
{
    int score, partial_tot;
} cell;

int get_board(FILE *in, int mat[][MAX], int v[], int *n, int *m);
int get_board_optimized(FILE *in, cell mat[][MAX], int v[], int *n, int *m);
void print_board(int mat[][MAX], int v[], int r, int c);
void print_board_with_struct(cell mat[][MAX], int v[], int r, int c);
int sum(int v[], int len);

int main(void)
{
    FILE *in;
    int /* board[MAX][MAX], */ n, m, ans, lines_team[MAX], high_score /* , tot */, max_index, max_line;
    cell board[MAX][MAX];

    in = fopen(FILE_PATH, "r");
    // ans = get_board(in, board, lines_team, &n, &m);
    ans = get_board_optimized(in, board, lines_team, &n, &m);

    if (ans < 0)
    {
        fclose(in);
        return -1;
    }

    // print_board(board, lines_team, n, m);
    print_board_with_struct(board, lines_team, n, m);

    for (int j = 0; j < m; j++) // optimized version
    {
        high_score = 0;
        printf("\nThe leader after %d day is ", j + 1);

        for (int i = 0; i < n; i++)
        {
            if (board[i][j].partial_tot > high_score)
            {
                high_score = board[i][j].partial_tot;
                max_index = i;
                max_line = lines_team[i];
            }
        }
        printf("%d [line %d].", max_index, max_line);
    }

    // for (int j = 0; j < m; j++)          // not optimized
    // {
    //     high_score = 0;
    //     printf("\nThe leader after %d day is ", j + 1);

    //     for (int i = 0; i < n; i++)
    //     {
    //         tot = sum(board[i], j + 1);
    //         if (tot > high_score)
    //         {
    //             high_score = tot;
    //             max_index = i;
    //             max_line = lines_team[i];
    //         }
    //     }
    //     printf("%d [line %d].", max_index, max_line);
    // }

    fclose(in);

    return 0;
}

int get_board_optimized(FILE *in, cell mat[][MAX], int v[], int *n, int *m)
{
    if (in == NULL)
    {
        printf("\nFile Error.\nFile %s not found", FILE_PATH);
        return -1;
    }

    fscanf(in, "%d %d", &(*n), &(*m));
    int line = 0, i = 0, j;
    char c;

    if (*n > MAX || *m > MAX || *n < 0 || *m < 0)
    {
        printf("\nBoard Error.\nImpossibile creata a board %d X %d", *n, *m);
        return -1;
    }

    while ((c = fgetc(in)) != EOF)
    {
        if (isdigit(c))
        {
            mat[i][0].score = c - '0';
            mat[i][0].partial_tot = mat[i][0].score;
            if (mat[i][0].score != 0 && mat[i][0].score != 1 && mat[i][0].score != 3)
            {
                printf("\nBoard Error.\nData in board have to be 0, 1 or 3.");
                return -1;
            }

            v[i] = line + 1;
            for (j = 1; j < (*m); j++)
            {
                fscanf(in, "%d", &mat[i][j].score);
                mat[i][j].partial_tot = mat[i][j].score + mat[i][j - 1].partial_tot;
                if (mat[i][j].score != 0 && mat[i][j].score != 1 && mat[i][j].score != 3)
                {
                    printf("\nBoard Error.\nData in board have to be 0, 1 or 3.");
                    return -1;
                }
            }
            i++;
        }
        else if (c == '\n')
            line++;
    }
    return 0;
}

int sum(int v[], int len)
{
    int tot = 0;
    for (int i = 0; i < len; tot += v[i++])
        ;
    return tot;
}

int get_board(FILE *in, int mat[][MAX], int v[], int *n, int *m)
{
    if (in == NULL)
    {
        printf("\nFile Error.\nFile %s not found", FILE_PATH);
        return -1;
    }

    fscanf(in, "%d %d", &(*n), &(*m));
    int line = 0, i = 0, j;
    char c;

    if (*n > MAX || *m > MAX || *n < 0 || *m < 0)
    {
        printf("\nBoard Error.\nImpossibile creata a board %d X %d", *n, *m);
        return -1;
    }

    while ((c = fgetc(in)) != EOF)
    {
        if (isdigit(c))
        {
            mat[i][0] = c - '0';
            if (mat[i][0] != 0 && mat[i][0] != 1 && mat[i][0] != 3)
            {
                printf("\nBoard Error.\nData in board have to be 0, 1 or 3.");
                return -1;
            }

            v[i] = line + 1;
            for (j = 1; j < (*m); j++)
            {
                fscanf(in, "%d", &mat[i][j]);
                if (mat[i][j] != 0 && mat[i][j] != 1 && mat[i][j] != 3)
                {
                    printf("\nBoard Error.\nData in board have to be 0, 1 or 3.");
                    return -1;
                }
            }
            i++;
        }
        else if (c == '\n')
            line++;
    }
    return 0;
}

void print_board_with_struct(cell mat[][MAX], int v[], int r, int c)
{
    int i, j, k;

    printf("\n   Teams  \t|"); //    Teams        |  match 1  |  match 2  |  match 3  |  match 4  |
    for (i = 0; i < c; i++)
        printf("  match %d  |", i + 1);

    printf("\n");
    for (i = 0; i < 17 + (c * 12); i++)
        printf("_");

    for (i = 0; i < r; i++)
    {
        printf("\n %d [line = %d]\t|", i, v[i]);
        for (j = 0; j < c; j++)
            printf("     %d     |", mat[i][j].score);

        printf("\n");
        for (k = 0; k < 17 + (c * 12); k++) // horizontal line
            printf("_");
    }
}

void print_board(int mat[][MAX], int v[], int r, int c)
{
    int i, j, k;

    printf("\n   Teams  \t|"); //    Teams        |  match 1  |  match 2  |  match 3  |  match 4  |
    for (i = 0; i < c; i++)
        printf("  match %d  |", i + 1);

    printf("\n");
    for (i = 0; i < 17 + (c * 12); i++)
        printf("_");

    for (i = 0; i < r; i++)
    {
        printf("\n %d [line = %d]\t|", i, v[i]);
        for (j = 0; j < c; j++)
            printf("     %d     |", mat[i][j]);

        printf("\n");
        for (k = 0; k < 17 + (c * 12); k++) // horizontal line
            printf("_");
    }
}