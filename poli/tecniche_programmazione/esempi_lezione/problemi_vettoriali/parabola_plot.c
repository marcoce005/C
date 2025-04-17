#include <stdio.h>

#define ROW 25
#define COL 80

void print_mat(char m[][COL]);

int main(void)
{
    int i, j;
    float a, b, c, x_min, x_max, y_min, y_max, y, x, gap_x, gap_y;
    char plot[ROW][COL];

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            plot[i][j] = ' ';

    printf("\nInsert parobole information:\n");
    printf("a --> ");
    scanf("%f", &a);
    printf("b --> ");
    scanf("%f", &b);
    printf("c --> ");
    scanf("%f", &c);

    printf("\nInsert limits of 'x' axis:\n");
    printf("x min --> ");
    scanf("%f", &x_min);
    printf("x max --> ");
    scanf("%f", &x_max);

    printf("\nInsert limits of 'y' axis:\n");
    printf("y min --> ");
    scanf("%f", &y_min);
    printf("y max --> ");
    scanf("%f", &y_max);

    gap_x = (x_max - x_min) / (COL - 1);
    gap_y = (y_max - y_min) / (ROW - 1);

    for (i = 0; i < COL; i++)
    {
        x = x_min + i * gap_x;
        y = a * (x * x) + (b * x) + c;
        if (y >= y_min && y <= y_max)
        {
            j = (y - y_min) / gap_y;
            plot[j][i] = '*';
        }
    }

    print_mat(plot);

    return 0;
}

void print_mat(char m[][COL])
{
    for (int i = ROW - 1; i >= 0; i--)
    {
        for (int j = 0; j < COL; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
}