#include <stdio.h>

#define FILE_PATH "./input.txt"

int analize_file(FILE *in, int *max, int *min, int *waste); // return -1 in case of error

int main(void)
{
    FILE *in;
    int max, min, waste = 0;

    in = fopen(FILE_PATH, "r");

    if (analize_file(in, &max, &min, &waste) < 0)
        printf("\nSomething went wrong\nPlease check file's path.\n");
    else
        printf("\nMaximum number:\t%d\nMinimum number:\t%d\nUnaccetable numbers:\t%d\n", max, min, waste);

    fclose(in);

    return 0;
}

int analize_file(FILE *in, int *max, int *min, int *waste)
{
    if (in == NULL)
        return -1;

    int n, n1, n2, sum, diff, mul, div;

    fscanf(in, "%d %d", &n, &n1);

    if (n > n1)
    {
        *max = n;
        *min = n1;
    }
    else
    {
        *max = n1;
        *min = n;
    }

    while (fscanf(in, "%d", &n2) == 1)
    {
        sum = n + n1;
        diff = n - n1;
        mul = n * n1;
        div = n / n1;

        if (n2 == sum || n2 == diff || n2 == mul || n2 == div)
        {
            if (n2 > *max)
                *max = n2;
            if (n2 < *min)
                *min = n2;

            n = n1;
            n1 = n2;
        }
        else
            (*waste)++;
    }

    return 0;
}