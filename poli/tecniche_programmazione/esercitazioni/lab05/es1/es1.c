#include <stdio.h>

#define FILE_PATH "./input.txt"
#define MAX_LEN 30

void sottoSequenze(int V[], int N);
int get_array(FILE *in, int v[], int len);
int find_longest(int v[], int len);

int main(void)
{
    int v[MAX_LEN], len;

    FILE *in;

    in = fopen(FILE_PATH, "r");

    len = get_array(in, v, MAX_LEN);

    if (len < 0)
    {
        printf("\nError!!!\n");
        fclose(in);
        return -1;
    }

    sottoSequenze(v, len);

    fclose(in);

    return 0;
}

int get_array(FILE *in, int v[], int len)
{
    if (in == NULL)
        return -1;

    int i;
    for (i = 0; i < len && fscanf(in, "%d", &v[i]) == 1; i++)
        ;
    return i;
}

int find_longest(int v[], int len)
{
    int max = 0, count = 0;
    for (int i = 0; i < len; i++)
        if (v[i] == 0)
        {
            max = count > max ? count : max;
            count = 0;
        }
        else
            count++;
    return max;
}

void sottoSequenze(int V[], int N)
{
    int max = find_longest(V, N), count = 0;

    if (max == 0)
    {
        printf("\nThere isn't any sequence.\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (count == max || (i + 1 == N && V[i] != 0 && count + 1 == max))
        {
            if (count != max)
                i++;

            printf("\nSubvector:\t");
            for (int j = i - max; j < i; j++)
                printf("%d ", V[j]);
        }
        count = V[i] == 0 ? 0 : count + 1;
    }
}