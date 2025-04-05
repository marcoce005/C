#include <stdio.h>

#define FILE_PATH "./data.txt"
#define MAX_LEN 100

int get_data(FILE *in, float v[], float sum[], int len);

int main()
{
    float v[MAX_LEN], sum[MAX_LEN], prev_avg, next_avg;
    int len;

    FILE *in;

    in = fopen(FILE_PATH, "r");
    len = get_data(in, v, sum, MAX_LEN);

    if (len < 0)
    {
        printf("\nERROR\n");
        fclose(in);
        return -1;
    }

    float new_arr[len];
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            prev_avg = 0.0;
            next_avg = (sum[len - 1] - sum[i]) / (len - 1 - i);
        }
        else if (i == len - 1)
        {
            prev_avg = sum[i - 1] / i;
            next_avg = 0.0;
        }
        else
        {
            prev_avg = sum[i - 1] / i;
            next_avg = (sum[len - 1] - sum[i]) / (len - 1 - i);
        }

        new_arr[i] = (prev_avg + next_avg + v[i]) / 3;
        printf("%f\t", new_arr[i]);
    }

    fclose(in);

    return 0;
}

int get_data(FILE *in, float v[], float sum[], int len)
{
    if (in == NULL)
        return -1;

    int i;
    for (i = 0; i < len && fscanf(in, "%f", &v[i]) == 1; i++)
        if (i > 0)
            sum[i] = sum[i - 1] + v[i];
        else
            sum[i] = v[i];
    return i;
}