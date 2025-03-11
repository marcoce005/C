#include <stdio.h>

int read_file(FILE *file, int result[2]);

int main(void)
{
    FILE *path;
    path = fopen("./sorgente.txt", "r");

    int len_and_val[2];

    read_file(path, len_and_val);
    printf("\nValue with most occorence:\t%d\nNumbers of occurence:\t%d", len_and_val[0], len_and_val[1]);

    return 0;
}

int read_file(FILE *file, int result[2])
{
    int max_times = 1, times = 1, max_val, val, prev_val;
    char next_char;

    fscanf(file, "%d", &max_val);
    prev_val = max_val;
    while (!feof(file))
    {
        fscanf(file, "%d", &val);

        if (prev_val == val)
            times++;
        else
        {
            if (times > max_times)
            {
                max_times = times;
                max_val = prev_val;
            }
            times = 1;
        }
        prev_val = val;
    }

    result[0] = max_val;
    result[1] = max_times;

    return 0;
}