#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN_FILE 20
#define MAX_ROW_COL 30
#define MAX_STR 100

typedef enum
{
    riga,
    colonna,
    fine
} selector;

typedef enum
{
    destra,
    sinistra,
    su,
    giu
} direction;

void to_lower(char str[]);
void print_mat(int m[][MAX_ROW_COL], int r, int c);
void reverse_arr(int v[], int start, int end);
void shift_row(int m[][MAX_ROW_COL], int r, int c, int index, int direction, int position);
void shift_column(int m[][MAX_ROW_COL], int r, int c, int index, int direction, int position);
int get_matrix(FILE *in, int m[][MAX_ROW_COL], int *r, int *c);
selector str_2_selector(char str[], char key_word[][10], int l);
direction str_2_direction(char str[], char key_word[][10], int l);

int main(void)
{
    FILE *fp_mat;
    int mat[MAX_ROW_COL][MAX_ROW_COL], nr, nc, exit = 0, sel, index, dir, position, ans;
    char selector_word[][10] = {"riga", "colonna", "fine"},
         direction_word[][10] = {"destra", "sinistra", "su", "giu"},
         str[MAX_STR], select[10], direct[10], path[MAX_LEN_FILE];

    printf("\nInsert matrix file path [ex. './mat.txt']:\t");
    scanf("%s", path);

    fp_mat = fopen(path, "r");
    ans = get_matrix(fp_mat, mat, &nr, &nc);

    if (ans < 0)
        return -1;

    printf("\n\nOriginal matrix:\n");
    print_mat(mat, nr, nc);

    while (exit == 0)
    {
        printf("\n<selector> <index> <direction> <position>\n");
        printf("Possible selector:\t'riga', 'colonna', 'fine'\nPossible selector:\t'destra', 'sinistra', 'su', 'giu'\n--> ");
        scanf("%s", str);

        if (sscanf(str, "%s %d %s %d", select, &index, direct, &position) != 4)
            printf("\nInvalid string");

        sel = str_2_selector(select, selector_word, sizeof(selector_word) / sizeof(selector_word[0]));
        dir = str_2_selector(direct, direction_word, sizeof(direction_word) / sizeof(direction_word[0]));

        if (sel < 0 || index < 0 || dir < 0 || position < 0)
            printf("\nInvalid string");
        else
        {
            switch (sel)
            {
            case riga:
                if (dir > 2)
                    printf("\nDirection error.");
                else
                {
                    shift_row(mat, nr, nc, index, dir, position);
                    printf("\nCurrent matrix:\n");
                    print_mat(mat, nr, nc);
                }
                break;

            case colonna:
                /* code */
                break;

            case fine:
                exit = 1;
                break;
            }
        }
    }

    return 0;
}

void reverse_arr(int v[], int start, int end)
{
    int tmp;
    while (end > start)
    {
        tmp = v[start];
        v[start++] = v[end];
        v[end--] = tmp;
    }
}

void shift_row(int m[][MAX_ROW_COL], int r, int c, int index, int direction, int position)
{
    position = direction == 0 ? c - position : position;
    reverse_arr(m[index], 0, position - 1);
    reverse_arr(m[index], position, c - 1);
    reverse_arr(m[index], 0, c - 1);
}

int get_matrix(FILE *in, int m[][MAX_ROW_COL], int *r, int *c)
{
    if (in == NULL)
    {
        printf("\nFile error.");
        return -1;
    }

    fscanf(in, "%d %d", &(*r), &(*c));

    if (*r < 0 || *c < 0 || *r > MAX_ROW_COL || *c > MAX_ROW_COL)
    {
        printf("\nFile error.\nRow or colum are incorrect.");
        return -1;
    }

    for (int i = 0; i < *r; i++)
        for (int j = 0; j < *c; j++)
            fscanf(in, "%d", &m[i][j]);
}

direction str_2_direction(char str[], char key_word[][10], int l)
{
    for (int i = 0; i < l; i++)
        if (strcmp(str, key_word[i]) == 0)
            return i;
    return -1;
}

selector str_2_selector(char str[], char key_word[][10], int l)
{
    for (int i = 0; i < l; i++)
        if (strcmp(str, key_word[i]) == 0)
            return i;
    return -1;
}

void to_lower(char str[])
{
    for (int i = 0; i < strlen(str); str[i] = tolower(str[i]), i++)
        ;
}

void print_mat(int m[][MAX_ROW_COL], int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}