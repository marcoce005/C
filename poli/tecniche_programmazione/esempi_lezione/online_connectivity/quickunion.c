#include <stdio.h>

#define NODES 10
#define FILE_PATH "./input.txt"

void online_connectivity(FILE *in, int id[]);
int slow_find(int id[], int v); // return the master of the node

int main(void)
{
    FILE *in;
    int id[NODES];

    for (int i = 0; i < NODES; i++) // init set [the master of the node at start is it self]
        id[i] = i;

    in = fopen(FILE_PATH, "r");

    online_connectivity(in, id);

    fclose(in);

    return 0;
}

int slow_find(int id[], int v)
{
    int i;
    for (i = v; id[i] != i; i = id[i])
        ;
    return i;
}

void online_connectivity(FILE *in, int id[])
{
    int p, q, master_p, master_q;
    while (fscanf(in, "%d %d", &p, &q) == 2)
    {
        printf("\n\n%d\t%d\t-->\t", p, q);

        master_p = slow_find(id, p);
        master_q = slow_find(id, q);

        if (master_p != master_q)
            id[master_p] = master_q; // quick union

        for (int i = 0; i < NODES; i++)
            printf(" %d", id[i]);
    }
}