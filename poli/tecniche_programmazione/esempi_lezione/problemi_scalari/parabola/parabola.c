#include <stdio.h>

#define FILE_PATH "./graph.txt"

void get_data(float *a, float *b, float *c, float *x_0, float *y_0, float *x_n, float *y_n, int *n);
int create_graph(FILE *f, float a, float b, float c, float x_0, float y_0, float x_n, float y_n, int n);

int main(void)
{
    FILE *out;
    float a, b, c, x_0, y_0, x_n, y_n;
    int n;

    get_data(&a, &b, &c, &x_0, &y_0, &x_n, &y_n, &n);

    out = fopen(FILE_PATH, "w");

    printf(create_graph(out, a, b, c, x_0, y_0, x_n, y_n, n) < 0 ? "\nSomething went wrong\n" : "\nGraph created\n");

    fclose(out);

    return 0;
}

void get_data(float *a, float *b, float *c, float *x_0, float *y_0, float *x_n, float *y_n, int *n)
{
    printf("\nParobole information:\n");
    printf("a = ");
    scanf("%f", &*a);
    printf("b = ");
    scanf("%f", &*b);
    printf("c = ");
    scanf("%f", &*c);

    printf("\nDefine x axis:\n");
    printf("x_0 = ");
    scanf("%f", &*x_0);
    printf("x_n = ");
    scanf("%f", &*x_n);

    printf("\nDefine y axis:\n");
    printf("y_0 = ");
    scanf("%f", &*y_0);
    printf("y_n = ");
    scanf("%f", &*y_n);

    printf("\nSet intervals number:\nn = ");
    scanf("%d", &*n);
}

int create_graph(FILE *f, float a, float b, float c, float x_0, float y_0, float x_n, float y_n, int n)
{
    if (f == NULL)
        return -1;

    float y;
    for (float i = x_0; i <= x_n; i += (x_n - x_0) / n)
    {
        y = a * i * i + b * i + c;

        if (y >= y_0 && y <= y_n)
        {
            for (int j = 0; j < ((int)y) - 1; j++)
                fputc(' ', f);
            fputs("*\n", f);
        }
    }

    return 0;
}