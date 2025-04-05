#include <stdio.h>

#define FILE_PATH "./data.txt"
#define MAX_LEN 100

int get_data(FILE *in, float v[], int len);
float avg(float v[], int start, int end);

int main()
{
    float v[MAX_LEN], prev_avg, next_avg;
    int len;

    FILE *in;

    in = fopen(FILE_PATH, "r");
    len = get_data(in, v, MAX_LEN);

    if (len < 0)
    {
        printf("\nERROR\n");
        fclose(in);
        return -1;
    }

    float new_arr[len];
    for (int i = 0; i < len; i++)
    {
        prev_avg = avg(v, 0, i);
        next_avg = avg(v, i + 1, len);
        new_arr[i] = (prev_avg + next_avg + v[i]) / 3;
        printf("%f\t", new_arr[i]);
    }

    fclose(in);

    return 0;
}

float avg(float v[], int start, int end)
{
    if (end <= start)
        return 0.0;

    float tot = 0.0;
    int i;
    for (i = start; i < end; i++)
        tot += v[i];
    return tot / (end - start);
}

int get_data(FILE *in, float v[], int len)
{
    if (in == NULL)
        return -1;

    int i;
    for (i = 0; i < len && fscanf(in, "%f", &v[i]) == 1; i++)
        ;
    return i;
}