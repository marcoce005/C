#include <stdio.h>

#define FILE_PATH "./data.txt"
#define MAX_LEN 100

int get_data(FILE *in, int v[], int len);

int main(void)
{
    FILE *in;
    int v[MAX_LEN], decine[11] = {0}, len, i;

    in = fopen(FILE_PATH, "r");
    len = get_data(in, v, MAX_LEN);

    for (i = 0; i < len; i++)
        decine[v[i] / 10]++;

    printf("\nOccurence:\n");
    for (i = 0; i < 11; i++)
        if (i == 10)
            printf("%d\t-->\t%d\n", i * 10, decine[i]);
        else
            printf("%d - %d\t-->\t%d\n", i * 10, (i * 10) + 9, decine[i]);

    fclose(in);

    return 0;
}

int get_data(FILE *in, int v[], int len)
{
    if (in == NULL)
        return -1;

    int i;
    for (i = 0; i < len && fscanf(in, "%d", &v[i]) == 1; i++)
        ;
    return i;
}