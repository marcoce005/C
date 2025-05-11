#include <stdio.h>

#define MAP_PATH "./mappa.txt"
#define MAX_ROW_OR_COL 50

typedef struct blackRegion
{
    int row, col, base, height;
} black_region;

int get_map(FILE *in, int *r, int *c, int m[][MAX_ROW_OR_COL]);
void print_mat(int m[][MAX_ROW_OR_COL], int r, int c);
void find_max_base_height_area(int m[][MAX_ROW_OR_COL], int r, int c);
black_region search_black_region(int m[][MAX_ROW_OR_COL], int start_r, int start_c, int r, int c);

int main(void)
{
    FILE *fp_map;
    int map[MAX_ROW_OR_COL][MAX_ROW_OR_COL], nr, nc, ans;

    fp_map = fopen(MAP_PATH, "r");
    ans = get_map(fp_map, &nr, &nc, map);

    if (ans < 0)
    {
        fclose(fp_map);
        return -1;
    }

    // print_mat(map, nr, nc);

    find_max_base_height_area(map, nr, nc);

    fclose(fp_map);
    return 0;
}

black_region search_black_region(int m[][MAX_ROW_OR_COL], int start_r, int start_c, int r, int c)
{
    int i, j;
    black_region res;

    for (j = start_c; m[start_r][j] && j < c; j++)
        ;
    for (i = start_r; m[i][start_c] && i < r; i++)
        ;

    res.base = j - start_c;
    res.height = i - start_r;
    res.row = start_r;
    res.col = start_c;

    return res;
}

void find_max_base_height_area(int m[][MAX_ROW_OR_COL], int r, int c)
{
    int i, j;
    black_region max_base, max_height, max_area, curr;

    max_base.base = 0;
    max_height.height = 0;
    max_area.base = max_area.height = 0;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (m[i][j])
            {
                curr = search_black_region(m, i, j, r, c);

                if (curr.base > max_base.base)
                    max_base = curr;

                if (curr.height > max_height.height)
                    max_height = curr;

                if (curr.base * curr.height > max_area.base * max_area.height)
                    max_area = curr;

                // printf("%d\t%d\t%d\t%d\n", curr.row, curr.col, curr.base, curr.height);
                j += curr.base;
            }

    printf("\nMax Base: estr. sup. SX = <%d,%d> b = %d, h = %d, Area = %d", max_base.row, max_base.col, max_base.base, max_base.height, max_base.base * max_base.height);
    printf("\nMax Area: estr. sup. SX = <%d,%d> b = %d, h = %d, Area = %d", max_area.row, max_area.col, max_area.base, max_area.height, max_area.base * max_area.height);
    printf("\nMax Base: estr. sup. SX = <%d,%d> b = %d, h = %d, Area = %d", max_height.row, max_height.col, max_height.base, max_height.height, max_height.base * max_height.height);
}

int get_map(FILE *in, int *r, int *c, int m[][MAX_ROW_OR_COL])
{
    if (in == NULL)
    {
        printf("\nFile Error\nFile %s not found. ", MAP_PATH);
        return -1;
    }

    fscanf(in, "%d %d", r, c);

    if (*r < 0 || *r > MAX_ROW_OR_COL || *c < 0 || *c > MAX_ROW_OR_COL)
    {
        printf("\nParameter error\nRows and colums have to be between 0 and %d", MAX_ROW_OR_COL);
        return -1;
    }

    int i, j;
    for (i = 0; i < (*r); i++)
        for (j = 0; j < (*c); j++)
            fscanf(in, "%d", &m[i][j]);

    return 0;
}

void print_mat(int m[][MAX_ROW_OR_COL], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}