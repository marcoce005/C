#include <stdio.h>

#define NODES 10
#define FILE_PATH "./input.txt"

void online_connectivity(FILE *in, int id[]);
void slow_union(int id[], int p, int q);

int main(void)
{
    FILE *in;
    int id[NODES];

    for (int i = 0; i < NODES; i++) // init set [each node is not connected with other nodes]
        id[i] = i;

    in = fopen(FILE_PATH, "r");

    online_connectivity(in, id);

    fclose(in);

    return 0;
}

void slow_union(int id[], int p, int q)
{
    int tmp = id[p];
    for (int i = 0; i < NODES; i++)
        if (id[i] == tmp)
            id[i] = id[q];
}

void online_connectivity(FILE *in, int id[])
{
    int p, q;
    while (fscanf(in, "%d %d", &p, &q) == 2)
    {
        printf("\n\n%d\t%d\t-->\t", p, q);

        if (id[p] != id[q]) // quick find
            slow_union(id, p, q);

        for (int i = 0; i < NODES; i++)
            printf(" %d", id[i]);
    }
}