#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH_TILES "tiles.txt"
#define FILE_PATH_BOARD "board.txt"

typedef struct // T1 horizontal, T2 vertical
{
    char colore_T1, colore_T2;
    int valore_T1, valore_T2, id;
} tile;

tile *get_tiles_from_file(int *n_tiles);
tile *get_board_from_file(tile *t, int **busy, int *r, int *c);
tile *init_val(tile *t, int n_t, tile *board, int *busy, int *tot_busy, int n_b, int *n_val);
tile rot_tile(tile x);
int *create_free_index_tab(int *busy, int free_cell, int r, int c);
int is_in_arr(int *v, int n, int x);
int cal_points(tile *board, int r, int c);
void print_arr(void *v, int n, size_t size);
void print_board(tile *v, int r, int c);
void print_tile(tile x);
void disp(int pos, int n, int k, tile *sol, int r, int c, tile *val, int *mark, int *busy, int *index_tab, tile *best, int *max);
void copy_arr(tile *dest, tile *src, int n);

int main(void)
{
    int n_tiles, r, c, *busy, n_busy, n_val, *mark, *free_index_tab, max;
    tile *tiles = get_tiles_from_file(&n_tiles),
         *board = get_board_from_file(tiles, &busy, &r, &c),
         *val = init_val(tiles, n_tiles, board, busy, &n_busy, r * c, &n_val),
         *best = (tile *)malloc(r * c * sizeof(tile));

    mark = (int *)calloc(n_val, sizeof(int));
    free_index_tab = create_free_index_tab(busy, (r * c) - n_busy, r, c);
    max = 0;

    disp(0, n_val, n_tiles - n_busy, board, r, c, val, mark, busy, free_index_tab, best, &max);

    printf("\nBest board [format tile: <id>:<coloreT1> <valoreT1> <coloreT2> <valoreT2>]:\n");
    print_board(best, r, c);
    printf("Points:\t%d\n", max);

    free(tiles);
    free(board);
    free(busy);
    free(val);
    free(mark);
    free(free_index_tab);
    free(best);
    return 0;
}

void copy_arr(tile *dest, tile *src, int n)
{
    for (int i = 0; i < n; dest[i] = src[i], i++)
        ;
}

int cal_points(tile *board, int r, int c)
{
    int i, j, tot, partial;
    for (tot = i = 0; i < r * c; i += r + 1)
    {
        for (partial = board[(i / r) * r].valore_T1, j = ((i / r) * r) + 1; j < ((i / r) * r) + r; j++) // search in row
        {
            if (board[j].colore_T1 != board[j - 1].colore_T1)
            {
                partial = 0;
                break;
            }
            partial += board[j].valore_T1;
        }
        tot += partial;
        for (partial = board[i % c].valore_T2, j = (i % c) + c; j <= (r - 1) * c + (i % c); j += c) // search in row
        {
            if (board[j].colore_T2 != board[j - c].colore_T2)
            {
                partial = 0;
                break;
            }
            partial += board[j].valore_T2;
        }
        tot += partial;
    }
    return tot;
}

void disp(int pos, int n, int k, tile *sol, int r, int c, tile *val, int *mark, int *busy, int *index_tab, tile *best, int *max)
{
    int i, points;

    if (pos >= k)
    {
        points = cal_points(sol, r, c);
        if (points > *max)
        {
            *max = points;
            copy_arr(best, sol, r * c);
        }
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (mark[i] == 0 && !is_in_arr(busy, index_tab[pos], val[i].id))
        {
            mark[i] = 1;
            sol[index_tab[pos]] = val[i];
            busy[index_tab[pos]] = val[i].id;
            disp(pos + 1, n, k, sol, r, c, val, mark, busy, index_tab, best, max);
            mark[i] = 0;
            busy[index_tab[pos]] = -1;
        }
    }
    return;
}

int *create_free_index_tab(int *busy, int free_cell, int r, int c)
{
    int i, index, *v = (int *)malloc(free_cell * sizeof(int));

    for (index = i = 0; i < r * c; i++)
        if (busy[i] == -1)
            v[index++] = i;
    return v;
}

int is_in_arr(int *v, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return 1;
    return 0;
}

tile *init_val(tile *t, int n_t, tile *board, int *busy, int *tot_busy, int n_b, int *n_val)
{
    tile *val;
    int i, index;

    for (*tot_busy = i = 0; i < n_b; i++)
        if (busy[i] != -1)
            (*tot_busy)++;

    *n_val = (n_t - *tot_busy) * 2;

    val = (tile *)malloc(*n_val * sizeof(tile));

    for (index = i = 0; i < n_t; i++)
        if (!is_in_arr(busy, n_b, t[i].id))
        {
            val[index++] = t[i];
            val[index++] = rot_tile(t[i]);
        }

    return val;
}

void print_tile(tile x) { printf("%d:%c %d %c %d \t", x.id, x.colore_T1, x.valore_T1, x.colore_T2, x.valore_T2); }

void print_board(tile *v, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            print_tile(v[(i * r) + j]);
        printf("\n");
    }
}

void print_arr(void *v, int n, size_t size)
{
    for (int i = 0; i < n * size; i += size)
    {
        switch (size)
        {
        case sizeof(int):
            printf("%d ", *((int *)(v + i)));
            break;

        case sizeof(tile):
            print_tile(*((tile *)(v + i)));
            break;
        }
    }
}

tile rot_tile(tile x)
{
    tile y;
    y.id = x.id;
    y.colore_T1 = x.colore_T2;
    y.colore_T2 = x.colore_T1;
    y.valore_T1 = x.valore_T2;
    y.valore_T2 = x.valore_T1;
    return y;
}

tile *get_board_from_file(tile *t, int **busy, int *r, int *c)
{
    FILE *fp = fopen(FILE_PATH_BOARD, "r");
    tile *board;
    int i, is_rot, index;

    if (fp == NULL)
    {
        printf("\nFile error.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", r, c);

    board = (tile *)malloc((*r) * (*c) * sizeof(tile));
    *busy = (int *)malloc((*r) * (*c) * sizeof(int));

    for (i = 0; i < (*r) * (*c); i++)
    {
        (*busy)[i] = -1; // init busy to -1
        fscanf(fp, "%d/%d", &index, &is_rot);

        if (index != -1)
        {
            (*busy)[i] = t[index].id;
            if (is_rot)
                board[i] = rot_tile(t[index]);
            else
                board[i] = t[index];
        }
    }

    fclose(fp);
    return board;
}

tile *get_tiles_from_file(int *n_tiles)
{
    FILE *fp = fopen(FILE_PATH_TILES, "r");
    tile *t, tmp;
    int i;

    if (fp == NULL)
    {
        printf("\nFile error.\n");
        exit(1);
    }

    fscanf(fp, "%d", n_tiles);

    t = (tile *)malloc(*n_tiles * sizeof(tile));

    for (i = 0; i < *n_tiles; fscanf(fp, " %c %d %c %d", &t[i].colore_T1, &t[i].valore_T1, &t[i].colore_T2, &t[i].valore_T2), t[i].id = i, i++)
        ;

    fclose(fp);
    return t;
}